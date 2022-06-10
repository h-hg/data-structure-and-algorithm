#include "solution.h"
#include <vector>
#include <deque>
using namespace std;
class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if(!root)
      return {};
    vector<vector<int>> ans;
    deque<TreeNode*> q;
    q.push_back(root);
    for(int level = 0; q.size(); ++level) {
      ans.push_back({});
      if((level & 1) == 0)
        for(int i = 0, n = q.size(); i < n; ++i) {
          auto node = q.front();
          q.pop_front();
          ans.back().push_back(node -> val);
          if(node -> left)
            q.push_back(node -> left);
          if(node -> right)
            q.push_back(node -> right);
        }
      else
        for(int i = 0, n = q.size(); i < n; ++i) {
          auto node = q.back();
          q.pop_back();
          ans.back().push_back(node -> val);
          if(node -> right)
            q.push_front(node -> right);
          if(node -> left)
            q.push_front(node -> left);
        }
    }
    return ans;
  }
};