#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> ans, hist(128, 0);
    for(auto c : p)
      ++hist[c];
    int l = 0, r = 0, nRemain = p.size();
    while(r < s.size()) {
      // enlarge window
      if(--hist[s[r++]] >= 0)
        --nRemain;
      // shrink window
      if(r - l == p.size()) {
        if(nRemain == 0)
          ans.push_back(l);
        if(++hist[s[l++]] > 0)
          ++nRemain;
      }
    }
    return ans;
  }
};