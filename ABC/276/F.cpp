#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int mod = 998244353;
struct modint {
  int n;
  modint(int n) : n(n) {}
};
modint operator+(modint a, modint b) {
  a.n += b.n;
  if (a.n >= mod) a.n -= mod;
  return a;
}
modint operator-(modint a, modint b) {
  a.n -= b.n;
  if (a.n < 0) a.n += mod;
  return a;
}
modint operator*(modint a, modint b) { return 1ll * a.n * b.n % mod; }
void operator+=(modint &a, modint b) { a = a + b; }
void operator-=(modint &a, modint b) { a = a - b; }
void operator*=(modint &a, modint b) { a = a * b; }
modint qpow(modint a, int b) {
  modint res = 1;
  while (b) {
    if (b & 1) res *= a;
    a *= a;
    b >>= 1;
  }
  return res;
}
modint inv(modint n) { return qpow(n, mod - 2); }
int lowbit(int n) { return n & -n; }
void add(vector<modint> &a, int p, modint v) {
  for (int i = p; i < a.size(); i += lowbit(i)) a[i] += v;
}
modint query(vector<modint> &a, int p) {
  modint res = 0;
  for (int i = p; i; i -= lowbit(i)) res += a[i];
  return res;
}
int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  vector<int> ord(n);
  for (int i = 0; i < n; i++) ord[i] = i;
  sort(ord.begin(), ord.end(), [&](int i, int j) { return a[i] < a[j]; });
  vector<int> p(n);
  for (int i = 0; i < n; i++) p[ord[i]] = i + 1;
  vector<modint> arr(n + 1, 0), brr(n + 1, 0);
  modint ans = 0;
  for (int i = 0; i < n; i++) {
    ans += (query(brr, p[i]) * 2 + 1) * a[i];
    ans += (query(arr, n) - query(arr, p[i])) * 2;
    add(brr, p[i], 1);
    add(arr, p[i], a[i]);
    printf("%d\n", (ans * inv(1ll * (i + 1) * (i + 1) % mod)).n);
  }
  return 0;
}