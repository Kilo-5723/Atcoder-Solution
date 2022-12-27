#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  vector<int> a(n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) printf("%d ", i + k < n ? a[i + k] : 0);
  puts("");
  return 0;
}