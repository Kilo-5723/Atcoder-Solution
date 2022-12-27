#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (auto &v : a) v = n - v;
  next_permutation(a.begin(), a.end());
  for (auto &v : a) v = n - v;
  for (auto v : a) printf("%d ", v);
  puts("");
  return 0;
}