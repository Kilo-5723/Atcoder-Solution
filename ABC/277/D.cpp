#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
ll dfs(int k, map<int, ll> &dp, map<int, ll> &sum, int m) {
  if (dp.count(k)) return dp[k];
  if (!sum.count((k + 1) % m)) return sum[k];
  return dp[k] = sum[k] + dfs((k + 1) % m, dp, sum, m);
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  map<int, ll> sum;
  for (int i = 0; i < n; i++) {
    int t;
    scanf("%d", &t);
    sum[t] += t;
  }
  if (sum.size() == m) {
    puts("0");
    return 0;
  }
  ll tot = 0;
  for (auto [k, v] : sum) tot += v;
  ll ans = 0;
  map<int, ll> dp;
  for (auto [k, v] : sum) ans = max(ans, dfs(k, dp, sum, m));
  printf("%lld\n", tot - ans);
  return 0;
}