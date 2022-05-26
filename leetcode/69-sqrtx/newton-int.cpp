class Solution {
 public:
  int mySqrt(int c) {
    if (c <= 1)
      return c;
    long long ans = c;
    do {
      ans = (ans + c / ans) / 2;
    } while (ans * ans - c > 0);
    return ans;
  }
};