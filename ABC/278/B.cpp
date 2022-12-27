#include <cstdio>
#include <iostream>
using namespace std;
bool check(int h, int m) {
  int a = h / 10, b = h % 10, c = m / 10, d = m % 10;
  int hh = a * 10 + c, mm = b * 10 + d;
  return hh < 24 && mm < 60;
}
int main() {
  int h, m;
  scanf("%d%d", &h, &m);
  while (!check(h, m)) {
    m++;
    if (m == 60) {
      h = (h + 1) % 24;
      m = 0;
    }
  }
  printf("%d %d\n", h, m);
  return 0;
}