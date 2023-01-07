#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int buff = 100;
void solve(int n) {
  if (!n) return;
  char s[buff];
  scanf("%s", s);
  solve(n - 1);
  printf("%s\n", s);
}
int main() {
  int n;
  scanf("%d", &n);
  solve(n);
  return 0;
}