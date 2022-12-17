#include <cstdio>
#include <iostream>
using namespace std;
const int buff = 3e5;
char s[buff];
int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", s);
  int flg = true;
  for (int i = 0; s[i]; i++) {
    if (s[i] == '"') flg = !flg;
    if (flg && s[i] == ',') s[i] = '.';
  }
  printf("%s\n", s);
  return 0;
}