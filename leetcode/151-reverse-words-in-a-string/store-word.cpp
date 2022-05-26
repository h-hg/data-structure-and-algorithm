#include <vector>
#include <sstream>
#include <string>
using namespace std;
class Solution {
public:
  string reverseWords(string s) {
    stringstream ss(s);
    vector<string> words;
    for(string word; ss >> word; words.emplace_back(move(word)));
    string ans;
    ans.reserve(s.size());
    for(auto iter = words.rbegin(); iter != words.rend(); ++iter)
      ans.append(*iter).push_back(' ');
    ans.resize(ans.size() - 1);
    return ans;
  }
};