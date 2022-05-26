#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  int lengthOfLongestSubstring(string &s) {
    int l = 0, r = 0, n = s.size(), ans = 0;
    vector<int> window(256, 0); // window[c] stands for the number of char c in the window
    while(r < n) {
      // enlarge the window
      char c = s[r];
      ++window[c];
      ++r;
      // shrinkage
      while(window[c] != 1)
        --window[s[l++]];
      ans = max(ans, r - l);
    }
    return ans;
  }
};