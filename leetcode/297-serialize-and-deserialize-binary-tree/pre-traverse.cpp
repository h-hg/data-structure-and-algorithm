#include "solution.h"
#include <string>
#include <sstream>
using namespace std;
class Codec {
private:
  static const char SEP = ' ';
  static const char NULLNODE = '#'; 
public:
  // Encodes a tree to a single string.
  void serialize(TreeNode *root, ostringstream &oss) {
    if(!root)
      oss << "# ";
    oss << (root -> val) << SEP;
    serialize(root -> left);
    serialize(root -> right);
  } 
  string serialize(TreeNode* root) {
    ostringstream oss;
    serialize(root, oss);
    return oss.str();
  }
  TreeNode* deserialize(istringstream &iss) {
    string value;
    iss >> value;
    if(value == "#")
      return nullptr;
    return new TreeNode(
      stoi(value),
      deserialize(iss),
      deserialize(iss)
    );
  }
  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    istringstream iss(data);
    return deserialize(iss);
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
