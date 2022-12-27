#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<int> b(n + 1);
  for (int i = 1; i <= n; i++) b[i] = i;
  auto p = b;
  vector<int> a(m);
  for (int i = 0; i < m; i++) scanf("%d", &a[i]);
  vector<pair<int, int>> que(m);
  for (int i = 0; i < m; i++) {
    swap(p[b[a[i]]], p[b[a[i] + 1]]);
    swap(b[a[i]], b[a[i] + 1]);
    que[i] = {b[a[i]], b[a[i] + 1]};
    if (que[i].first > que[i].second) swap(que[i].first, que[i].second);
  }
  for (int i = 0; i < m; i++) {
    if (que[i].first == 1)
      printf("%d\n", p[que[i].second]);
    else
      printf("%d\n", p[1]);
  }
  return 0;
}