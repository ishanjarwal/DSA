#include <bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, vector<vector<int>> &arr,
            vector<vector<bool>> &visited, int n) {
  return x >= 0 && x < n && y >= 0 && y < n && arr[x][y] == 1 && !visited[x][y];
}

void solve(int x, int y, vector<vector<int>> &arr, int n,
           vector<vector<bool>> &visited, vector<string> &ans, string &path) {

  if (x == n - 1 && y == n - 1) {
    ans.push_back(path);
    return;
  }

  visited[x][y] = true;

  int dx[] = {1, 0, 0, -1};
  int dy[] = {0, -1, 1, 0};
  char dir[] = {'D', 'L', 'R', 'U'};

  for (int i = 0; i < 4; i++) {
    int newX = x + dx[i];
    int newY = y + dy[i];

    if (isSafe(newX, newY, arr, visited, n)) {
      path.push_back(dir[i]);
      solve(newX, newY, arr, n, visited, ans, path);
      path.pop_back();
    }
  }

  visited[x][y] = false;
}

vector<string> searchMaze(vector<vector<int>> &arr, int n) {
  vector<string> ans;

  if (arr.empty() || arr[0][0] == 0 || arr[n - 1][n - 1] == 0)
    return ans;

  vector<vector<bool>> visited(n, vector<bool>(n, false));
  string path;

  solve(0, 0, arr, n, visited, ans, path);
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