#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int v, a, b, c;
  scanf("%d%d%d%d", &v, &a, &b, &c);
  v %= (a + b + c);
  if (v < a)
    puts("F");
  else if (v < a + b)
    puts("M");
  else
    puts("T");
  return 0;
}