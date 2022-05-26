#include "solution.h"
class Solution {
public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(!list1)
      return list2;
    else if(!list2)
      return list1;
    ListNode head, *cur = &head;
    while(list1 && list2) {
      ListNode* &tmp = list1 -> val < list2 -> val ? list1 : list2;
      cur = cur -> next = tmp;
      tmp = tmp -> next;
    }
    cur -> next = list1 ? list1 : list2;
    return head.next;
  }
};
