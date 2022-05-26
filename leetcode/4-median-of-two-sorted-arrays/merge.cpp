#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int i = 0, n = (nums1.size() + nums2.size()) / 2 + 1, i1 = 0, i2 = 0;
    vector<int> nums(n);
    while(i < n && i1 < nums1.size() && i2 < nums2.size())
      nums[i++] = nums1[i1] < nums2[i2] ? nums1[i1++] : nums2[i2++];
    while(i < n && i1 < nums1.size())
      nums[i++] = nums1[i1++];
    while(i < n && i2 < nums2.size())
      nums[i++] = nums2[i2++];
    return (nums1.size() + nums2.size()) % 2 ? nums.back() : (nums.back() + nums[n - 2]) / 2.0; 
  }
};