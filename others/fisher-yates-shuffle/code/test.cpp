#include "fisher-yates-shuffle.hpp"
#include <iostream>
#include <vector>
using namespace std;
int main() {
  vector<int> v = {1, 2, 3, 4, 5, 6, 7};
  shuffle(v.begin(), v.end());
  for(auto val :v)
    cout << val << ' ';
  cout << endl;
  return 0;
}