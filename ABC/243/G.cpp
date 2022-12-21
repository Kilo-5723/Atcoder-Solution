#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll lim = 1e5;
int main() {
  vector<ll> arr(lim), sum(lim);
  arr[1] = 1;
  arr[2] = 1;
  for (ll i = 2; i < lim; i++) {
    if (i * i < lim) arr[i * i] += arr[i];
    arr[i + 1] += arr[i];
  }
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    ll n;
    scanf("%lld", &n);
    ll m = sqrt(n);
    while (m * m <= n) m++;
    m--;
    ll ans = 0;
    for (ll i = 1; i * i <= m; i++) ans += (m - i * i + 1) * arr[i];
    printf("%lld\n", ans);
  }
  return 0;
}