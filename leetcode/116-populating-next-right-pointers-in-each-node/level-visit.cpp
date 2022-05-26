#include "solution.h"
#include <queue>
using namespace std;
class Solution {
public:
  Node* connect(Node* root) {
    if(!root)
      return nullptr;
    queue<Node*> q;
    q.push(root);
    while(q.size()) {
      // process each level
      for(int i = 1, n = q.size(); i <= n; ++i) {
        auto node = q.front();
        q.pop();
        if(i != n)
          node -> next = q.front();
        if(node -> left)
          q.push(node -> left);
        if(node -> right)
          q.push(node -> right);
      }
    }
    return root;
  }
};