#include "solution.h"
#include <queue>
using namespace std;
class Solution {
public:
  Node* connect(Node* root) {
    auto cur = root;
    while(cur) {
      auto nextLevelFront = cur -> left;
      // process each level
      while(cur) {
        auto lc = cur -> left, rc = cur -> right;
        // judge whether cur has children
        if(lc) {
          lc -> next = rc;
          rc -> next = cur -> next ? cur -> next -> left : nullptr;
        }
        cur = cur -> next;
      }
      cur = nextLevelFront;
    }
    return root;
  }
};