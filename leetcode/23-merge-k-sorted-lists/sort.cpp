#include "solution.h"
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class Solution {
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    vector<ListNode*> v;
    for(auto list: lists)
      while(list){
        v.push_back(list);
        list = list -> next;
      }
    sort(v.begin(), v.end(), [](ListNode * x, ListNode *y) {
      return x -> val < y -> val;
    });
    ListNode head, *cur = &head;
    for(auto node : v)
      cur = cur -> next = node;
    cur -> next = nullptr;
    return head.next;
  }
};
