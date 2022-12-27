#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int lim = 1e8;
ll f(vector<ll> &cf, ll n) {
  return n < lim ? cf[n] : f(cf, n / 2) + f(cf, n / 3);
}
int main() {
  vector<ll> cf(lim);
  cf[0] = 1;
  for (int i = 1; i < lim; i++) cf[i] = cf[i / 2] + cf[i / 3];
  ll n;
  scanf("%lld", &n);
  printf("%lld\n", f(cf, n));
  return 0;
}