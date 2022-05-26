#include "solution.h"
#include <algorithm>
#include <tuple>
#include <stack>
#include <vector>
using namespace std;
class Solution {
 public:
  TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
    TreeNode *pTree = nullptr;

    using IteratorT = std::decay_t<decltype(nums)>::const_iterator;

    std::stack<std::tuple<TreeNode **, IteratorT, IteratorT>> s;

    s.push(std::make_tuple(&pTree, nums.cbegin(), nums.cend()));
    while (!s.empty()) {
      auto [ppTree, begin, end] = std::move(s.top());
      s.pop();
      auto middle = std::max_element(begin, end);
      if (middle == end) {
        *ppTree = nullptr;
        continue;
      }

      *ppTree = new TreeNode(*middle);
      s.push(std::make_tuple(&(*ppTree)->right, std::next(middle), end));
      s.push(std::make_tuple(&(*ppTree)->left, begin, middle));
    }

    return pTree;
  }
};