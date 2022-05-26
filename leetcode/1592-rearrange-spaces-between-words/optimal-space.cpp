#include <vector>
#include <string>
using namespace std;
class Solution {
public:
  string reorderSpaces(string text) {
    // split text and count
    int spaceNum = 0, wordNum = 0;
    bool isSpace = true; // whether last char is space
    for(auto c : text)
      if(c == ' ') {
        ++spaceNum;
        isSpace = true;
      } else {
        if(isSpace)
          ++wordNum;
        isSpace = false;
      }
    // calculate the space
    int evenSpace = wordNum == 1 ? 0 : spaceNum / (wordNum - 1);
    // splicing
    string ans;
    ans.reserve(text.size()); // allocate space
    int i = 0;
    while(text[i] == ' ') // skip lead space
      ++i;
    while(i != text.size()) {
      if(text[i] != ' ') {
        ans.push_back(text[i]);
        ++i;
      } else {
        ans.append(evenSpace, ' ');
        while(text[i] == ' ' && i != text.size())
          ++i;
      }
    }
    if(ans.size() < text.size())
      ans.append(text.size() - ans.size(), ' ');
    else
      ans.resize(text.size());
    return ans;
  }
};