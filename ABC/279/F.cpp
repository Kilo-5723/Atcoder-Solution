#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int ff(vector<int> &f, int u) { return f[u] == u ? u : f[u] = ff(f, f[u]); }
int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  vector<int> f(2 * n + 1), v(2 * n + 1), xid(n + 1), bid(n + 1);
  for (int i = 1; i <= n; i++) {
    f[i * 2 - 1] = i * 2 - 1;
    f[i * 2] = i * 2 - 1;
    v[i * 2 - 1] = i;
    xid[i] = i * 2 - 1;
    bid[i] = i * 2;
  }
  while (q--) {
    int op, x, y;
    scanf("%d", &op);
    switch (op) {
      case 1:
        scanf("%d%d", &x, &y);
        f[ff(f, xid[y])] = ff(f, xid[x]);
        xid[y] = f.size();
        f.push_back(xid[y]);
        v.push_back(y);
        break;
      case 2:
        scanf("%d", &x);
        bid.push_back(f.size());
        f.push_back(xid[x]);
        v.push_back(0);
        break;
      case 3:
        int x;
        scanf("%d", &x);
        x = ff(f, bid[x]);
        printf("%d\n", v[x]);
        break;
    }
  }
  return 0;
}