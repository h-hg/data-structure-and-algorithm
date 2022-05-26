#include <string>
#include <vector>
using namespace std;

class Solution {
  // state
  enum {
    S0 = 0, S1, S2, S3, S4, S5, S6, S7, S8, S_ERROR
  };
  // input type
  enum {
    BLANK = 0, SIGN, DIGIST, DOT, E, OTHER
  };
  vector<vector<int>> table = {
    {S0, S1, S6, S2, S_ERROR, S_ERROR},
    {S_ERROR, S_ERROR, S6, S2, S_ERROR, S_ERROR},
    {S_ERROR, S_ERROR, S3, S_ERROR, S_ERROR, S_ERROR},
    {S8, S_ERROR, S3, S_ERROR, S4, S_ERROR},
    {S_ERROR, S7, S5, S_ERROR, S_ERROR, S_ERROR},
    {S8, S_ERROR, S5, S_ERROR, S_ERROR, S_ERROR},
    {S8, S_ERROR, S6, S3, S4, S_ERROR},
    {S_ERROR, S_ERROR, S5, S_ERROR, S_ERROR, S_ERROR},
    {S8, S_ERROR, S_ERROR, S_ERROR, S_ERROR, S_ERROR}
  };
  int getInputType(char c) {
    switch (c) {
    case ' ':
      return BLANK;
    case '+':
    case '-':
      return SIGN;
    case '.':
      return DOT;
    case 'e':
      return E;
    default:
      return '0' <= c && c <= '9' ? DIGIST : OTHER;
    }
  }
  int updateState(char c) {
    return state = table[state][getInputType(c)];
  }
  int state = S0;
public:
  bool isNumber(string &s) {
    for(auto &c : s)
      if(updateState(c) == S_ERROR)
        return false;
    return state == S3 || state == S5 || state == S6 || state == S8;
  }
};