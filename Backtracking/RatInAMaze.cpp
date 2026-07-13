#include <bits/stdc++.h>
#include <vector>
using namespace std;

bool isSafe(int x, int y, vector<vector<bool>> &visited,
            vector<vector<int>> &arr, int n) {
  if ((x >= 0 && x < n) && (y >= 0 && y < n) && arr[x][y] == 1 &&
      !visited[x][y])
    return true;
  return false;
}

void solve(int x, int y, vector<vector<int>> &arr, int n, vector<string> &ans,
           vector<vector<bool>> &visited, string &path) {
  // base case
  if (x == n - 1 && y == n - 1) {
    ans.push_back(path);
    return;
  }

  visited[x][y] = true;
  // D
  if (isSafe(x + 1, y, visited, arr, n)) {
    path += 'D';
    solve(x + 1, y, arr, n, ans, visited, path);
    path.pop_back();
  }
  // L
  if (isSafe(x, y - 1, visited, arr, n)) {
    path += 'L';
    solve(x, y - 1, arr, n, ans, visited, path);
    path.pop_back();
  }
  // R
  if (isSafe(x, y + 1, visited, arr, n)) {
    path += 'R';
    solve(x, y + 1, arr, n, ans, visited, path);
    path.pop_back();
  }
  // U
  if (isSafe(x - 1, y, visited, arr, n)) {
    path += 'U';
    solve(x - 1, y, arr, n, ans, visited, path);
    path.pop_back();
  }
  visited[x][y] = false;
}

vector<string> searchMaze(vector<vector<int>> &arr, int n) {
  vector<string> ans;
  if (arr[0][0] == 0)
    return ans;
  vector<vector<bool>> visited(n, vector<bool>(n, false));

  string path = "";

  solve(0, 0, arr, n, ans, visited, path);
  return ans;
}

int main() {
  int n = 4;

  vector<vector<int>> arr = {
      {1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};

  vector<string> paths = searchMaze(arr, n);

  if (paths.empty()) {
    cout << "No path found.\n";
  } else {
    cout << "Possible paths:\n";
    for (const string &path : paths) {
      cout << path << endl;
    }
  }

  return 0;
}