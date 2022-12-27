#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
ll qpow(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
ll inv(ll n) { return qpow(n, mod - 2); }
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  vector<ll> a(n + 1);
  a[0] = 1;
  ll m_1 = inv(m);
  while (k--) {
    vector<ll> next(n + 1);
    next[n] = a[n];
    for (int i = 0; i < n; i++) {
      for (int j = 1; j <= m; j++) {
        int t = j, p = i;
        while (t && p < n) {
          p++;
          t--;
        }
        while (t) {
          p--;
          t--;
        }
        next[p] += a[i] * m_1 % mod;
      }
    }
    a = next;
    for (auto &v : a) v %= mod;
  }
  printf("%lld\n", a.back());
  return 0;
}