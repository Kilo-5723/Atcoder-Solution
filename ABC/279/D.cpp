#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
typedef long double ld;
ld inf = 1e36;
ld f(ld x, ld a, ld b) { return a / sqrt(x) + b * x - b; }
int main() {
  ll a, b;
  scanf("%lld%lld", &a, &b);
  ll l = 1, r = 1e18;
  while (r - l > 10) {
    ll m1 = (l + r) / 2, m2 = (m1 + r) / 2;
    if (f(m1, a, b) < f(m2, a, b))
      r = m2;
    else
      l = m1;
  }
  ld ans = inf;
  for (ll i = l; i <= r; i++) ans = min(ans, f(i, a, b));
  printf("%.12f\n", (double)ans);
  return 0;
}