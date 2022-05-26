#include <iostream>
#include <string>
using namespace std;
int brute_force1(string &s1, string &s2) {
  int n1 = s1.size(), n2 = s2.size();
  for(int i1 = 0; i1 < n1; ++i1) {
    int i2 = 0;
    while(i2 < n2 && s1[i1 + i2] == s2[i2])
      ++i2;
    if(i2 == n2)
      return i1;
  }
  return -1;
}

int brute_force(string &s1, string &s2) {
  int i1 = 0, i2 = 0, n1 = s1.size(), n2 = s2.size();
  while(i1 < n1 && i2 < n2) {
    if(s1[i1] == s2[i2]) {
      ++i1;
      ++i2;
    } else {
      i1 = i1 - i2 + 1;
      i2 = 0;
    }
  }
  return i2 == n2 ? i1 - i2 : -1;
}