#include "binary-indexed-tree.hpp"
#include <iostream>
using namespace std;
int sum(std::vector<int> const &v, int n) {
  int ans = 0;
  for(int i = 0; i <= n; ++i)
    ans += v[i];
  return ans;
}
void print(BIT<int> const &t, vector<int> const &v) {
  int n = v.size();
  for(int i = 0; i < n; ++i) {
    cout << t.sum(i) << "<" << sum(v, i) << "> ";
  }
  cout << endl;
}
int main() {
  vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int n = v.size();
  BIT<int> t(v);
  print(t, v);
  //update
  v[5] += 10;
  t.update(5, 10);
  print(t, v);
  return 0;
}