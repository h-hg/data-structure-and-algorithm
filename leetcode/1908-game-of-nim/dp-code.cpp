#include <vector>
using namespace std;
class Solution {
public:
  enum {NONE=-1, FAIL=false, WIN=true};
  vector<int> dp;
  int encode(vector<int>& piles) {
    int ans = 0, base = 1;
    for(auto val : piles) {
      ans += base * val;
      base *= (1 << 3);
    }
    return ans;
  }
  int changState(int state, int pos, int val) {
    int bitPos = pos * 3;
    // set bit to 0
    state &= ~(7 << bitPos); // 7(10) = 111(2)
    // add val
    state |= (val << bitPos);
    return state;
  }
  int stateAt(int state, int pos) {
    int bitPos = pos * 3;
    return (state & (7 << bitPos)) >> bitPos;
  }
  bool dfs(int piles, int n) {
    if(dp[piles] != NONE)
      return dp[piles];

    bool flag = false;
    for (int i = 0; i < n && !flag; ++i)
      for (int j = 1, m = stateAt(piles, i); j <= m && !flag; ++j)
        flag = !dfs(changState(piles, i, m - j), n);

    return dp[piles] = flag;
  }
  bool nimGame(vector<int>& piles) {
    dp = vector<int>(1 << 21, NONE);
    dp[0] = false;
    return dfs(encode(piles), piles.size());
  }
};