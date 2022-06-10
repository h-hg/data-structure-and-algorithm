def readfile(path):
    with open(path, 'r', encoding='utf-8') as fr:
        return fr.read()
    return None

def writefile(path, content):
    with open(path, 'w', encoding='utf-8') as fw:
        fw.write(content)