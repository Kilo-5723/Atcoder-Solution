#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    int ans = 0;
    while (n--) {
      int t;
      scanf("%d", &t);
      ans += t & 1;
    }
    printf("%d\n", ans);
  }
  return 0;
}