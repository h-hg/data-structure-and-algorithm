#include "kruskal_matrix.cpp"
using namespace std;
int main() {
  vector<vector<int>> graph = {
    {0, 6, 1, 5, INT_MAX, INT_MAX},
    {6, 0, 5, INT_MAX, 3, INT_MAX},
    {1, 5, 0, 5, 6, 4},
    {5, INT_MAX, 5, 0, INT_MAX, 2},
    {INT_MAX, 3, 6, INT_MAX, 0, 6},
    {INT_MAX, INT_MAX, 4, 2, 6, 0}
  };
  cout << kruskal(graph) << endl;
  return 0;
}