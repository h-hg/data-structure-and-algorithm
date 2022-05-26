#include "solution.h"
class Solution {
public:
  // whether has k nodes after head
  bool hasKNodes(ListNode *head, int k) {
    while(head && k--)
      head = head -> next;
    return head;
  }
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode preHead(0, head), *prevLeft = &preHead;
    while(hasKNodes(prevLeft, k)) {
      auto cur = prevLeft -> next;
      // reverse range [cur, cur + k)
      for(int i = 1; i < k; ++i) {
        // remove
        auto remove = cur -> next;
        cur -> next = remove -> next;
        // insert
        remove -> next = prevLeft -> next;
        prevLeft -> next = remove;
      }
      // update
      prevLeft = cur;
    }
    return preHead.next;
  }
};