#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
  enum {FLAG = 'o'};
  const vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  void solve(vector<vector<char>>& board) {
    int m = board.size(), n = board[0].size();
    queue<pair<int, int>> q;
    // add bfs source
    for(int i = 0; i < m; ++i) {
      if(board[i][0] == 'O') {
        board[i][0] = FLAG;
        q.push({i, 0});
      }
      if(board[i][n - 1] == 'O') {
        board[i][n - 1] = FLAG;
        q.push({i, n - 1});
      }
    }
    for(int j = 0; j < n; ++j) {
      if(board[0][j] == 'O') {
        board[0][j] = FLAG;
        q.push({0, j});
      }
      if(board[m - 1][j] == 'O') {
        board[m - 1][j] = FLAG;
        q.push({m - 1, j});
      }
    }
    // multi bfs
    while(q.size()) {
      auto [r, c] = q.front();
      q.pop();
      for(auto [deltaR, deltaC] : dirs) {
        auto newR = r + deltaR, newC = c + deltaC;
        if(
          newR >= 0 && newR < m && newC >= 0 && newC < n
          && board[newR][newC] == 'O'
        ) {
          // set flag (visited)
          board[newR][newC] = FLAG;
          q.push({newR, newC});
        }
      }
    }
    // modify
    for(int i = 0; i < m; ++i)
      for(int j = 0; j < n; ++j)
        if(board[i][j] == 'O')
        board[i][j] = 'X';
        else if(board[i][j] == FLAG)
          board[i][j] = 'O';
  }
};