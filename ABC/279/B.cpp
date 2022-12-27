#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int buff = 1e5;
char s[buff], t[buff];
bool check(char s[], char t[]) {
  for (int i = 0; t[i]; i++)
    if (s[i] != t[i]) return false;
  return true;
}
int main() {
  scanf("%s", s);
  scanf("%s", t);
  int n = strlen(s), m = strlen(t);
  bool flg = false;
  for (int i = 0; i + m <= n; i++) flg = flg || check(s + i, t);
  puts(flg ? "Yes" : "No");
  return 0;
}