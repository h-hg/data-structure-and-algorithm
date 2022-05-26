import os
import sys
import requests
import json
from bs4 import BeautifulSoup

class Crawler:
    def __init__(self):
        self.session = requests.Session()
        self.userAgent = "Mozilla/5.0 (X11; Linux x86_64; rv:81.0) Gecko/20100101 Firefox/81.0"

    """
    @desc Return the problem list
    """
    def getProblemList(self):
        url = "https://leetcode.com/api/problems/all/"
        headers = {
            "User-Agent": self.userAgent,
            "Connection": "keep-alive",
            "Content-Type": "application/json"
        }
        resp = self.session.get(url=url, headers=headers)
        dataJson = resp.json()
        problemList = [None] * (len(dataJson["stat_status_pairs"]) + 1)

        for x in dataJson["stat_status_pairs"]:
            problemId = int(x["stat"]["frontend_question_id"])
            problemList[problemId] = {
                "slugTitle": x["stat"]["question__title_slug"],
                "title": x["stat"]["question__title"],
                "free": not x["paid_only"]
            }
        return problemList
    def getProblemDetailById(self, problemId:int):
        slugTitle = self.getProblemList()[problemId]["slugTitle"]
        return self.getProblemDetail(slugTitle)

    def getProblemDetail(self, titleSlug:str):
        headers = {
            "User-Agent": self.userAgent,
            "Connection": "keep-alive",
            "Content-Type": "application/json",
            "Referer": "https://leetcode.com/problems/" + titleSlug
        }
        url = "https://leetcode.com/graphql"
        params = {
            "operationName": "questionData",
            "variables": {
                "titleSlug": titleSlug
            },
            "query": "query questionData($titleSlug: String!) {\n  question(titleSlug: $titleSlug) {\n    questionId\n    questionFrontendId\n    boundTopicId\n    title\n    titleSlug\n    content\n    translatedTitle\n    translatedContent\n    isPaidOnly\n    difficulty\n    likes\n    dislikes\n    isLiked\n    similarQuestions\n    contributors {\n      username\n      profileUrl\n      avatarUrl\n      __typename\n    }\n    topicTags {\n      name\n      slug\n      translatedName\n      __typename\n    }\n    companyTagStats\n    codeSnippets {\n      lang\n      langSlug\n      code\n      __typename\n    }\n    stats\n    hints\n    solution {\n      id\n      canSeeDetail\n      paidOnly\n      hasVideoSolution\n      __typename\n    }\n    status\n    sampleTestCase\n    metaData\n    judgerAvailable\n    judgeType\n    mysqlSchemas\n    enableRunCode\n    enableTestMode\n    enableDebugger\n    envInfo\n    libraryUrl\n    adminUrl\n    __typename\n  }\n}\n"
        }        
        resp = self.session.post(url=url, data=json.dumps(params).encode("utf8"), headers=headers)
        dataJson = resp.json()
        
        return {
            "id": dataJson["data"]["question"]["questionFrontendId"],
            "title": dataJson["data"]["question"]["title"],
            "titleSlug": titleSlug,
            "difficulty": dataJson["data"]["question"]["difficulty"],
            "tags": [topicTag["name"] for topicTag in dataJson["data"]["question"]["topicTags"]],
            "free": not dataJson["data"]["question"]["isPaidOnly"],
            "content": dataJson["data"]["question"]["content"],
            "hints": dataJson["data"]["question"]["hints"],
            "images": self.getImgs(dataJson["data"]["question"]["content"]),
            "codeSnippets": { pair["lang"] : pair for pair in dataJson["data"]["question"]["codeSnippets"] }
        }
    
    def getImgs(self, htmlCode):
        soup = BeautifulSoup(htmlCode, 'html.parser')
        imgs = []
        for img in soup.find_all("img"):
            url = img.get("src")
            imgs.append({
                "src": url,
                "filename": url[url.rfind("/") + 1 : len(url)],
                "data": requests.get(url).content
            })
        return imgs


class Leetcode:
    def __init__(self):
        self.scriptPath = sys.path[0]
        self.workplace = os.path.join(self.scriptPath, "..")
        self.leetcodePath = os.path.join(self.workplace, "leetcode")
        self.crawler = Crawler()

    def readfile(self, path):
        with open(path, "r", encoding="utf-8") as fr:
            return fr.read()
        return None

    def getProblemRelativePath(self, info):
        return os.path.join("leetcode", info["id"] + "-" + info["titleSlug"])

    def getProblemAbsolutePath(self, info):
        return os.path.join(self.workplace, self.getProblemRelativePath(info))

    def createIndexMd(self, info):
        dirPath = self.getProblemAbsolutePath(info)
        if(not os.path.exists(dirPath)):
            os.makedirs(dirPath)
        with open(os.path.join(dirPath, "index.md"), "w", encoding="utf-8") as fw:
            template = self.readfile(os.path.join(self.scriptPath, "template/leetcode.md"))
            fw.write(template.format(
                title=info["title"],
                url_en="https://leetcode.com/problems/" + info["titleSlug"],
                url_cn="https://leetcode.cn/problems/" + info["titleSlug"],
            ))

    def createDescMD(self, info):
        dirPath = self.getProblemAbsolutePath(info)
        # write images and modify desc.md
        for img in info["images"]:
            # There are something wrong with docsify embed files with images of html
            # see https://github.com/docsifyjs/docsify/issues/865
            info["content"] = info["content"].replace(img["src"], self.getProblemRelativePath(info) + '/' + img["filename"])
            with open(os.path.join(dirPath, img["filename"]), "wb") as f:
                f.write(img["data"])
        # write desc.md
        with open(os.path.join(dirPath, "desc.md"), "w", encoding="utf-8") as f:
            f.write(info["content"])

    def createSolutionFile(self, info):
        dirPath = self.getProblemAbsolutePath(info)
        cppCode = info["codeSnippets"]["C++"]["code"]
        # preprocess code
        if cppCode.startswith('class '):
            hFile = None
            cppFile = cppCode
        else:
            pos = cppCode.find('class ')
            hFile = cppCode[:pos]
            hFile = hFile.splitlines()
            # add header
            hFile[0] = "// solution.h"
            # remove comment block
            hFile.pop(-1)
            hFile[1] = hFile[1].replace(" * ", "// ")
            for i in range(2, len(hFile)):
                hFile[i] = hFile[i][len(" * "):].replace(" " * 4, " " * 2)
            hFile = "\n".join(hFile)
            cppFile = '#include "solution.h"\n' + cppCode[pos:]
        # 4 space -> 2 space
        cppFile = cppFile.splitlines()
        for i in range(len(cppFile)):
            cppFile[i] = cppFile[i].replace(" " * 4, " " * 2)
        cppFile = "\n".join(cppFile)
        
        if hFile:
            with open(os.path.join(dirPath, "solution.h"), "w", encoding="utf-8") as fw:
                fw.write(hFile)
            with open(os.path.join(dirPath, "index.md"), "a+", encoding="utf-8") as fw:
                fw.write("[](solution.h ':include :type=code cpp')\n\n")

        with open(os.path.join(dirPath, "solution.cpp"), "w", encoding="utf-8") as fw:
            fw.write(cppFile)
        with open(os.path.join(dirPath, "index.md"), "a+", encoding="utf-8") as fw:
            fw.write("[](solution.cpp ':include :type=code cpp')\n")

    def updateTag(self, info):
        filePath = os.path.join(self.workplace, "tag/leetcode.md")
        # read the tags
        tags = {
            int(line[1 : line.find("|", 1)]) : line
                for line in self.readfile(filePath).splitlines(True)[2:]
        }
        # symbol for free
        free = ":o:" if info["free"] else ":x:"
        # set tag
        tags[int(info["id"])] = f'|{info["id"]}|{info["title"]}|{info["difficulty"]}|{", ".join(["`" + tag + "`" for tag in info["tags"]])}|{free}|\n'
        # sort the tag
        tags = [tags[key] for key in sorted(tags.keys())]
        # write tag
        with open(filePath, "w", encoding="utf-8") as f:
            f.write("|ID|Problem|Difficulty|Tag|Free|\n|:-:|:-:|:-:|:-:|:-:|\n")
            f.writelines(tags)

    def updateSidebar(self, info):
        # read
        lines = self.readfile(os.path.join(self.workplace, "SUMMARY.md")).splitlines(True)
        beginIdx = lines.index("- Leetcode\n") + 1
        endIdx = None
        for i in range(beginIdx, len(lines)):
            if not lines[i].startswith(" " * 4):
                endIdx = i
                break
        items = {int(line[line.find("[") + 1 : line.find(".")]) : line for line in lines[beginIdx : endIdx]}
        # insert current item
        items[int(info["id"])] = f'    - [{info["id"]}. {info["title"]}]({self.getProblemRelativePath(info)}/index.md)\n'
        # sort and update
        items = [items[key] for key in sorted(items.keys())]
        lines[beginIdx : endIdx] = items
        # write
        with open(os.path.join(self.workplace, "SUMMARY.md"), "w", encoding="utf-8") as f:
            f.writelines(lines)

    def new(self, titleSlug):
        # get information
        info = self.crawler.getProblemDetail(titleSlug)
        # create index.md
        self.createIndexMd(info)
        # desc.md and image
        self.createDescMD(info)
        # solution
        self.createSolutionFile(info)
        # update tag
        self.updateTag(info)
        # update sidebar
        self.updateSidebar(info)

def main():
    leetcode = Leetcode()
    import argparse
    parse = argparse.ArgumentParser()
    parse.add_argument('title')
    args = parse.parse_args()
    leetcode.new(args.title)

if __name__ == "__main__":
    main()