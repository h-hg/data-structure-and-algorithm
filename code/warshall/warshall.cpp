#include <vector>
//e is an adjacent matrix
std::vector<std::vector<int>> warshall(std::vector<std::vector<int>> const&w0) {
  int n = w0.size();
  auto w = w0;
  for(int k = 0; k < n; ++k)
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < n; ++j)
        w[i][j] = w[i][j] || (w[i][k] && w[k][j]);
  return w;
}
