#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> flip(vector<vector<int>> a) {
  int n = a.size(), m = a[0].size();
  vector b(m, vector<int>(n));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) b[j][i] = a[i][j];
  return b;
}
bool check(const vector<int> &a) {
  int las = 0;
  for (int i = 0; i < a.size(); i++)
    if (a[i]) {
      if (a[i] < las) return false;
      las = a[i];
    }
  return true;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector a(n, vector<int>(m));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
  for (int i = 0; i < n; i++) {
    stable_sort(a.begin(), a.end(),
                [&](const vector<int> &a, const vector<int> &b) {
                  if (!a[i] || !b[i]) return false;
                  return a[i] < b[i];
                });
  }
  puts("");
  for (int i = 0; i < n; i++) {
    for (auto v : a[i]) printf("%d ", v);
    puts("");
  }
  puts("");
  a = flip(a);
  for (int i = 0; i < n; i++) {
    for (auto v : a[i]) printf("%d ", v);
    puts("");
  }
  puts("");
  for (int i = 0; i < m; i++) {
    stable_sort(a.begin(), a.end(),
                [&](const vector<int> &a, const vector<int> &b) {
                  if (!a[i] || !b[i]) return false;
                  return a[i] < b[i];
                });
  }
  puts("");
  bool flg = true;
  for (int i = 0; i < m; i++) flg = flg && check(a[i]);
  a = flip(a);
  for (int i = 0; i < n; i++) flg = flg && check(a[i]);
  for (int i = 0; i < n; i++) {
    for (auto v : a[i]) printf("%d ", v);
    puts("");
  }
  puts(flg ? "Yes" : "No");
  return 0;
}