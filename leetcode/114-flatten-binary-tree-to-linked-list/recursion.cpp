#include "solution.h"
#include <stack>
using namespace std;
class Solution {
public:
  TreeNode* helper(TreeNode *root) {
    if(!root)
      return;
    root -> right = 
    root -> left = nullptr;
  }
  void flatten(TreeNode* root) {
    TreeNode preHead, *cur = &preHead;
    stack<TreeNode *> st;
    st.push(root);
    while(st.size()) {
      auto node = st.top();
      st.pop();
      if(!node)
        continue;
      // visit
      cur = cur -> right = node;
      st.push(node -> right);
      st.push(node -> left);
      node -> left = nullptr;
    }
    cur -> right = nullptr;
  }
};