#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  // states
  enum {
    START = 0, SIGNED, NUMBER, END
  };
  // input type
  enum {
    SPACE = 0, SIGN, DIGIST, OTHER
  };
  vector<vector<int>> table = {
    {START, SIGNED, NUMBER, END}, // for START 
    {END, END, NUMBER, END},      // for SIGNED
    {END, END, NUMBER, END},      // for NUMBER
    {END, END, END, END}          // for END
  };
  int getInputType(char c) {
    if(c == ' ')
      return SPACE;
    else if(c == '+' || c == '-')
      return SIGN;
    else if('0' <= c && c <= '9')
      return DIGIST;
    else
      return OTHER;
  }

  int updateState(char c) {
    // get the next state
    state = table[state][getInputType(c)];
    // action of state transition
    if(state == NUMBER) {
      ans = ans * 10 + c - '0';
      ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
    } else if(state == SIGNED) {
      sign = c == '+' ? 1 : -1;
    }
    return state;
  }
  
  int state = START;
  int sign = 1;
  long long ans = 0;
public:
  int myAtoi(string &s) {
    for(auto &c : s)
      if(updateState(c) == END)
        return sign * ans;
    return sign * ans;
  }
};