#include "solution.h"
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
      vector<int> ans;
      stack<TreeNode *> st;
      st.push(root);
      while(st.size()) {
        auto ptr = st.top();
        st.pop();
        if(!ptr)
          continue;
        ans.push_back(ptr -> val);
        st.push(ptr -> right);
        st.push(ptr -> left);
      }
      return ans;
    }
};