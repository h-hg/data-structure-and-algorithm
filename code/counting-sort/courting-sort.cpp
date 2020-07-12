#include <algorithm>
#include <vector>
using namespace std;
vector<int> counting_sort(vector<int> const &a) {
  //find the minVal and maxVal
  auto p = minmax_element(a.begin(), a.end());
  auto minVal = *p.first, maxVal = *p.second, k = maxVal - minVal + 1;
  //count
  vector<int> val2cnt(k, 0);
  for(int i = 0; i < a.size(); ++i)
    ++val2cnt[a[i] - minVal];
  //output
  vector<int> ret;
  ret.reserve(a.size());
  for(int i = 0; i < k; ++i)
    for(int j = 0; j < val2cnt[i]; ++j)
      ret.push_back(i + minVal);
  return ret;
}