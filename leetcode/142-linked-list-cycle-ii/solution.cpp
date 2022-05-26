#include "solution.h"
class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    if(!head)
      return nullptr;
    auto fast = head, slow = head;
    while(fast && (fast = fast -> next)) {
      fast = fast -> next;
      slow = slow -> next;
      if(fast == slow)
        break;
    }
    if(!fast)
      return nullptr;
    slow = head;
    while(slow != fast) {
      slow = slow -> next;
      fast = fast -> next;
    }
    return fast;
  }
};