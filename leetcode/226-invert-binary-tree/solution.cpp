#include "solution.h"
class Solution {
public:
  TreeNode* invertTree(TreeNode* root) {
    if(!root)
      return nullptr;
    auto l = invertTree(root -> left),
         r = invertTree(root -> right);
    root -> left = r;
    root -> right = l;
    return root;
  }
};