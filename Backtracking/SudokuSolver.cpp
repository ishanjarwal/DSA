#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<char>> &board, int row, int col, char val) {
  for (int i = 0; i < 9; i++) {
    if (board[i][col] == val)
      return false;
    if (board[row][i] == val)
      return false;
    if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
      return false;
  }

  return true;
}
bool solve(vector<vector<char>> &board) {

  for (int row = 0; row < 9; row++) {
    for (int col = 0; col < 9; col++) {
      if (board[row][col] == '.') {
        for (char ch = '1'; ch <= '9'; ch++) {
          if (isSafe(board, row, col, ch)) {
            board[row][col] = ch;
            if (solve(board))
              return true;
            board[row][col] = '.';
          }
        }
        return false;
      }
    }
  }
  return true;
}
void solveSudoku(vector<vector<char>> &board) { solve(board); }

int main() {
  vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

  solveSudoku(board);

  cout << "Solved Sudoku:\n";
  for (int i = 0; i < 9; i++) {
    // Print a horizontal separator after every 3 rows
    if (i > 0 && i % 3 == 0) {
      cout << "---------------------\n";
    }

    for (int j = 0; j < 9; j++) {
      // Print a vertical separator after every 3 columns
      if (j > 0 && j % 3 == 0) {
        cout << "| ";
      }

      cout << board[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}