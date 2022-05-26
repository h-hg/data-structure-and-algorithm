#include "solution.h"
class Solution {
public:
  ListNode* middleNode(ListNode* head) {
    ListNode *slow = head,*fast = head;
    while(fast && (fast = fast -> next)) {
      slow = slow -> next;
      fast = fast -> next;
    }
    return slow;
  }
};