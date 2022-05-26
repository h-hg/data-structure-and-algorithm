#include "solution.h"
class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    ListNode prevHead(0, head);
    ListNode *prevLeft = &prevHead;
    for (int i = 1; i < left; i++)
      prevLeft = prevLeft -> next;
    ListNode *cur = prevLeft -> next;
    // reverse
    for(int i = 0; i < right - left; ++i) {
      // remove
      auto remove = cur -> next;
      cur -> next = remove -> next;
      // insert
      remove -> next = prevLeft -> next;
      prevLeft -> next = remove;
    }
    return prevHead.next;
  }
};