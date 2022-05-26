#include <map>
#include <string>
using namespace std;
class Solution {
public:
  map<string, bool> dp;
  bool dfs(string &currentState) {
    if(auto iter = dp.find(currentState); iter != dp.end())
      return iter -> second;

    bool flag = false;
    for(int i = 1; i < currentState.size() && !flag; ++i)
      if(currentState[i] == '+' && currentState[i-1] == '+') {
        currentState[i] = currentState[i-1] = '-';
        flag = !dfs(currentState);
        currentState[i] = currentState[i-1] = '+';
      }
    return dp[currentState] = flag;
  }
  bool canWin(string currentState) {
    return dfs(currentState);
  }
};