#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
// struct modint {
//   int n;
//   modint(int n) : n(n) {}
// };
// modint operator+(modint a, modint b) {
//   a.n += b.n;
//   if (a.n >= mod) a.n -= mod;
//   return a;
// }
// modint operator-(modint a, modint b) {
//   a.n -= b.n;
//   if (a.n < 0) a.n += mod;
//   return a;
// }
// modint operator*(modint a, modint b) { return (int)(1LL * a.n * b.n % mod); }
// void operator+=(modint &a, modint b) { a = a + b; }
// void operator-=(modint &a, modint b) { a = a - b; }
int main() {
  int n, k;
  ll c;
  scanf("%d%d%lld", &n, &k, &c);
  if (c == 1) {
    puts("1");
    return 0;
  }
  vector<ll> a(n, 0), b(n, 0);
  a[0] = 0;
  b[0] = c;
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    if (i - k >= 0) sum = (sum - a[i - k]) % mod;
    a[i] = (a[i] + sum) % mod;
    if (i - k + 1 >= 0) a[i] = (a[i] + a[i - k + 1] * (c - 2)) % mod;
    sum = (sum + a[i]) % mod;
    if (i + k - 1 < n) b[i + k - 1] = (b[i + k - 1] + a[i]) % mod;
    if (i + 1 < n) a[i + 1] = (a[i + 1] + b[i] * (c - 1)) % mod;
    if (i + 1 < n) b[i + 1] = (b[i + 1] + b[i]) % mod;
  }
  // for (auto v : a) printf("%d ", v);
  // puts("");
  // for (auto v : b) printf("%d ", v);
  // puts("");
  ll ans = 0;
  for (int i = 1; i < k; i++) ans += a[n - i];
  ans += b[n - 1];
  printf("%lld\n", (ans % mod + mod) % mod);
  return 0;
}