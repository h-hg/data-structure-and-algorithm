#include <algorithm>
#include <vector>
#include <sstream>
#include <string>
using namespace std;
class Solution {
public:
  string reorderSpaces(string text) {
    // split text and count
    vector<string> words;
    stringstream ss(text);
    for(string word; ss >> word; words.emplace_back(move(word)));
    // calculate the space
    int spaceNum = count(text.begin(), text.end(), ' ');
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