#include <vector>
using namespace std;
class Solution {
public:
  void swap_by_leading_diagonal(vector<vector<int>> &matrix) {
    int n = matrix.size();
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < i; ++j)
        swap(matrix[i][j], matrix[j][i]);
  }
  void reverse_by_row(vector<vector<int>> &matrix) {
    int n = matrix.size();
    for(int j = 0; j < n / 2; ++j)
      for(int i = 0; i < n; ++i)
        swap(matrix[i][j], matrix[i][n - 1 - j]);
  }
  void rotate(vector<vector<int>>& matrix) {
    swap_by_leading_diagonal(matrix);
    reverse_by_row(matrix);
  }
};