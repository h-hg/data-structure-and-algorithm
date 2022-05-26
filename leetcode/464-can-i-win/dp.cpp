#include <vector>
#include <bitset>
using namespace std;
class Solution {
public:
  enum {NONE=-1, FAIL=false, WIN=true};
  vector<int> dp;
  bool dfs(int maxChoosableInteger, int desiredTotal, int state, int currentTotal) {
    if(dp[state] != NONE)
      return dp[state];
    
    bool flag = false;
    for(int i = 1; i <= maxChoosableInteger && !flag; ++i)
      // bit 1 - used, bit 0 - unused
      if(((state >> (i-1)) & 1) == 0) {
        currentTotal += i;
        flag = currentTotal >= desiredTotal ? true : !dfs(maxChoosableInteger, desiredTotal, state | (1 << (i-1)), currentTotal);
        currentTotal -= i;
      }
    return dp[state] = flag;
  }
  bool canIWin(int maxChoosableInteger, int desiredTotal) {
    if((maxChoosableInteger + 1) * maxChoosableInteger / 2 < desiredTotal)
      return false; // no one can win
    dp = vector<int>(1 << 20, NONE);
    return dfs(maxChoosableInteger, desiredTotal, 0, 0);
  }
};

int main() {
  Solution sl;
  sl.canIWin(10, 0); // 为什么是 false，貌似 debug 也有问题
  return 0;
}