#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int inf = 1e9;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector dp(n + 1, vector<int>(m + 1, inf));
  dp[0][0] = 0;
  vector<int> cur(m + 1, inf);
  for (int i = 1; i <= n; i++) {
    int t;
    scanf("%d", &t);
    for (int j = t; j <= m; j++) dp[i][j] = min(dp[i][j], dp[i - 1][j - t]);
    for (int j = t; j <= m; j++) dp[i][j] = min(dp[i][j], cur[j - t] + 1);
    for (int j = 0; j <= m; j++) cur[j] = min(cur[j], dp[i - 1][j]);
  }
  for (int i = 1; i <= m; i++) {
    int ans = dp[n][i];
    for (int j = 0; j < n; j++) ans = min(ans, dp[j][i] + 1);
    printf("%d\n", ans > inf / 2 ? -1 : ans);
  }
  return 0;
}