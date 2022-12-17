#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
bool dfs(vector<vector<int>> &e, vector<int> &c, int u, int k) {
  if (c[u]) return k == c[u];
  c[u] = k;
  for (auto v : e[u])
    if (!dfs(e, c, v, -k)) return false;
  return true;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<vector<int>> e(n + 1);
  for (int i = 0; i < m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    e[u].push_back(v);
    e[v].push_back(u);
  }
  vector<int> c(n + 1);
  bool flg = true;
  for (int i = 1; i <= n; i++)
    if (!c[i]) flg = flg && dfs(e, c, i, i);
  if (!flg) {
    puts("0");
    return 0;
  }
  vector<int> cnt(2 * n + 1);
  for (int i = 1; i <= n; i++) cnt[c[i] + n]++;
  ll ans = 0;
  for (int i = 1; i <= n; i++) ans += n - cnt[c[i] + n] - e[i].size();
  printf("%lld\n", ans / 2);
  return 0;
}