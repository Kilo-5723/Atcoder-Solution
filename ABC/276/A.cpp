#include <cstdio>
#include <iostream>
using namespace std;
const int buff = 1e5;
char s[buff];
int main() {
  scanf("%s", s);
  int p = -1;
  for (int i = 0; s[i]; i++)
    if (s[i] == 'a') p = i + 1;
  printf("%d\n", p);
  return 0;
}