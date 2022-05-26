#include <string>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
  int lengthLongestPath(string input) {
    int ans = 0;
    input.push_back('\n');
    vector<int> st(1, -1); // use vector to simulate stack, insert a dummy node `-1`, for root isn't started with '/'
    for(auto p = input.begin(); p != input.end();) {
      // count '\t'
      int depth = 1; // start from 1, for there is a dummy node at the head of the `st`
      for(; *p == '\t'; ++depth, ++p);
      // count the length of file/dir name
      bool isFile = false;
      int len = 0;
      for(; *p != '\n'; ++p, ++len)
          if(*p == '.')
            isFile = true;
      // update the stack
      st.resize(depth); // pop the stack
      st.push_back(st.back() + len + 1); // +1 stands for the length of '/'
      // update the ans
      if(isFile)
        ans = max(ans, st.back());
      // skip the '\n'
      ++p;
    }
    return ans;
  }
};