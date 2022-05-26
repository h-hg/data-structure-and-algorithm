#include "solution.h"
class Solution {
public:
  ListNode* helper(ListNode *prev, ListNode *cur) {
    if(!cur)
      return prev;
    auto next = cur -> next;
    // reverse
    cur -> next = prev;
    // handle the next node 
    return helper(cur, next);
  }
  ListNode* reverseList(ListNode* head) {
    return helper(nullptr, head);
  }
};