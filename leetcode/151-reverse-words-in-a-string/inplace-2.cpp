#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
  string reverseWords(string s) {
    // reduce space
    auto l = find_if(s.begin(), s.end(), [](char c) {
      return c != ' ';
    });
    int n = distance(l, s.end());
    for(auto iter = s.begin(); iter != s.end(); ) {
      *iter++ = *l++;
    }
    s.resize(n);

    auto r = unique(s.begin(), s.end(), [](char slow, char fast) {
      return slow == fast && fast == ' ';
    });
    // trim
    if(*prev(r) == ' ')
      --r;
    // resize
    s.resize(distance(s.begin() ,r));
    // reverse all
    reverse(s.begin(), s.end());
    // find and reverese each word in s
    for(auto st = s.begin(); st != s.end(); ) {
      auto ed = find(st, s.end(), ' ');
      reverse(st, ed);
      st = ed == s.end()? ed : next(ed);
    }
    return s;
  }
};