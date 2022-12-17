#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
struct edge {
  int u, v;
  ll w;
};
ll qpow(ll a, ll b, ll m) {
  ll res = 1;
  while (b) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
int ff(vector<int> &f, int u) { return u == f[u] ? u : ff(f, f[u]); }
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<ll> a(n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  vector<edge> e;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      e.push_back({i, j, (qpow(a[i], a[j], m) + qpow(a[j], a[i], m)) % m});
  sort(e.begin(), e.end(), [](auto a, auto b) { return a.w > b.w; });
  vector<int> f(n);
  for (int i = 0; i < n; i++) f[i] = i;
  ll ans = 0;
  for (auto [u, v, w] : e) {
    u = ff(f, u);
    v = ff(f, v);
    if (u == v) continue;
    f[u] = v;
    ans += w;
  }
  printf("%lld\n", ans);
  return 0;
}