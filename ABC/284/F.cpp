#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
ll qpow(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
ll inv(ll n) { return qpow(n, mod - 2); }
const ll mul = 37, imul = inv(mul);
const int buff = 3e6;
char s[buff];
char t[buff];
vector<ll> get_pow(char s[]) {
  vector<ll> res = {1};
  for (int i = 0; s[i]; i++) res.push_back(res.back() * mul % mod);
  return res;
}
vector<ll> get_ipow(char s[]) {
  vector<ll> res = {1};
  for (int i = 0; s[i]; i++) res.push_back(res.back() * imul % mod);
  return res;
}
vector<ll> get_hash(char s[]) {
  vector<ll> res = {0};
  for (int i = 0; s[i]; i++)
    res.push_back((res.back() * mul + s[i] - 'a' + 1) % mod);
  return res;
}
int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", s);
  vector<ll> pow = get_pow(s);
  vector<ll> hashl = get_hash(s);
  reverse(s, s + 2 * n);
  vector<ll> hashr = get_hash(s);
  reverse(s, s + 2 * n);
  for (int i = 0; i <= n; i++) {
    ll hash1 =
        (hashl[i] * pow[n - i] + hashl[2 * n] - hashl[n + i] * pow[n - i]) %
        mod;
    ll hash2 = (hashr[2 * n - i] - hashr[n - i] * pow[n]) % mod;
    // cout << i << ' ' << hash1 << ' ' << hash2 << endl;
    if (!((hash1 - hash2) % mod)) {
      for (int j = 0; j < i; j++) putchar(s[j]);
      for (int j = i + n; j < 2 * n; j++) putchar(s[j]);
      puts("");
      printf("%d\n", i);
      return 0;
    }
  }
  puts("-1");
  return 0;
}