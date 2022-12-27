#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int inf = 1e9;
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  vector e(2, vector<vector<int>>(n + 1));
  while (m--) {
    int u, v, a;
    scanf("%d%d%d", &u, &v, &a);
    e[a][u].push_back(v);
    e[a][v].push_back(u);
  }
  vector<bool> s(n + 1, false);
  while (k--) {
    int t;
    scanf("%d", &t);
    s[t] = true;
  }
  queue<pair<int, int>> que;
  vector dis(2, vector<int>(n + 1, inf));
  dis[1][1] = 0;
  que.push({1, 1});
  while (que.size()) {
    auto [a, u] = que.front();
    que.pop();
    for (auto v : e[a][u])
      if (dis[a][v] == inf) {
        dis[a][v] = dis[a][u] + 1;
        que.push({a, v});
      }
    if (s[u]) {
      dis[!a][u] = dis[a][u];
      a = !a;
      for (auto v : e[a][u])
        if (dis[a][v] == inf) {
          dis[a][v] = dis[a][u] + 1;
          que.push({a, v});
        }
    }
  }
  int ans = min(dis[0][n], dis[1][n]);
  printf("%d\n", ans < inf ? ans : -1);
  return 0;
}