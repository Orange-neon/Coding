#include<bits/stdc++.h>
using namespace std;
int n, m, numRooms = 0;
vector<vector<char>> maze;
vector<vector<int>> visited;
vector<pair<int, int>> startingPts;
array<int, 4> dx = {0, 0, -1, 1};
array<int, 4> dy = {1, -1, 0, 0};
bool isValid(int x, int y) {
    return (x >= 0 && x < m && y >=0 && y < n && !(visited[y][x] == 1)) && maze[y][x] == '.';
}

void floodFill(int x, int y) {
    if (!isValid(x, y)) {
        return;
    }
    visited[y][x] = 1;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        floodFill(nx, ny);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("countingrooms.in", "r", stdin);
    cin >> n >> m;
    maze.resize(n, vector<char>(m, ' '));
    visited.resize(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            if (c == '.') {
                startingPts.push_back({j, i});
            }
            maze.at(i).at(j) = c;
        }
    }
    for (pair<int, int> pt : startingPts) {
        if (isValid(pt.first, pt.second)) {
            floodFill(pt.first, pt.second);
            ++numRooms;
        }
    }
    cout << numRooms;
}
/*
This is faster:

#include <iostream>
#include <vector>
using namespace std;
int num_rooms=0;
vector<vector<char>> g_maze;

vector<vector<bool>> g_visited;
int g_maze_n;
int g_maze_m;
void findroom(int x, int y) {
  if (x<0 || x>=g_maze_m || y<0 || y>=g_maze_n) {
    return;
  }
  if (g_visited[y][x]) {
    return;
  }
  if (g_maze[y][x]=='#') {
    return;
  }
  g_visited[y][x]=true;
  findroom(x+1, y);
  findroom(x-1, y);
  findroom(x, y+1);
  findroom(x, y-1);
  return;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,m;
  cin>>n>>m;
  vector<vector<char>> maze(n, vector<char>(m, '#'));
  vector<vector<bool>> visited(n+2, vector<bool>(m+2, false));
  g_visited=visited;
  for (int q=0; q<n; ++q) {
    for (int w=0; w<m; ++w) {
      cin>>maze[q][w];
    }
  }
  g_maze=maze;
  g_maze_n=n;
  g_maze_m=m;
  for (int q=0; q<n; ++q) {
    for (int w=0; w<m; ++w) {
      if (g_maze[q][w]=='.' && !g_visited[q][w]) {
          findroom(w, q);
          ++num_rooms;
      }
    }
  }

  cout<<num_rooms;
}
*/