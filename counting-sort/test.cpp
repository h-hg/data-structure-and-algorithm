#include <iostream>
#include "courting-sort.cpp"
int main() {
  using namespace std;
  vector<int> v = {3, 5, 10, 8, 3, 4, 5};
  for(auto val: counting_sort(v))
    cout << val << ' ';
  cout << endl;
  return 0;
}