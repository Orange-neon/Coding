#include <bits/stdc++.h>
using namespace std;
int n, m, poolnum=0;
array<int, 8> dx = {1, 1, 1, -1, -1, -1, 0, 0};
array<int, 8> dy = {0, 1, -1, 0, 1, -1, 1, -1};
vector<vector<int>> maze;
vector<vector<int>> visited;
vector<vector<int>> pools_visited;

bool isvalid(int x, int y) {
  return x >= 0 && x < m && y >=0 && y < n && !visited[y][x];
}

bool ispvalid(int x, int y) {
  return x >= 0 && x < m && y >=0 && y < n && !pools_visited[y][x];
}

void pool_bfs(int x, int y) {
  queue<pair<int, int>> q;
  q.push({x,y});
  pools_visited[y][x] = 1;
  while (!q.empty()) {
    int sx = q.front().first, sy = q.front().second;
    for (int k = 0; k < 8; ++k) {
      int nx = sx + dx[k], ny = sy + dy[k];
      if (ispvalid(nx, ny) && maze[ny][nx] == 1) {
        q.push({nx, ny});
        pools_visited[ny][nx] = 1;
      }
    }
    q.pop();
  }
}

void bfs() {
  queue<pair<int, int>> q;
  q.push({0,0});
  visited[0][0] = 1;
  while (!q.empty()) {
    int x = q.front().first, y = q.front().second;
    for (int k = 0; k < 8; ++k) {
      int nx = x + dx[k], ny = y + dy[k];
      if (isvalid(nx, ny)) {
        q.push({nx, ny});
        visited[ny][nx] = 1;
        if (maze[ny][nx] == 1 && !pools_visited[ny][nx]) {
          pool_bfs(nx, ny);
          ++poolnum;
        }
      }
    }
    q.pop();
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    vector<int> row;
    for (int j = 0; j < m; ++j) {
      int pt;
      cin >> pt;
      row.push_back(pt);
    }
    maze.push_back(row);
  }
  visited.resize(n, vector<int>(m, 0));
  pools_visited.resize(n, vector<int>(m, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
        if (maze[i][j]==1 && !pools_visited[i][j]) {
            pool_bfs(j, i);
            ++poolnum;
        }
    }
  }
  cout << poolnum;
}