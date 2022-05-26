#include "solution.h"
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
  using Iter = vector<int>::const_iterator;
  unordered_map<int, Iter> val2Pos;
  TreeNode* helper(Iter preFirst, Iter preLast, Iter inFirst, Iter inLast) {
    if(preFirst == preLast)
      return nullptr;
    auto root = val2Pos[*preFirst];
    int nLeftNodes = root - inFirst;
    auto newPreFirst = next(preFirst);
    return new TreeNode(
      *root,
      helper(newPreFirst, newPreFirst + nLeftNodes, inFirst, inFirst + nLeftNodes),
      helper(newPreFirst + nLeftNodes, preLast, next(root), inLast)
    );
  }
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    for(auto iter = inorder.begin(); iter != inorder.end(); ++iter)
      val2Pos[*iter] = iter;
    return helper(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
  }
};