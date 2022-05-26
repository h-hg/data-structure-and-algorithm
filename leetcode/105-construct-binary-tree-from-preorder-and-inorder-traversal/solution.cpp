#include "solution.h"
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
  using Iter = vector<int>::const_iterator;
  TreeNode* helper(Iter preFirst, Iter preLast, Iter inFirst, Iter inLast) {
    if(preFirst == preLast)
      return nullptr;
    auto root = find(inFirst, inLast, *preFirst);
    int nLeftNodes = root - inFirst;
    auto newPreFirst = next(preFirst);
    return new TreeNode(
      *root,
      helper(newPreFirst, newPreFirst + nLeftNodes, inFirst, inFirst + nLeftNodes),
      helper(newPreFirst + nLeftNodes, preLast, next(root), inLast)
    );
  }
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return helper(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
  }
};