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
vector<vector<ll>> comb;
ll solve(int n, int m, int k, vector<ll> &a, vector<vector<vector<ll>>> &dp) {
  if (~dp[n][m][k]) return dp[n][m][k];
  if (m > k || m > n) return 0;
  if (!m) return !k;
  ll res = 0;
  ll sum = 0;
  for (int i = 1; i <= n; i++) sum += a[i];
  for (int i = 0; i <= k; i++)
    res += comb[k][i] * qpow(a[n], i) % mod * qpow(sum - a[n], k - i) % mod *
           qpow(inv(sum), k) % mod * solve(n - 1, m - (i > 0), k - i, a, dp) %
           mod;
  return dp[n][m][k] = res % mod;
}
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  comb.assign(k + 1, vector<ll>(k + 1, 0));
  for (int i = 0; i <= k; i++) comb[i][0] = comb[i][i] = 1;
  for (int i = 0; i <= k; i++)
    for (int j = 1; j < i; j++)
      comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
  vector<vector<vector<ll>>> dp(
      n + 1, vector<vector<ll>>(m + 1, vector<ll>(k + 1, -1)));
  vector<ll> a(n + 1);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  printf("%lld\n", solve(n, m, k, a, dp));
  return 0;
}