#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  int p = 0;
  for (int i = 1; i < n; i++)
    if (a[i] > a[p]) p = i;
  printf("%d\n", p + 1);
  return 0;
}