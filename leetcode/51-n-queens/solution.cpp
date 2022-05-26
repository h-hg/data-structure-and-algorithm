#include <vector>
#include <string>
using namespace std;
class Solution {
public:
  vector<vector<string>> ans;

  vector<string> board;
  vector<int> colOfQueens; // colOfQueens[i] is the column index of queen in the i-th row

  bool isValid(int row, int col) {
    for(int i = 0; i < row; ++i)
      if(col == colOfQueens[i] || abs(colOfQueens[i] - col) == abs(i - row))
        return false;
    return true;
  }

  void helper(int row) {
    if(row == board.size()) {
      ans.push_back(board);
      return;
    }
    for(int col = 0; col < board.size(); ++col)
      if(isValid(row, col)) {
        // place
        board[row][col] = 'Q';
        colOfQueens[row] = col;
        // dfs
        helper(row + 1);
        // unplace
        board[row][col] = '.';
        // colOfQueens[row] = -1;
      }

  }
  vector<vector<string>> solveNQueens(int n) {
    board = vector<string>(n, string(n, '.'));
    colOfQueens = vector<int>(n, -1);
    helper(0);
    return ans;
  }
};