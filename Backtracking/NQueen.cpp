#include <iostream>
#include <vector>
using namespace std;

void appendConfiguration(const vector<vector<int>> &board, int n,
                         vector<vector<string>> &ans) {
  vector<string> temp;
  for (int i = 0; i < n; i++) {
    string str = "";
    for (int j = 0; j < n; j++) {
      char ch = board[i][j] == 0 ? '.' : 'Q';
      str += ch;
    }
    temp.push_back(str);
  }
  ans.push_back(temp);
}

bool isSafe(int row, int col, const vector<vector<int>> &board, int n) {
  int x = row, y = col;

  // same row check
  while (y >= 0) {
    if (board[x][y])
      return false;
    y--;
  }

  // top left diagonal check
  x = row, y = col;
  while (x >= 0 && y >= 0) {
    if (board[x][y])
      return false;

    x--;
    y--;
  }

  // bottom left diagonal check
  x = row, y = col;
  while (x < n && y >= 0) {
    if (board[x][y])
      return false;
    x++;
    y--;
  }

  return true;
}

void solve(int col, vector<vector<int>> &board, int n,
           vector<vector<string>> &ans) {
  if (col == n) {
    appendConfiguration(board, n, ans);
    return;
  }

  for (int row = 0; row < n; row++) {
    if (isSafe(row, col, board, n)) {
      board[row][col] = 1;
      solve(col + 1, board, n, ans);
      board[row][col] = 0;
    }
  }
}

vector<vector<string>> solution(int n) {
  vector<vector<int>> board(n, vector<int>(n, 0));
  vector<vector<string>> ans;
  solve(0, board, n, ans);
  return ans;
}

int main() {
  vector<vector<string>> ans;
  ans = solution(4);

  cout << "Total Possible solutions : " << ans.size() << endl;
  for (auto line : ans) {
    for (auto str : line) {
      cout << str << endl;
    }
    cout << endl;
  }

  return 0;
}