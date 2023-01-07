#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll mod;
ll qpow(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
ll dfs(ll n, ll p) {
  if (n == 1) return 0;
  return (qpow(n - 1, n) * p + (n - 1) * dfs(n - 1, p + 1)) % mod;
}
int main() {
  int n;
  scanf("%d%lld", &n, &mod);
  ll ans = 0;
  ll mul = 1;
  for (int i = 1; i <= n; i++) {
    ans = ans + mul * (1LL * i * (i + 1) / 2 % mod) % mod *
                    qpow(n - i, n - i + 1) % mod;
    mul = mul * (n - i) % mod;
  }
  ans = printf("%lld\n", n * ans % mod);
  return 0;
}