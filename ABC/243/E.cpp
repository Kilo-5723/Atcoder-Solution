#include <cstdio>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<tuple<int, int, int>> ed;
  vector<vector<ll>> dis(n, vector<ll>(n, inf));
  vector<vector<ll>> mds(n, vector<ll>(n, inf));
  while (m--) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    u--;
    v--;
    dis[u][v] = dis[v][u] = w;
    ed.push_back({u, v, w});
  }
  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (k != i && k != j) mds[i][j] = min(mds[i][j], dis[i][k] + dis[k][j]);
  int ans = 0;
  for (auto [u, v, w] : ed) ans += mds[u][v] <= w;
  printf("%d\n", ans);
  return 0;
}