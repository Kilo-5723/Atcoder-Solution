#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
int dfs(int u, map<int, vector<int>> &e, set<int> &vis) {
  int res = u;
  if (vis.count(u)) return res;
  vis.insert(u);
  for (auto v : e[u]) res = max(res, dfs(v, e, vis));
  return res;
}
int main() {
  int n;
  scanf("%d", &n);
  map<int, vector<int>> e;
  while (n--) {
    int a, b;
    scanf("%d%d", &a, &b);
    e[a].push_back(b);
    e[b].push_back(a);
  }
  set<int> vis;
  printf("%d\n", dfs(1, e, vis));
  return 0;
}