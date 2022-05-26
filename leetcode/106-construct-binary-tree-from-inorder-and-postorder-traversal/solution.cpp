#include "solution.h"
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
  using Iter = vector<int>::const_iterator;
  unordered_map<int, Iter> val2Pos;
  TreeNode* helper(Iter inFirst, Iter inLast, Iter postFirst, Iter postLast) {
    if(inFirst == inLast)
      return nullptr;
    auto newPostLast = prev(postLast);
    auto root = val2Pos[*newPostLast];
    int nLeftNodes = root - inFirst;
    return new TreeNode(
      *root,
      helper(inFirst, root, postFirst, postFirst + nLeftNodes),
      helper(next(root), inLast, postFirst + nLeftNodes, newPostLast)
    );
  }
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    for(Iter iter = inorder.begin(); iter != inorder.end(); ++iter)
      val2Pos[*iter] = iter;
    return helper(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
  }
};