#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> argsort(vector<int> const &arr) {
    auto idx = vector<int>(arr.size());
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(),[&arr](int x, int y) {
      return arr[x] > arr[y];
    });
    return idx;
  }
  vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans(nums1.size());
    sort(nums1.begin(), nums1.end(), greater<int>());
    // l1 and r1 are the two pointers of nums1
    int l1 = 0, r1 = nums1.size() - 1;
    for(auto i2 : argsort(nums2))
      ans[i2] = nums1[l1] > nums2[i2] ? nums1[l1++] : nums1[r1--];
    return ans;
  }
};
