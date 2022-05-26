#include "solution.h"

class Solution {
public:
  int left_;
  int right_;
  void helper(ListNode *prev, ListNode *cur, int pos) {
    if(pos == right_ + 1) {
      if(cur)
        cur -> next = prev;
    }
    else if(pos < left_) {
      helper(cur, cur -> next, pos + 1);
    } else {
      auto next = cur -> next;

    }
    
  }
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    left_ = left;
    right_ = right;
  }
};