#ifndef _HEAP_H
#define _HEAP_H
#include <algorithm>
#include <vector>

template <typename T, typename Compare>
class Heap {
public:
  Heap(){}
  Heap(std::vector<T> const &vec): arr(vec) {
    build(arr, cmp);
  }
  void pop() {
    std::swap(arr.front(), arr.back());
    arr.pop_back();
    if(arr.size())
      siftDown(arr, 0, cmp);
  }
  T top() {
    return arr[0];
  }
  void insert(T const &val) {
    arr.push_back(val);
    siftUp(arr, arr.size() - 1, cmp);
  }
protected:
  std::vector<T> arr;
  Compare cmp;
  static void siftDown(std::vector<T> &arr, int x, Compare &cmp) {
    int n = arr.size();
    while(!(n/2 <= x && x < n)) /* judge whether x is a leaf*/{
      //get the max/min child
      int lc = x * 2 + 1, rc = lc + 1; //lc is left child, lr is right child
      if(rc < n && cmp(arr[rc], arr[lc]))
        lc = rc;
      //compare with parent node
      if(cmp(arr[x], arr[lc]))//meet the condition
        break;
      //sift down
      std::swap(arr[x], arr[lc]);
      x = lc;
    }
  }
  static void build(std::vector<T> &arr, Compare &cmp) {
    for(int x = arr.size() / 2 - 1; x >= 0; --x)
      siftDown(arr, x, cmp);
  }
  static void siftUp(std::vector<T> &arr, int x, Compare &cmp) {
    while(x > 0) {
      int p = (x & 1) ? x / 2 : (x - 1) / 2;
      if(cmp(arr[p], arr[x]))
        break;
      std::swap(arr[p], arr[x]);
      x = p;
    }
  }
};
#endif