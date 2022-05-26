#include <vector>
#include <string>
using namespace std;
// 错误的
class Solution {
public:
  inline int hash(char c) {
    return c - 'a';
  }
  inline char unhash(int h) {
    return 'a' + h;
  }
  string removeDuplicateLetters(string s) {
    vector<bool> m(26,false);
    // record
    for(auto c : s)
      m[hash(c)] = true;
    
    string ans;
    for(int i = 0; i < 26; ++i)
      if(m[i])
        ans.push_back(unhash(i));
    return ans;
  }
};

/*
 * 应该要从 dp 角度思考
 * 考虑 s[i] 和 s[i+1]
 * c = s[i + 1]
 * 
 */