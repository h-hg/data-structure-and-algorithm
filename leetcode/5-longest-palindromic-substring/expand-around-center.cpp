#include <string>
using namespace std;
class Solution {
public:
  /*
   * @desc This function return the max length of palindrome expanded from s[l] and s[r]
   * When l == r, the return value is odd number, when r == l + 1, the return value is even number
   */
  int expandAroundCenter(int l, int r, string &s) {
    while(l >= 0 && r < s.size() && s[l] == s[r]) {
      --l;
      ++r;
    }
    return r - l - 1;
  }
  string longestPalindrome(string &s) {
    int l = 0, maxLen = 0;
    for(int center = 0; center < s.size(); ++center) {
      int len = max(expandAroundCenter(center, center, s), expandAroundCenter(center, center + 1, s));
      if(maxLen < len) {
        l = center - (len - 1) / 2;
        maxLen = len;
      }
    }
    return s.substr(l, maxLen);
  }
};