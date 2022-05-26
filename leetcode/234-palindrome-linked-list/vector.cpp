#include "solution.h"
#include <vector>
using namespace std;
class Solution {
public:
  bool isPalindrome(ListNode* head) {
    vector<int> v;
    while(head) {
      v.push_back(head -> val);
      head = head -> next;
    }
    for(int i = 0, j = v.size() - 1; i < j; )
      if(v[i++] != v[j--])
        return false;
    return true;
  }
};