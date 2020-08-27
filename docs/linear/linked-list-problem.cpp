struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution2 {
public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    //Node *pre = nullptr, 
  }
};
// m = 1, n = 4 过不了，可以是试试 head = new ListNode(0, head)
class Solution {
public:
  ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode *lp = head, *rp;
    for(int i = 2; i < m; ++i)
      lp = lp -> next;
    ListNode *prev = lp, *cur = lp -> next, *next;
    for(int i = m; i <= n; ++i) {
      next = cur -> next;
      cur -> next = prev;
      prev = cur;
      cur = next;
    }
    //rp = cur;
    //cout << (lp -> next ->val) << ' ' << (lp -> next -> next-> val) << ' ' << (prev-> val) << ' ' << (cur -> val);
    lp -> next -> next = cur;
    lp -> next = prev;
    return m == 1 ? prev : head;
  }
};