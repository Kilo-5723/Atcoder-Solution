#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int solve(const vector<int> &a, const vector<int> &b) {
  int res = 0;
  for (int i = 0; i < a.size(); i++) res += a[i] != b[i];
  return res;
}
int main() {
  int n, m, k, h, w;
  scanf("%d%d%d%d%d", &n, &m, &k, &h, &w);
  vector a(n, vector<int>(m));
  vector<int> cnt(k + 1);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
  for (auto &arr : a)
    for (auto v : arr) cnt[v]++;
  for (int p = 0; p + h <= n; p++) {
    vector<int> cur(k + 1);
    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++) cur[a[p + i][j]]++;
    printf("%d", solve(cnt, cur));
    for (int q = 0; q + w < m; q++) {
      for (int i = 0; i < h; i++) cur[a[p + i][q]]--;
      for (int i = 0; i < h; i++) cur[a[p + i][q + w]]++;
      printf(" %d", solve(cnt, cur));
    }
    puts("");
  }
  return 0;
}