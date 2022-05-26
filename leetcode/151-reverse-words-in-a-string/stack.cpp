#include <stack>
#include <sstream>
#include <string>
using namespace std;
class Solution {
public:
  string reverseWords(string s) {
    stack<string> words;
    string word;
    s.push_back(' ');
    for(auto c : s)
      if(c == ' ' && word.size()) {
        words.push(word);
        word.clear();
      } else
        word.push_back(c);
    string ans;
    while(words.size()) {
      ans.append(words.top()).push_back(' ');
      words.pop();
    }
    ans.resize(ans.size() - 1);
    return ans;
  }
};