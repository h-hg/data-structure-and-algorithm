#ifndef _HEAP_SORT_H
#define _HEAP_SORT_H
#include <algorithm>
#include <vector>

template <typename T, typename Compare>
void siftDown(std::vector<T> &arr, int n, int x, Compare &cmp) {
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

template<typename T, typename Compare>
void build(std::vector<T> &arr, Compare &cmp) {
  int n = arr.size();
  for(int x = n / 2 - 1; x >= 0; --x)
    siftDown<T, Compare>(arr, n, x,cmp);
}

template<typename T, typename Compare>
void rmFirst(std::vector<T> &arr, int n, Compare &cmp) {
  --n;
  std::swap(arr.front(), arr[n]);
  siftDown<T, Compare>(arr, n, 0,cmp);
}

template<typename T, typename Compare>
std::vector<T> heapSort(std::vector<T> &arr) {
  Compare cmp;
  build(arr, cmp);
  for(int n = arr.size(); n > 1;--n) /* (n-1) times */
    rmFirst(arr, n, cmp);
  reverse(arr.begin(), arr.end());
  return arr;
}

#endif