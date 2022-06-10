#include "solution.h"
#include <queue>
using namespace std;
class Solution {
public:
  int x, y;
  TreeNode *xPraent, *yPrarent;

  void setParent(TreeNode* parent, TreeNode *child) {
    if(child -> val == x)
      xPraent = parent;
    else if(child -> val == y)
      yPrarent = parent;
  }
  bool isCousins(TreeNode* root, int x, int y) {
    // init
    this -> x = x;
    this -> y = y;
    // bfs
    queue<TreeNode *> q;
    q.push(root);
    int flag = 0; // number of x/y
    while(q.size()) {
      for(int i = 0, n = q.size(); i < n; ++i) {
        auto node = q.front();
        q.pop();
        if(node -> val == x || node -> val == y)
          ++flag;

        if(auto l = node -> left; l) {
          setParent(node, l);
          q.push(l);
        }
        if(auto r = node -> right; r) {
          setParent(node, r);
          q.push(r);
        }
      }
      if(flag == 1)
        return false;
      else if(flag == 2)
        return xPraent != yPrarent;
    }
    return false;
  }
};