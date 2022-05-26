#include <limits>
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  int nAns = numeric_limits<int>::max(), lAns = 0;
  string minWindow(string &s, string &t) {
    vector<int> hist(128, 0);
    for (char c : t)
      hist[c]++;
    int nRemain = t.size();
    int l = 0, r = 0;
    while (r < s.length()) {
      // enlarge the window
      if (--hist[s[r++]] >= 0)
        --nRemain;
      // shrink the window
      while (nRemain == 0) {
        // update the answer
        if (r - l < nAns) {
          nAns = r - l;
          lAns = l;
        }
        if (++hist[s[l++]] > 0)
          ++nRemain;
      }
    }
    return nAns < numeric_limits<int>::max() ? s.substr(lAns, nAns) : "";
  }
};