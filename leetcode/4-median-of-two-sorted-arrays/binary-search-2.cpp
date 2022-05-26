#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size() + nums2.size();
    return n & 1 ? getKth(nums1, 0, nums2, 0, (n + 1) / 2) : ( getKth(nums1, 0, nums2, 0, n / 2) + getKth(nums1, 0, nums2, 0, n / 2 + 1) ) / 2.0;
  }
  int getKth(vector<int> &nums1, int i1, vector<int> &nums2, int i2, int k){
    if(i1 >= nums1.size()) // nums1 is an empty array
      return nums2[i2 + k - 1];
    if(i2 >= nums2.size()) // nums2 is an empty array
      return nums1[i1 + k - 1];
    if(k == 1)
      return min(nums1[i1], nums2[i2]);
    int pivot1 = (i1 + k / 2 - 1 < nums1.size()) ? nums1[i1 + k / 2 - 1] : INT_MAX;
    int pivot2 = (i2 + k / 2 - 1 < nums2.size()) ? nums2[i2 + k / 2 - 1] : INT_MAX;
    return pivot1 < pivot2 ? getKth(nums1, i1 + k / 2, nums2, i2 , k - k / 2) : getKth(nums1, i1, nums2, i2 + k / 2 , k - k / 2);
  }
};