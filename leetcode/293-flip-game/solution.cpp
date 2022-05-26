#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  vector<string> generatePossibleNextMoves(string currentState) {
    vector<string> ans;
    for(int i = 1; i < currentState.size(); ++i)
      if(currentState[i] == '+' && currentState[i-1] == '+') {
          currentState[i-1] = currentState[i] = '-';
          ans.push_back(currentState);
          currentState[i-1] = currentState[i] = '+';
      }
    return ans;
  }
};