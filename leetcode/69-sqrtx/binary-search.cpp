class Solution {
public:
  int mySqrt(int x) {
    if (x <= 1)
      return x;
    long low = 1, high = x, mid, product;  // 'long' avoids overflow
    while (low <= high) {
      mid = low + (high - low) / 2;
      product = mid * mid;
      if (product == x)
        return mid;
      else if (product < x)
        low = mid + 1;
      else
        high = mid - 1;
    }
    // because we could have incremented mid when 'product < x'
    if (mid * mid > x)
      mid -= 1;
    return mid;
  }
};