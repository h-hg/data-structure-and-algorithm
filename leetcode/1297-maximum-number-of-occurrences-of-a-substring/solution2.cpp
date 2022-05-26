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
    // init the window
    while(r < minSize) {
      if(++window[s[r++]] == 1)
        ++nType;
    }
    // move window by one step
    while(r <= s.size()) {
      // update the answer
      if(nType <= maxLetters)
        ans = max(ans, ++s2cnt[s.substr(l, minSize)]);
      // move the window
      // 1. enlarge the window
      if(++window[s[r++]] == 1)
        ++nType;
      // 2. shrink the window
      if(--window[s[l++]] == 0)
        --nType;
    }
    return ans;
  }
};

int main() {
  string s = "aababcaab";
  int maxLetters = 2, minSize = 3, maxSize =  4;
  Solution sl;
  sl.maxFreq(s, maxLetters, minSize, maxSize);
  return 0;
}