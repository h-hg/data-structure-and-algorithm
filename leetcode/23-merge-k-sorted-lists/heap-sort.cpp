#include "solution.h"
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
  struct Cmp {
    bool operator()(ListNode * x, ListNode *y) {
      return x -> val > y -> val;
    }
  };
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, Cmp> pq;
    for(auto list : lists)
      if(list)
         pq.push(list);
    ListNode head, *cur = &head;
    while(pq.size()) {
      cur = cur -> next = pq.top();
      pq.pop();
      if(cur -> next)
        pq.push(cur -> next);
    }
    return head.next;
  }
};