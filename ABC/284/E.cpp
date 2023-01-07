#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int lim = 1e6;
int dfs(int u, vector<bool>& vis, const vector<vector<int>>& e, int lim) {
  vis[u] = true;
  if (!lim) return 0;
  lim--;
  for (auto v : e[u])
    if (!vis[v]) lim = dfs(v, vis, e, lim);
  vis[u] = false;
  return lim;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<vector<int>> e(n + 1);
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    e[u].push_back(v);
    e[v].push_back(u);
  }
  vector<bool> vis(n + 1);
  printf("%d\n", lim - dfs(1, vis, e, lim));
  return 0;
}