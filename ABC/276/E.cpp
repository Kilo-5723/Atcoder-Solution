#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int buff = 2e6;
const int d = 4, dx[d] = {1, 0, -1, 0}, dy[d] = {0, 1, 0, -1};
char s[buff];
bool legal(int x, int y, const vector<vector<char>> &a) {
  return x >= 0 && x < a.size() && y >= 0 && y < a[0].size() && a[x][y] != '#';
}
bool dfs(int x, int y, int tx, int ty, const vector<vector<char>> &a,
         vector<vector<bool>> &vis) {
  if (vis[x][y]) return false;
  vis[x][y] = true;
  if (x == tx && y == ty) return true;
  for (int i = 0; i < d; i++) {
    int xx = x + dx[i], yy = y + dy[i];
    if (legal(xx, yy, a) && dfs(xx, yy, tx, ty, a, vis)) return true;
  }
  return false;
}
bool check(const vector<vector<char>> &a, int x, int y, int x1, int y1, int x2,
           int y2, int x3, int y3, int x4, int y4) {
  vector vis(a.size(), vector<bool>(a[0].size(), false));
  vis[x][y] = true;
  vis[x1][y1] = true;
  vis[x2][y2] = true;
  return dfs(x3, y3, x4, y4, a, vis);
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int x, y;
  vector a(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    for (int j = 0; j < m; j++) {
      a[i][j] = s[j];
      if (s[j] == 'S') {
        x = i;
        y = j;
      }
    }
  }
  for (int k1 = 0; k1 < d; k1++) {
    int x1 = x + dx[k1], y1 = y + dy[k1];
    if (legal(x1, y1, a)) {
      for (int k2 = k1 + 1; k2 < d; k2++) {
        int x2 = x + dx[k2], y2 = y + dy[k2];
        if (legal(x2, y2, a)) {
          for (int k3 = 0; k3 < d; k3++) {
            int x3 = x1 + dx[k3], y3 = y1 + dy[k3];
            if (legal(x3, y3, a) && (x3 != x || y3 != y)) {
              for (int k4 = 0; k4 < d; k4++) {
                int x4 = x2 + dx[k4], y4 = y2 + dy[k4];
                if (legal(x4, y4, a) && (x4 != x || y4 != y)) {
                  if (check(a, x, y, x1, y1, x2, y2, x3, y3, x4, y4)) {
                    puts("Yes");
                    return 0;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  puts("No");
  return 0;
}