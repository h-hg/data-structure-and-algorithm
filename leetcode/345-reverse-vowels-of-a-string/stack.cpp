#include <stack>
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
 public:
  string reverseVowels(string s) {
    unordered_set<char> mp;
    for (auto c : "aeiouAEIOU")
      mp.insert(c);
    string res = "";
    stack<char> st;
    for (auto c : s)
      if (mp.count(c))
        st.push(c);
    for (auto c : s)
      if (mp.count(c)) {
        res.push_back(st.top());
        st.pop();
      } else
        st.push(c);
    return res;
  }
};