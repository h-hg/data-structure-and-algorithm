#include <vector>
#include <climits>
//e is adjacent matrix
std::vector<std::vector<int>> floyd(const std::vector<std::vector<int>> &e) {
  //init the d
  auto d = e;
  int n = d.size();
  for(int k = 0; k < n; ++k)
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < n; ++j) {
        if(d[i][k] == INT_MAX || d[k][j] == INT_MAX)
          continue;
        else if(d[i][k] + d[k][j] < d[i][j])
          d[i][j] = d[i][k] + d[k][j];
  return d;
}