#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  int lengthOfLongestSubstring(string &s) {
    int l = 0, r = 0, n = s.size(), ans = 0;
    vector<int> window(256, -1); // window[c] stands for the index of char c of tht sliding window in the string s
    while(r < n) {
      char c = s[r];
      // shrinkage
      if(window[s[l]] <= window[c])
        l = window[c] + 1;
      //update and enlarge the window
      window[c] = r;
      ++r;
      ans = max(ans, r - l);
    }
    return ans;
  }
};