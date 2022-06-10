#include <stack>
#include <string>
using namespace std;
class Solution {
 public:
  string removeOuterParentheses(string s) {
    string ans;
    stack<char> st;
    for (auto c : s) {
      if (c == '(') {
        if(st.size())
          ans.push_back('(');
        st.push('(');
      } else { // c == ')'
        st.pop();
        if (st.size())
          ans.push_back(')');
      }
    }
    return ans;
  }
};
