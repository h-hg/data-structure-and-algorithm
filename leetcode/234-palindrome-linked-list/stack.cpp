#include "solution.h"
#include <stack>
using namespace std;
class Solution {
public:
  bool isPalindrome(ListNode* head) {
    stack<ListNode*> st;
    auto cur = head;
    while(cur) {
      st.push(cur);
      cur = cur -> next;
    }
    cur = head;
    while(st.size()) {
      auto back = st.top();
      st.pop();
      if(back -> val != cur -> val)
        return false;
      cur = cur -> next;
    }
    return true;
  }
};