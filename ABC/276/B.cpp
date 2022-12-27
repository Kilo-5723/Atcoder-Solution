#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
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
  for (int i = 1; i <= n; i++) {
    sort(e[i].begin(), e[i].end());
    printf("%lu", e[i].size());
    for (auto v : e[i]) printf(" %d", v);
    puts("");
  }
  return 0;
}