#include "solution.h"
class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode node, *cur = &node;
    int sum = 0;
    while(l1 || l2 || sum) {
      if(l1) {
        sum += l1 -> val;
        l1 = l1 -> next;
      }
      if(l2) {
        sum += l2 -> val;
        l2 = l2 -> next;
      }
      cur = cur -> next = new ListNode(sum % 10);
      sum /= 10;
    }
    return node.next;
  }
};