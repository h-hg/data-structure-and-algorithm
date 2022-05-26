#include <string>
#include <vector>
#include <unordered_map>
#include <limits>
using namespace std;
class Solution {
 public:
  int lAns = 0, nAns = numeric_limits<int>::max();
  string minWindow(string s, string t) {
    unordered_map<char, int> need;
    for (char c : t)
      need[c]++;
    // `nRemain` is the number of char in t that aren't found in window
    int l = 0, r = 0, nRemain = t.size();
    while (r < s.size()) {
      // enlarge window, c is the new char added
      char c = s[r++];
      // steps for enlarging window
      if (need.count(c) && --need[c] >= 0)
        --nRemain;
      // keep shrinking the window
      while (nRemain == 0) {
        // update the answer
        if (r - l < nAns) {
          lAns = l;
          nAns = r - l;
        }
        // shrink the window, d is the char removed
        char d = s[l++];
        // steps for shrinking the window
        if (need.count(d) &&++need[d] > 0)
          ++nRemain;
      }
    }
    return nAns == numeric_limits<int>::max() ? "" : s.substr(lAns, nAns);
  }
};