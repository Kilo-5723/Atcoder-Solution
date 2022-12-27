#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  int g = 0;
  for (auto v : a) g = gcd(g, v);
  int ans = 0;
  for (auto v : a) {
    v /= g;
    while (!(v % 2)) {
      v /= 2;
      ans++;
    }
    while (!(v % 3)) {
      v /= 3;
      ans++;
    }
    if (v != 1) {
      puts("-1");
      return 0;
    }
  }
  printf("%d\n", ans);
  return 0;
}