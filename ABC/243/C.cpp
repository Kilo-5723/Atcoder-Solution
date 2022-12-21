#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
const int buff = 2e5 + 5;
char s[buff];
bool check(vector<pair<int, int>> &arr) {
  sort(arr.begin(), arr.end());
  int p = 0, q = arr.size() - 1;
  while (p < arr.size() && s[arr[p].second] == 'L') p++;
  while (q >= 0 && s[arr[q].second] == 'R') q--;
  return q < p;
}
int main() {
  int n;
  scanf("%d", &n);
  map<int, vector<pair<int, int>>> pos;
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    pos[y].push_back({x, i});
  }
  scanf("%s", s);
  bool flg = true;
  for (auto &[val, arr] : pos) flg = flg && check(arr);
  puts(flg ? "No" : "Yes");
  return 0;
}