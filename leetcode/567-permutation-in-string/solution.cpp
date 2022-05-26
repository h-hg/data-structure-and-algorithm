#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    vector<int> hist(128, 0);
    for(auto c : s1)
      ++hist[c];

    int l = 0, r = 0, nRemain = s1.size();
    while(r < s2.size()) {
      // enlarge the window
      if(--hist[s2[r++]] >= 0)
        --nRemain;
      // shrink the window
      if(r - l == s1.size()) {
        // update the answer
        if(nRemain == 0)
          return true;
        if(++hist[s2[l++]] > 0)
          ++nRemain;
      }
    }
    return false;
  }
};