#include "solution.h"
class Solution {
public:
  // reverse range [head, tail)
  ListNode* reverse(ListNode *head, ListNode *tail) {
    ListNode *prev = nullptr, *cur = head;
    while(cur != tail) {
      auto next = cur -> next;
      cur -> next = prev;
      prev = cur;
      cur = next;
    }
    return prev;
  }
  ListNode* reverseKGroup(ListNode* head, int k) {
    if(!head)
      return nullptr;
    ListNode *tail = head;
    for(int i = 0; i < k; ++i) {
      if(!tail)
        return head;
      tail = tail -> next;
    }
    ListNode *newHead = reverse(head, tail);
    head -> next = reverseKGroup(tail, k);
    return newHead;
  }
};