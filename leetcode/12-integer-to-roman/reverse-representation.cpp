#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
  string intToRoman(int num) {
    string ans;
    char symbols[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    char *table = symbols;
    // The answer is represented by inverted Roman numerals. 
    while (num) {
      int tmp = num % 10;
      num /= 10;
      switch (tmp) {
      case 3:
        ans += table[0];
      case 2:
        ans += table[0];
      case 1:
        ans += table[0];
        break;
      case 4:
        ans += table[1];
        ans += table[0];
        break;
      case 8:
        ans += table[0];
      case 7:
        ans += table[0];
      case 6:
        ans += table[0];
      case 5:
        ans += table[1];
        break;
      case 9:
        ans += table[2];
        ans += table[0];
        break;
      }
      table += 2;
    }
    // reverse the ans to the final answer
    reverse(ans.begin(), ans.end());
    return ans;
  }
};