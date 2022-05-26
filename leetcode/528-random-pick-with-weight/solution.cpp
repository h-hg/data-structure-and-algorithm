#include <vector>
#include <random>
#include <algorithm>
using namespace std;
class Solution {
public:
  vector<int> wSums;
  int maxSum;
  Solution(vector<int>& w) : wSums(w){
    partial_sum(wSums.begin(), wSums.end(), wSums.end());
    maxSum = wSums.back();
  }
  int pickIndex() {
    static default_random_engine rand_eng;
    static uniform_int_distribution<int> u(0, maxSum);
    return lower_bound(wSums.begin(), wSums.end(), u(rand_eng)) - wSums.begin();
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */