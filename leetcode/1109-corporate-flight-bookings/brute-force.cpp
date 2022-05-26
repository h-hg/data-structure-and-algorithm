#include <vector>
using namespace std;
class Solution {
public:
  vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int> ans(n, 0);
    for(auto &booking : bookings)
      for(int i = booking[0] - 1; i < booking[1]; ++i)
        ans[i] += booking[2];
    return ans;
  }
};