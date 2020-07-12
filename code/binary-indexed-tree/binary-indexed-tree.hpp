#ifndef _BINARY_INDEXED_TREE_H
#define _BINARY_INDEXED_TREE_H
#include <algorithm>
#include <vector>
#include <iostream>
template <typename T>
class BIT {
public:
  BIT(int n): c(n, 0) {}
  BIT(std::vector<T> const &a): BIT(a.size()) {
    c[0] = a[0];
    for(int i = 1; i < a.size(); ++i)
      update(i, a[i]);
  }
  void update(int idx, T const &val) {
    for(; idx < c.size(); idx += lowbit(idx))
      c[idx] += val;
  }
  T sum(int n) const {
    T ans = 0;
    for(; n > 0; n -= lowbit(n))
      ans += c[n];
    return ans + c[0];
  }
protected:
  std::vector<T> c;
  static int lowbit(int n) {
    return n - (n & (n-1));
  }
};

#endif