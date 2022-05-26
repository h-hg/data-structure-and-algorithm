#include "solution.h"
#include <stack>
using namespace std;
class Solution {
public:
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