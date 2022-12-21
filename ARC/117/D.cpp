#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
pair<int, int> distant(int u, int f, int d, vector<vector<int>> &e) {
  pair<int, int> res = {d, u};
  for (auto v : e[u])
    if (v != f) res = max(res, distant(v, u, d + 1, e));
  return res;
}
bool init(int u, int f, int t, vector<vector<int>> &e) {
  if (u == t) return true;
  for (auto &v : e[u])
    if (v != f && init(v, u, t, e)) {
      swap(v, e[u].back());
      return true;
    }
  return false;
}
bool euler(int u, int f, int t, vector<vector<int>> &e, vector<int> &res) {
  res.push_back(u);
  if (u == t) return true;
  for (auto v : e[u])
    if (v != f) {
      if (euler(v, u, t, e, res)) return true;
      res.push_back(u);
    }
  return false;
}
int main() {
  int n;
  scanf("%d", &n);
  vector<vector<int>> e(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    e[u].push_back(v);
    e[v].push_back(u);
  }
  int s = distant(1, 1, 0, e).second;
  int t = distant(s, s, 0, e).second;
  init(s, s, t, e);
  vector<int> arr;
  euler(s, s, t, e, arr);
  vector<int> ans(n + 1);
  for (int i = 0; i < arr.size(); i++) ans[arr[i]] = i + 1;
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  return 0;
}