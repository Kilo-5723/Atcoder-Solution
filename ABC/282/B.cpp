#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int buff = 1e5;
char s[buff];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    for (int j = 0; s[j]; j++)
      if (s[j] == 'o') a[i] |= 1 << j;
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) ans += (a[i] | a[j]) == (1 << m) - 1;
  printf("%d\n", ans);
  return 0;
}