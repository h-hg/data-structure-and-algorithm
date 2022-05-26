#include <iostream>
#include <functional>
#include "heap-sort.hpp"

using namespace std;
int main() {
  std::vector<int> arr = {7, 10, 4, 3, 9, 12, 15, 8, 16, 6};
  std::less_equal<int> cmp;
  for(auto v: heapSort<int, less_equal<int>>(arr))
    cout << v << ' ';
  cout << endl;
  return 0;
}