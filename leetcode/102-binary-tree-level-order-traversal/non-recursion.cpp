#include "solution.h"
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    q.push(root);
    while(q.size()) {
      ans.push_back({});
      for(int i = 0, n = q.size(); i < n; ++i) {
        auto node = q.front();
        q.pop();
        ans.back().push_back(node -> val);
        if(node -> left)
          q.push(node -> left);
        if(node -> right)
          q.push(node -> right);
      }
    }
    return ans;
  }
};