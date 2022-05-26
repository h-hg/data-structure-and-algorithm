class Solution {
 public:
  int mySqrt(int c) {
    if (c <= 1)
      return c;
    double x_n1 = c, x_n;
    do {
      x_n = x_n1;
      x_n1 = (x_n + c / x_n) / 2;
    } while(x_n - x_n1 > 1e-6);
    return x_n1;
  }
};