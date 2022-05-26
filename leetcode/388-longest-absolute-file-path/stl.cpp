#include <algorithm>
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  int lengthLongestPath(string input) {
    int ans = 0;
    input.push_back('\n');
    vector<int> st(1, -1);
    for (auto p1 = input.begin(); p1 != input.end(); ) {
      auto p2 = find(p1, input.end(), '\n');
      int depth = count(p1, p2, '\t');
      int len = p2 - p1 - depth;
      st.resize(depth + 1);
      st.push_back(st.back() + len + 1);
      if (find(p1 + depth, p2, '.') != p2)
        ans = max(ans, st.back());
      p1 = next(p2);
    }
    return ans;
  }
};