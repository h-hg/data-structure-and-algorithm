#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
class Solution {
public:
  bool carPooling(vector<vector<int>>& trips, int capacity) {
    int n = 1000 + 1;
    vector<int> diff(n, 0);
    for(auto &trip : trips) {
      int num = trip[0], from = trip[1], to = trip[2];
      // add num to range [from, to)
      diff[from] += num;
      if(to < n)
        diff[to] -= num;
    }
    // compuate the number of passengers in each location
    partial_sum(diff.begin(), diff.end(), diff.begin());
    // check the capacity in each location
    return find_if(diff.begin(), diff.end(), [capacity](int x) { return x > capacity;}) == diff.end();
  }
};