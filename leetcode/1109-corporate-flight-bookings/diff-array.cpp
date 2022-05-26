#include <vector>
#include <numeric>
using namespace std;
class Solution {
public:
  vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int> diff(n, 0);
    for(auto &booking : bookings) {
      int l = booking[0] - 1, r = booking[1], val = booking[2];
      diff[l] += val;
      if(r < n)
        diff[r] -= val;
    }
    partial_sum(diff.begin(), diff.end(), diff.begin());
    return diff;
  }
};