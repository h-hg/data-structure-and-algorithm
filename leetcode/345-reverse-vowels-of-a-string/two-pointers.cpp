#include <unordered_set>
#include <string>
using namespace std;
class Solution {
public:
  string reverseVowels(string s) {
    unordered_set<char> mp;
    for(auto c : "aeiouAEIOU")
        mp.insert(c);
    int l = -1, r = s.size();
    while(l < r) {
      while(!mp.count(s[++l]) && l < r);
      while(!mp.count(s[--r]) && l < r);
      if(l < r)
        swap(s[l], s[r]);
    }
    return s;
  }
};