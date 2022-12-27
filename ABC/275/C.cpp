#include <cstdio>
#include <iostream>
using namespace std;
const int n = 9;
char s[n][n + 1];
bool check(int x, int y) {
  if (x < 0 || x >= n || y < 0 || y >= n) return false;
  return s[x][y] == '#';
}
int main() {
  for (int i = 0; i < n; i++) scanf("%s", s[i]);
  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int di = 1; di < n; di++)
        for (int dj = 0; dj < n; dj++)
          ans += check(i, j) && check(i + di, j + dj) &&
                 check(i + di - dj, j + dj + di) && check(i - dj, j + di);
  printf("%d\n", ans);
  return 0;
}