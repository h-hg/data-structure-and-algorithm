#include <iostream>
#include "warshall.cpp"
using namespace std;
int main() {
  vector<vector<int>> w = {
    {0, 1, 0, 1},
    {0, 0, 0, 1},
    {0, 0, 0, 0},
    {1, 0, 1, 0}
  };
  for(auto &v: warshall(w)) {
    for(auto val : v)
      cout << val << ' ';
    cout << endl;
  }
  return 0;
}