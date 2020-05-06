#include "topological-sort-dfs.hpp"
#include "topological-sort-reduce.hpp"
#include <iostream>
using namespace std;
int main() {
  std::vector<std::vector<int>> e1 {
    {2},
    {2},
    {3, 4},
    {},
    {3},
    {}
  }, e2 = {
    {2},
    {2},
    {3, 4},
    {4},
    {3},
    {}
  };
  cout << "reduce: ";
  for(auto val : topological_sort_reduce(e1))
    cout << val << ' ';
  cout << endl;
  cout << "dfs: ";
  for(auto val : topological_sort_dfs(e1))
    cout << val << ' ';
  cout << endl;
  cout << "reduce loop: ";
  for(auto val : topological_sort_reduce_loop(e2))
    cout << val << ' ';
  cout << endl;
  cout << "dfs loop: ";
  for(auto val : topological_sort_dfs_loop(e2))
    cout << val << ' ';
  cout << endl;
  return 0;
}