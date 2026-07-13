#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int row, int col, int n, vector<bool> &sameRowCheck,
            vector<bool> &upperDiagonalCheck,
            vector<bool> &lowerDiagonalCheck) {

  if (sameRowCheck[row] || upperDiagonalCheck[(n - 1) + col - row] ||
      lowerDiagonalCheck[row + col])
    return false;

  return true;
}

void solve(int col, vector<vector<string>> &ans, vector<string> &board, int n,
           vector<bool> &sameRowCheck, vector<bool> &upperDiagonalCheck,
           vector<bool> &lowerDiagonalCheck) {
  // base case
  if (col == n) {
    ans.push_back(board);
    return;
  }

  // solve for 1st queen in every cell of first column for each row
  for (int row = 0; row < n; row++) {
    if (isSafe(row, col, n, sameRowCheck, upperDiagonalCheck,
               lowerDiagonalCheck)) {
      board[row][col] = 'Q';
      sameRowCheck[row] = true;
      upperDiagonalCheck[(n - 1) + col - row] = true;
      lowerDiagonalCheck[row + col] = true;
      solve(col + 1, ans, board, n, sameRowCheck, upperDiagonalCheck,
            lowerDiagonalCheck);
      // backtrack : remove queen
      sameRowCheck[row] = false;
      upperDiagonalCheck[(n - 1) + col - row] = false;
      lowerDiagonalCheck[row + col] = false;
      board[row][col] = '.';
    }
  }
}

vector<vector<string>> solveNQueens(int n) {
  vector<string> board(n, string(n, '.'));
  vector<vector<string>> ans;

  vector<bool> sameRowCheck(n, false);
  vector<bool> upperDiagonalCheck(2 * n - 1, false);
  vector<bool> lowerDiagonalCheck(2 * n - 1, false);

  solve(0, ans, board, n, sameRowCheck, upperDiagonalCheck, lowerDiagonalCheck);
  return ans;
}

int main() {
  vector<vector<string>> ans;
  ans = solveNQueens(4);

  cout << "Total Possible solutions : " << ans.size() << endl;
  for (auto line : ans) {
    for (auto str : line) {
      cout << str << endl;
    }
    cout << endl;
  }

  return 0;
}