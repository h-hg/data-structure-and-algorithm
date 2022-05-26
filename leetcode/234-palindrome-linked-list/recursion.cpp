#include "solution.h"

class Solution {
  ListNode* frontPointer;
public:
  bool recursivelyCheck(ListNode* currentNode) {
    if (currentNode) {
      if (!recursivelyCheck(currentNode -> next) || currentNode -> val != frontPointer -> val)
        return false;
      frontPointer = frontPointer -> next;
    }
    return true;
  }

  bool isPalindrome(ListNode* head) {
    frontPointer = head;
    return recursivelyCheck(head);
  }
};