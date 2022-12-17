#include <cstdio>
#include <cstring>
#include <iostream>Z
#include <vector>
using namespace std;
typedef long long ll;
ll mod;
vector<vector<vector<ll>>> modu(int k, int n) {
  vector<vector<vector<ll>>> res(k + 1,
                                 vector<vector<ll>>(n + 1, vector<ll>(n + 1)));
  return res;
}
void getsum(vector<vector<ll>> &dp, bool b1, bool b2) {
  int n = dp.size() - 1;
  if (b1)
    for (int i = n - 1; i >= 1; i--)
      for (int j = 1; j <= n; j++) dp[i][j] = (dp[i][j] + dp[i + 1][j]) % mod;
  else
    for (int i = 2; i <= n; i++)
      for (int j = 1; j <= n; j++) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
  if (b2)
    for (int j = n - 1; j >= 1; j--)
      for (int i = 1; i <= n; i++) dp[i][j] = (dp[i][j] + dp[i][j + 1]) % mod;
  else
    for (int j = 2; j <= n; j++)
      for (int i = 1; i <= n; i++) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
}
void addeq(vector<vector<ll>> &nxt, vector<vector<ll>> &dp, bool b1, bool b2) {
  for (int i = 1; i < nxt.size(); i++)
    for (int j = 1; j < nxt.size(); j++)
      nxt[i][j] = (nxt[i][j] + dp[i + b1][j + b2]) % mod;
}
void same(const vector<vector<ll>> &dp, vector<vector<ll>> &nxt, int n) {
  auto s1 = dp;
  getsum(s1, true, true);
  addeq(nxt, s1, true, true);
  auto s2 = dp;
  getsum(s2, false, false);
  addeq(nxt, s2, false, false);
}
void diff(const vector<vector<ll>> &dp, vector<vector<ll>> &nxt, int n) {
  auto s1 = dp;
  getsum(s1, true, false);
  addeq(nxt, s1, true, false);
  auto s2 = dp;
  getsum(s2, false, true);
  addeq(nxt, s2, false, true);
}
int main() {
  int n, k;
  scanf("%d%d%lld", &n, &k, &mod);
  auto dp = modu(k, n);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) dp[0][i][j] = 1;
  for (int i = n - 1; i >= 1; i--) {
    auto nxt = modu(k, i);
    for (int j = 0; j < k; j++) same(dp[j], nxt[j + 1], i);
    for (int j = 0; j <= k; j++) diff(dp[j], nxt[j], i);
    dp = nxt;
  }
  printf("%lld\n", dp[k][1][1]);
  return 0;
}