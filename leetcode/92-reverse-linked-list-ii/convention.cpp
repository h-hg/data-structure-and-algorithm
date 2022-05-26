#include "solution.h"
#include <vector>
using namespace std;
class Solution {
public:
  ListNode *reverse(ListNode *head) {
    if(!head)
      return nullptr;
    ListNode *prev = nullptr, *cur = head;
    while(cur) {
      auto next = cur -> next;
      // reverse
      cur -> next = prev;
      // update
      prev = cur;
      cur = next;
    }
    return prev;
  }
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode prevHead(0, head);
    // find the node before left
    ListNode *prevLeft = &prevHead;
    for(int i = 1; i < left; ++i)
      prevLeft = prevLeft -> next;
    // find the node after right
    ListNode *pLeft = prevLeft -> next,
             *pRight = pLeft;
    for(int i = 0; i < right - left; ++i)
      pRight = pRight -> next;
    ListNode *nextRight = pRight -> next;
    // split the list
    pRight -> next = nullptr;
    // reverse
    reverse(pLeft);
    // merge
    prevLeft -> next = pRight;
    pLeft -> next = nextRight;
    return prevHead.next;
  }
};