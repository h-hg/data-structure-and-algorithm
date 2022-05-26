//#include "adjacent_matrix.cpp"
#include "adjacent_matrix_optimized.cpp"

int main() {
  using namespace std;
  vector<vector<int>> graph = {
    {0, INT_MAX, 10, INT_MAX, 30, 100},
    {INT_MAX, 0, 5, INT_MAX, INT_MAX, INT_MAX},
    {INT_MAX, INT_MAX, 0, 50, INT_MAX, INT_MAX},
    {INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, 10},
    {INT_MAX, INT_MAX, INT_MAX, 20, 0, 60},
    {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0}
  };
  for(auto val: dijkstra(graph, 0))
    if(val == INT_MAX)
      cout << "oo ";
    else
      cout << val << ' ';
  cout << endl;
  return 0;
}