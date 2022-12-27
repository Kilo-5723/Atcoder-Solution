#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int n, x;
  scanf("%d%d", &n, &x);
  for (int i = 1; i <= n; i++) {
    int t;
    scanf("%d", &t);
    if (t == x) printf("%d\n", i);
  }
  return 0;
}