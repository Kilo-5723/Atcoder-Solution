#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int ff(vector<int> &f, int u) { return f[u] == u ? u : f[u] = ff(f, f[u]); }
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<int> f(n + 1);
  for (int i = 1; i <= n; i++) f[i] = i;
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    u = ff(f, u);
    v = ff(f, v);
    f[u] = v;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) ans += f[i] == i;
  printf("%d\n", ans);
  return 0;
}