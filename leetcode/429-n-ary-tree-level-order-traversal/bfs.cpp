#include "solution.h"
#include <queue>
class Solution {
public:
  vector<vector<int>> levelOrder(Node* root) {
    if(!root)
      return {};
    vector<vector<int>> ans;
    queue<Node*> q;
    q.push(root);
    while(q.size()) {
      ans.push_back({});
      for(int i = 0, n = q.size(); i < n; ++i) {
        auto node = q.front();
        q.pop();
        ans.back().push_back(node -> val);
        for(auto child : node -> children)
          if(child)
            q.push(child);
      }
    }
    return ans;
  }
};