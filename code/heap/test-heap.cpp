#include "heap.hpp"
#include <iostream>
#include <functional>
using namespace std;

template <typename T, typename Compare>
class Tester: public Heap<T, Compare> {
public:
  Tester(){}
  Tester(vector<T> &vec):Heap<T, Compare>(vec){}
  void print() const {
    for(auto &v: Heap<T, Compare>::arr)
      cout << v << ' ';
    cout << endl;
  }
};
int main() {
  vector<int> arr = {7, 10, 4, 3, 9, 12, 15, 8, 16, 6};
  less_equal<int> cmp;
  Tester<int, less_equal<int>> h(arr);
  h.print();
  //h.pop();
  //h.print();
  h.insert(5);
  h.print();
  return 0;
}