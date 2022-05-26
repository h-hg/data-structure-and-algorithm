#include "solution.h"
#include <vector>
using namespace std;
class Solution {
public:
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    vector<ListNode*> v;
    // node in the front
    ListNode prevHead(0, head);
    v.push_back(&prevHead);
    // insert the nodes of list
    for(auto cur = head; cur; cur = cur -> next)
      v.push_back(cur);
    // empty node at the end
    v.push_back(nullptr);
    // reverse between
    for(int i = right; i > left; --i)
      v[i] -> next = v[i-1];
    v[left] -> next = v[right + 1];
    v[left - 1] -> next = v[right];
    return prevHead.next;
  }
};