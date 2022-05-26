#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
  string reverseWords(string s) {
    // reduce space
    auto r = unique(s.begin(), s.end(), [](char slow, char fast) {
      return slow == fast && fast == ' ';
    });
    // trim
    auto l = s.begin();
    if(*l == ' ')
      ++l;
    if(*prev(r) == ' ')
      --r;
    // resize
    int n = distance(l ,r);
    for(auto iter = s.begin(); l != r; ) {
      *iter++ = *l++;
    }
    s.resize(n);
    // reverse all
    reverse(s.begin(), s.end());
    // find and reverese each word in s
    for(auto st = s.begin(); st != s.end(); ) {
      auto ed = find(st, s.end(), ' ');
      reverse(st, ed);
      st = ed == s.end() ? ed : next(ed);
    }
    return s;
  }
};