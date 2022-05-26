#include <algorithm>
#include <vector>
#include <map>
using namespace std;
class Solution {
  // state, S_ERROR means the state is unvalid
  enum {
    S0 = 0, S1, S2, S3, S4, S5, S6, S_ERROR
  };
  //input type
  enum {
    b0xxxxxxx = 0, b10xxxxxx, b110xxxxx, b1110xxxx, b11110xxx, OTHER
  };
  vector<map<int, int>> table = {
    {{b0xxxxxxx, S0}, {b110xxxxx, S1}, {b1110xxxx, S2}, {b11110xxx, S3}}, // for state ZERO
    {{b10xxxxxx, S0}}, // for state S1
    {{b10xxxxxx, S4}}, // for state S2
    {{b10xxxxxx, S5}}, // for state S3
    {{b10xxxxxx, S0}}, // for state S4
    {{b10xxxxxx, S6}}, // for state S5
    {{b10xxxxxx, S0}} // for state S6
  };
  int getInputType(int byte) {
    int prefix = byte & 0xf8; // 0xf8 = 0b 1111 1000
    if(prefix <= 0x7f) { // 0x7f = 0111 1111
      return b0xxxxxxx;
    } else if(prefix <= 0xbf) { // 0xbf = 0b 1011 1111
      return b10xxxxxx;
    } else if(prefix <= 0xdf) { // 0xdf = 0b 1101 1111
      return b110xxxxx;
    } else if(prefix <= 0xef) { // 0xef = 0b 1110 1111
      return b1110xxxx;
    } else if(prefix <= 0xf7) { // 00b 1111 0111
      return b11110xxx;
    } else {
      return OTHER;
    }
  }
  // return the next state
  int updateState(int byte) {
    int type = getInputType(byte);
    auto res = table[state].find(type);
    return state = res == table[state].end() ? S_ERROR : res -> second;
  }

  int state = S0;
public:
  bool validUtf8(vector<int>& data) {
    for(auto &byte : data)
      if(updateState(byte) == S_ERROR)
        return false;
    return state == S0;
  }
};