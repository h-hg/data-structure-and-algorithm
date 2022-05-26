#include "solution.h"

class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    ListNode *pNext;
    if(!head || !(pNext = head -> next))
      return head;
    auto newHead = reverseList(pNext);
    pNext -> next = head;
    head -> next = nullptr;
    return newHead;
  }
};