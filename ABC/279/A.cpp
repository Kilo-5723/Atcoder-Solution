#include <cstdio>
#include <iostream>
using namespace std;
const int buff = 1e5;
char s[buff];
int main() {
  scanf("%s", s);
  int ans = 0;
  for (int i = 0; s[i]; i++) ans += (s[i] == 'w') + 1;
  printf("%d\n", ans);
  return 0;
}