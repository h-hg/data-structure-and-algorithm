#include "solution.h"
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> ans;
  void helper(TreeNode *root) {
    if(!root)
      return;
    ans.push_back(root -> val);
    helper(root -> left);
    helper(root -> right);
  }
  vector<int> preorderTraversal(TreeNode* root) {
    helper(root);
    return ans;
  }
};