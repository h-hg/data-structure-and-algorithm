#include "solution.h"

class Solution {
public:
  ListNode* reverse(ListNode *head) {
    ListNode *prev = nullptr, *cur = head;
    while(cur) {
      auto next = cur -> next;
      cur -> next = prev;
      prev = cur;
      cur = next;
    }
    return prev;
  }
  ListNode* findMiddle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while(fast && (fast = fast -> next)) {
      fast = fast -> next;
      slow = slow -> next;
    }
    return slow;
  }
  bool isPalindrome(ListNode* head) {
    auto middle = findMiddle(head);
    auto l = head, r = reverse(middle);
    while(r) {
      if(l -> val != r -> val)
        return false;
      l = l -> next;
      r = r -> next;
    }
    return true;
  }
};