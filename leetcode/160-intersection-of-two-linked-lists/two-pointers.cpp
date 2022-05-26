#include "solution.h"
#include <algorithm>
using namespace std;
class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(headA == nullptr || headB == nullptr)
      return nullptr;
    int nA = 1, nB = 1;// length of list
    //compute the length of list
    ListNode *tailA = headA, *tailB = headB;
    while(tailA -> next) {
      tailA = tailA -> next;
      ++nA;
    }
    while(tailB -> next) {
      tailB = tailB -> next;
      ++nB;
    }
    //judge whether they intersect
    if(tailA != tailB)
      return nullptr;
    // calculate the length difference between the two
    int n; // n = abs(nA - nB)
    if(nA < nB) {
      n = nB - nA;
      swap(headA, headB);
    } else
      n = nA - nB;
    //get the intersection node
    while(n--)
      headA = headA -> next;
    while(headA != headB) {
      headA = headA -> next;
      headB = headB -> next;
    }
    return headA;
  }
};