#include "solution.h"
class Solution {
public:
  ListNode* deleteDuplicates(ListNode* head) {
    if(!head)
      return nullptr;
    auto slow = head, fast = head -> next;
    while(fast) {
      if(fast -> val != slow -> val) {
        slow = slow -> next;
        slow -> val = fast -> val;
      }
      fast = fast -> next;
    }
    // disconnect
    slow -> next = nullptr;
    return head;
  }
};