#include "solution.h"
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
  using Iter = vector<int>::const_iterator;
  unordered_map<int, Iter> val2Pos;
  TreeNode* helper(Iter preFirst, Iter preLast, Iter postFirst, Iter postLast) {
    if(preFirst == preLast)
      return nullptr;
    auto preNewRoot = next(preFirst);
    auto letfRoot = val2Pos[*preNewRoot];
    int nLeftNodes = letfRoot - postFirst + 1;
    return new TreeNode(
      *preFirst,
      helper(preNewRoot, preNewRoot + nLeftNodes, postFirst, postFirst + nLeftNodes),
      helper(preNewRoot + nLeftNodes, preLast, postFirst + nLeftNodes, prev(postLast))
    );
  }
  TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
    for(auto iter = postorder.begin(); iter != postorder.end(); ++iter)
      val2Pos[*iter] = iter;
    return helper(preorder.begin(), preorder.end(), postorder.begin(), postorder.end());
  }
};