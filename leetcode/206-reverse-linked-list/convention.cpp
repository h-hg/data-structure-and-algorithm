#include "solution.h"

class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    if(!head)
      return head;
    ListNode *prev = nullptr, *cur = head;
    while(cur) {
      auto next = cur -> next;
      // reverse
      cur -> next = prev;
      // update
      prev = cur;
      cur = next;
    }
    return prev;
  }
};