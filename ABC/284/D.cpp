#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
ll _sqrt(ll n) {
  ll m = sqrt(n);
  while (m * m > n) m--;
  while (m * m <= n) m++;
  m--;
  return m;
}
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    ll n;
    scanf("%lld", &n);
    ll p = 2, q;
    while (n % p) p++;
    if (n / p % p) {
      q = p;
      p = _sqrt(n / q);
    } else {
      q = n / p / p;
    }
    printf("%lld %lld\n", p, q);
  }
  return 0;
}