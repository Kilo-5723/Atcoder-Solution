#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> log2(n + 1);
  log2[1] = 0;
  for (int i = 2; i <= n; i++) log2[i] = log2[i >> 1] + 1;
  map<pair<int, int>, int> id;
  int m = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; i + j - 1 <= n; j <<= 1) id[{i, i + j - 1}] = ++m;
  cout << id.size() << endl;
  for (auto [pr, val] : id) cout << pr.first << ' ' << pr.second << endl;
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    int k = 1 << log2[r - l + 1];
    cout << id[{l, l + k - 1}] << ' ' << id[{r - k + 1, r}] << endl;
  }
  return 0;
}