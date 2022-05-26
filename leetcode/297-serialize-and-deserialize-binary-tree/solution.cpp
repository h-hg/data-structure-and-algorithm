#include "solution.h"
#include <string>
#include <sstream>
using namespace std;
class Codec {
public:
  static const char SEP = ' ';
  static const char NULLNODE = '#';
  
  void preTraverse(TreeNode *root, istringsstream && iss) {
    if(!root) {
      iss << NULLNODE << SEP;
      return;
    }
    // visit the node
    iss << (root -> val) << SEP;
    preTraverse(root -> left, iss);
    preTraverse(root -> right, iss);
  }
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    istringstream iss;
    preTraverse(root, iss);
    return iss.str();
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    ostringstream oss(data);
    string value;
    while(oss << value)
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));