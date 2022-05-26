#include <vector>
#include <string>
using namespace std;
class Solution {
public:
  string reorderSpaces(string text) {
    // split text and count
    vector<string> words;
    string word;
    int spaceNum = 0;
    for(auto c : text)
      if(c == ' ') {
        ++spaceNum;
        if(word.size()) {
          words.push_back(word);
          word.clear();
        }
      } else
        word.push_back(c);
    if(word.size())
      words.push_back(word);
    // calculate the space
    int evenSpace = words.size() == 1 ? 0 : spaceNum / (words.size() - 1);
    // splicing
    string ans;
    ans.reserve(text.size()); // allocate space
    for(auto &word : words)
      ans.append(word).append(evenSpace, ' ');
    if(ans.size() < text.size())
      ans.append(text.size() - ans.size(), ' ');
    else
      ans.resize(text.size());
    return ans;
  }
};