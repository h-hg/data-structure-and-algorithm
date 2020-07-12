#include "select-sort.hpp"
#include <iostream>
#include <functional>
using namespace std;
int main() {
  int a[] = {4, 2, 9, 4, 0, -199, 123};
  const int n = sizeof(a)/sizeof(a[0]);
  selectSort(a, a + n, std::less<int>());
  for(auto val: a)
    cout << val << ' ';
  cout << endl;
  return 0;
}