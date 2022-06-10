#include "solution.h"
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if(!root)
      return {};
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    q.push(root);
    for(int level = 0; q.size(); ++level) {
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
      if(level & 1)
        reverse(ans.back().begin(), ans.back().end());
    }
    return ans;
  }
};