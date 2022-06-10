#include <string>
using namespace std;
class Solution {
public:
  string removeOuterParentheses(string s) {
    string ans;
    int cnt = 0;
    for(auto c : s) {
      if(c == ')')
        --cnt;
      if(cnt)
        ans.push_back(c);
      if(c == '(')
        ++cnt;
    }
    return ans;
  }
};