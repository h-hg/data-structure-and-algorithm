#ifndef _UNION_FIND_SET_BASE_H
#define _UNION_FIND_SET_BASE_H
#include <vector>
using namespace std;

//union find set base
class UFSB {
protected:
  vector<int> father;
  int findRoot(int x);
public:
  UFSB(int n);
  bool isSameSet(int a, int b);
  void merge(int a, int b);
};
UFSB::UFSB(int n): father(n) {
  for(int i = 0; i < n; ++i)
    father[i] = i;
}

bool UFSB::isSameSet(int a, int b) {
  return findRoot(a) == findRoot(b);
}

void UFSB::merge(int a, int b) {
  int rootA = findRoot(a),
      rootB = findRoot(b);
  if(rootA != rootB)
    father[rootB] = rootA;
}

int UFSB::findRoot(int x) {
  int root = x;
  // the old findRoot
  while(root != father[root])
    root = father[root];
  //The second pass: let nodes point to root
  while(x != father[x]) {
    int tmp = father[x];
    father[x] = root;
    x = tmp;
  }
  return root;
}

#endif