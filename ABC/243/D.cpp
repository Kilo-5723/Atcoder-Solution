#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int buff = 1e6 + 5;
char s[buff];
int main() {
  int n;
  ll x;
  scanf("%d%lld", &n, &x);
  vector<int> a;
  while (x > 1) {
    a.push_back(x & 1);
    x >>= 1;
  }
  reverse(a.begin(), a.end());
  scanf("%s", s);
  for (int i = 0; s[i]; i++) switch (s[i]) {
      case 'U':
        a.pop_back();
        break;
      case 'L':
        a.push_back(0);
        break;
      case 'R':
        a.push_back(1);
        break;
    }
  ll ans = 1;
  for (auto v : a) ans = ans * 2 + v;
  printf("%lld\n", ans);
  return 0;
}