#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
  int maxEnvelopes(vector<vector<int>>& envelopes) {
    sort(envelopes.begin(), envelopes.end(), [](vector<int> const &x, vector<int> const &y) {
      return x[0] < y[0] || (x[0] == y[0] && x[1] > y[1]);
    });
    int n = envelopes.size();
    vector<int> dp(n, 1);
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < i; ++j)
        if(envelopes[j][1] < envelopes[i][1])
          dp[i] = max(dp[i], dp[j] + 1);
    return *max_element(dp.begin(), dp.end());
  }
};