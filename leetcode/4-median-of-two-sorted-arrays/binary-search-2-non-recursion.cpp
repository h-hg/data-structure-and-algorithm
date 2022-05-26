class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size() + nums2.size();
    return n & 1 ? getKth(nums1, nums2, (n + 1) / 2) : (getKth(nums1, nums2, n / 2) + getKth(nums1, nums2, n / 2 + 1)) / 2.0;
  }
  int getKth(vector<int> &nums1, vector<int> &nums2, int k) {
    int i1 = 0, i2 = 0, n1 = nums1.size(), n2 = nums2.size();
    while(true) {
      if(i1 >= n1)
        return nums2[i2 + k - 1];
      if(i2 >= n2)
        return nums1[i1 + k - 1];
      if(k == 1)
        return min(nums1[i1], nums2[i2]);
      int pivot1 = (i1 + k / 2 - 1 < nums1.size()) ? nums1[i1 + k / 2 - 1] : INT_MAX;
      int pivot2 = (i2 + k / 2 - 1 < nums2.size()) ? nums2[i2 + k / 2 - 1] : INT_MAX;
      (pivot1 < pivot2 ? i1 : i2) += k / 2;
      k -= k / 2;
    }
  }
};