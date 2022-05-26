#include <vector>
#include <string>
using namespace std;
class Solution {
public:
  vector<int> mp;
  // return whether s1 <= s2
  bool le(string const &s1, string const &s2) {
    for(int i = 0, n = min(s1.size(), s2.size()); i < n; ++i) {
      int diff = mp[s1[i]] - mp[s2[i]];
      if(diff < 0)
        return true;
      else if(diff > 0)
        return false;
    }
    return s1.size() <= s2.size();
  }
  bool isAlienSorted(vector<string>& words, string order) {
    mp = vector<int>(128, 0);
    // map char to rank
    for(int i = 0; i < order.size(); ++i)
      mp[order[i]] = i + 1;
    // comparison
    for(int i = 1; i < words.size(); ++i)
      if(!le(words[i - 1], words[i]))
        return false;
    return true;
  }
};