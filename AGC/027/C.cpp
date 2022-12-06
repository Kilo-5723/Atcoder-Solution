#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int buff = 2e5 + 5;
char s[buff];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<vector<int>> e(2 * n + 1);
  vector<int> deg(2 * n + 1);
  scanf("%s", s + 1);
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    if (s[u] == s[v]) {
      e[u].push_back(v + n);
      e[v].push_back(u + n);
      deg[v + n]++;
      deg[u + n]++;
    } else {
      e[u + n].push_back(v);
      e[v + n].push_back(u);
      deg[v]++;
      deg[u]++;
    }
  }
  queue<int> que;
  for (int i = 1; i <= 2 * n; i++)
    if (!deg[i]) que.push(i);
  while (que.size()) {
    auto u = que.front();
    que.pop();
    for (auto v : e[u])
      if (!--deg[v]) que.push(v);
  }
  for (int i = 1; i <= 2 * n; i++)
    if (deg[i] > 0) {
      puts("Yes");
      return 0;
    }
  puts("No");
  return 0;
}