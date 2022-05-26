#include <limits>
#include <string>
#include <vector>
#include <unordered_map>
#include <limits>
using namespace std;
class Solution {
 public:
  int lAns = 0, nAns = numeric_limits<int>::max();
  string minWindow(string s, string t) {
    unordered_map<char, int> need, window;
    for (auto c : t)
      need[c]++;
    // `valid` is the number of char type in t that are all found in window
    int l = 0, r = 0, valid = 0;
    while (r < s.size()) {
      // enlarge window, c is the new char added
      char c = s[r++];
      // steps for enlarging window
      if (need.count(c)) {
        ++window[c];
        if (window[c] == need[c])
          ++valid;
      }
      // keep shrinking the window
      while (valid == need.size()) {
        // update the answer
        if (r - l < nAns) {
          lAns = l;
          nAns = r - l;
        }
        // shrink the window, d is the char removed
        char d = s[l++];
        // steps for shrinking the window
        if (need.count(d)) {
          if (window[d] == need[d])
            --valid;
          --window[d];
        }
      }
    }
    return nAns == numeric_limits<int>::max() ? "" : s.substr(lAns, nAns);
  }
};