#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int n;
  vector<bool> visited;
  void print() {
    for(auto val : visited)
      cout << (val ? 1 : 0);
    cout << endl;
  }
  int dfs(vector<int> &nums, int i, int sum) {
    if(visited[i] || visited[(i - 1 + n) % n] || visited[(i + 1) % n]) {
      return sum;
    }
    visited[i] = true;
    int val1 = dfs(nums, (i + 2) % n, sum + nums[i]);
    print();
    // backtrace
    visited[i] = false;
    int val2 = dfs(nums, (i + 1) % n, sum);
    print();
    return max(val1, val2);
  }
  int rob(vector<int>& nums) {
    n = nums.size();
    visited = vector<bool>(n, false);
    return dfs(nums, 0, 0);
  }
};
int main() {
  vector<int> v = {2,3,2};
  Solution sl;
  cout << sl.rob(v) << endl;
  return 0;
}