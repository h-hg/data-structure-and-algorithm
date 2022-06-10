#include <string>
#include <stack>
using namespace std;
class Solution {
public:
  string removeOuterParentheses(string s) {
    string ans;
    stack<pair<char, int>> st;
    for(int i = 0; i < s.size(); ++i) {
      if(s[i] == '(')
        st.push({s[i], i});
      else { // s == ')'
        auto p = st.top();
        st.pop();
        if(st.empty())
          ans += s.substr(p.second + 1, i - p.second - 1);
      }
    }
    return ans;
  }
};