#include <vector>
#include <string>
using namespace std;
class Solution {
public:
  string convert(string &s, int numRows) {
    if(numRows == 1)
      return s;
    vector<string> m(numRows); // m[i] is row i of the output
    bool direction = 0; // true stands for down, false stands for up
    int row = 0;
    for(auto &c : s) {
      m[row].push_back(c);
      // judge the direction
      if(row == numRows - 1 || row == 0)
        direction = ! direction;
      // get the next row
      row += direction ? 1 : -1;
    }
    string ans;
    for(auto &str : m)
        ans += str;
    return ans;
  }
};