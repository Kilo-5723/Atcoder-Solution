#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
const int buff = 1e6;
char s[buff];
int main() {
  int n, m;
  scanf("%d%d", &m, &n);
  vector a(n, vector<bool>(m)), b(n, vector<bool>(m));
  multiset<vector<bool>> st;
  for (int i = 0; i < m; i++) {
    scanf("%s", s);
    for (int j = 0; j < n; j++) a[j][i] = s[j] == '#';
  }
  for (int i = 0; i < m; i++) {
    scanf("%s", s);
    for (int j = 0; j < n; j++) b[j][i] = s[j] == '#';
  }
  for (auto v : b) st.insert(v);
  bool flg = true;
  for (auto v : a) {
    if (st.find(v) == st.end()) {
      flg = false;
      break;
    }
    st.erase(st.find(v));
  }
  puts(flg ? "Yes" : "No");
  return 0;
}