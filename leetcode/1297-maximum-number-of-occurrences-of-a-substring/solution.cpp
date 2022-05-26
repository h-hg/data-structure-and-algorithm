#include <string>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
  int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
    int ans = 0;
    map<string, int> s2cnt;
    vector<int> window(128, 0); // window[c] stands for the number of char c
    int l = 0, r = 0, nType = 0;
    while(r < s.size()) {
      // enlarge the window
      if(++window[s[r++]] == 1)
        ++nType;
      // shrink the window
      while(nType > maxLetters || r - l > minSize) {
        if(--window[s[l++]] == 0)
          --nType;
      }
      // update the answer
      if(r - l == minSize)
        ans = max(ans, ++s2cnt[s.substr(l, minSize)]);
    }
    return ans;
  }
};
