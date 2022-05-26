#include <vector>
#include <string>
using namespace std;
class Solution {
public:
  bool isAlienSorted(vector<string>& words, string order) {
    vector<int> mp(128, 0);
    // map alien char to our char
    for(int i = 0; i < order.size(); ++i)
      mp[order[i]] = i + 'a';
    // conversion
    for(auto &word : words)
      for(auto &c : word)
        c = mp[c];
    // comparison
    for(int i = 1; i < words.size(); ++i)
      if(words[i - 1] > words[i])
        return false;
    return true;
  }
};