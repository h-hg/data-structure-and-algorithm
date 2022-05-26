#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  string longestPalindrome(string &s) {
    int l = 0, maxLen = 1;
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
    // init the table
    for(int i = 0; i < s.size(); ++i)
      dp[i][i] = true;
    for(int i = 1; i < s.size(); ++i)
      dp[i][i - 1] = true;
    
    for(int level = 1; level < s.size(); ++level)
      for(int i = 0; i + level < s.size(); ++i) {
        int j = i + level;
        if(dp[i + 1][j - 1] && s[i] == s[j]) {
          dp[i][j] = true;
          // update
          if(level + 1 > maxLen) {
            maxLen = level + 1;
            l = i;
          }
        }
      }
    return s.substr(l, maxLen);
  }
};