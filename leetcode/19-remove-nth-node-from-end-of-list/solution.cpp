#include "solution.h"
class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode preHead(0, head), *slow = &preHead, *fast = &preHead;
    for(n += 1; n--;fast = fast -> next); // take (n+1) steps forward
    while(fast) {
      fast = fast -> next;
      slow = slow -> next;
    }
    slow -> next = slow -> next -> next;
    return preHead.next;
  }
};