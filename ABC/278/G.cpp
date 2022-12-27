#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
pair<int, int> read() {
  int x, y;
  cin >> x >> y;
  return {x, y};
}
void submit(pair<int, int> pr) { cout << pr.first << ' ' << pr.second << endl; }
void go(vector<pair<int, int>> &game, pair<int, int> pr) {
  for (int i = 0; i < game.size(); i++) {
    int l1 = game[i].first, r1 = l1 + game[i].second - 1;
    int l2 = pr.first, r2 = l2 + pr.second - 1;
    if (l1 <= l2 && r2 <= r1) {
      game.erase(game.begin() + i);
      if (l1 < l2) game.push_back({l1, l2 - l1});
      if (r2 < r1) game.push_back({r2 + 1, r1 - r2});
      return;
    }
  }
}
void work(vector<pair<int, int>> &game, vector<int> &sg,
          vector<vector<int>> &next, int k) {
  int sum = 0;
  for (auto [l, n] : game) sum ^= sg[n];
  for (auto [l, n] : game)
    if ((sg[n] ^ sum) < sg[n]) {
      int j = next[n][sg[n] ^ sum];
      pair<int, int> pr = {l + j, k};
      submit(pr);
      go(game, pr);
      break;
    }
}
int main() {
  int n, l, r;
  cin >> n >> l >> r;
  if (l != r) {
    cout << "First" << endl;
    if (n - l & 1) l++;
    submit({(n - l) / 2 + 1, l});
    while (true) {
      auto pr = read();
      if (!pr.first) break;
      if (pr.first <= n / 2)
        pr.first += l + (n - l) / 2;
      else
        pr.first -= l + (n - l) / 2;
      submit(pr);
    }
    return 0;
  }
  vector<int> sg(n + 1);
  vector<vector<int>> next(n + 1);
  for (int i = 0; i <= n; i++) {
    set<int> st;
    next[i].resize(i + 2);
    for (int j = 0; j + l <= i; j++) {
      auto t = sg[j] ^ sg[i - l - j];
      st.insert(t);
      if (t < next[i].size()) next[i][t] = j;
    }
    while (st.count(sg[i])) sg[i]++;
    next[i].resize(sg[i]);
  }
  vector<pair<int, int>> game = {{1, n}};
  // for (int i=0;i<n;i++) cout<<sg[i]<<' ';
  // cout<<endl;
  if (sg[n]) {
    cout << "First" << endl;
    work(game, sg, next, l);
  } else {
    cout << "Second" << endl;
  }
  while (true) {
    auto pr = read();
    if (!pr.first) break;
    // for (auto [u, v] : game) cout << u << ' ' << v << endl;
    go(game, pr);
    // for (auto [u, v] : game) cout << u << ' ' << v << endl;
    work(game, sg, next, l);
  }
  return 0;
}