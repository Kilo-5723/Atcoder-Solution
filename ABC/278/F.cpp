#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
const int alpha = 26;
const int buff = 1e5;
char s[buff];
bool dfs(int las, vector<vector<int>> &cnt,
         map<pair<int, vector<vector<int>>>, bool> &dp) {
  if (dp[{las, cnt}]) return dp[{las, cnt}];
  bool flg = false;
  for (auto &arr : cnt)
    for (auto v : arr) flg = flg || v;
  if (!flg) return dp[{las, cnt}] = false;
  flg = false;
  for (int i = 0; i < 26; i++)
    if (cnt[las][i]) {
      cnt[las][i]--;
      flg = flg || !dfs(i, cnt, dp);
      cnt[las][i]++;
    }
  return dp[{las, cnt}] = flg;
}
int main() {
  int n;
  scanf("%d", &n);
  vector cnt(26, vector<int>(26, 0));
  while (n--) {
    scanf("%s", s);
    cnt[s[0] - 'a'][s[strlen(s) - 1] - 'a']++;
  }
  map<pair<int, vector<vector<int>>>, bool> dp;
  bool ans = false;
  for (int i = 0; i < alpha; i++) ans = ans || dfs(i, cnt, dp);
  puts(ans ? "First" : "Second");
  return 0;
}