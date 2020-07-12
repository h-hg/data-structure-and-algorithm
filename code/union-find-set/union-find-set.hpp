#ifndef _UNION_FIND_SET_H
#define _UNION_FIND_SET_H
#include <vector>
//union find set base
class UFSB {
protected:
  std::vector<int> father;
public:
  UFSB(const std::vector<int> &v) : father(v) {}
  UFSB(int n) : father(n) {
    for(int i = 0; i < n; ++i)
      father[i] = i;
  }
  int findRoot(int x) {
    int root = x;
    while(root != father[root]) {
      root = father[root];
    }
    //The second pass: let nodes point to root
    while(x != father[x]) {
      int tmp = father[x];
      father[x] = root;
      x = tmp;
    }
    return root;
  }
  void merge(int a, int b) {
    int rootA = findRoot(a),
        rootB = findRoot(b);
    if(rootA != rootB) {
      father[rootB] = rootA;
    }
  }
};

#endif