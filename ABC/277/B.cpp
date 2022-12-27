#include <cstdio>
#include <iostream>
#include <set>
using namespace std;
const int buff = 1e5 + 5;
const char first[] = "HDCS", second[] = "A23456789TJQK";
char s[buff];
bool check(char s[]) {
  bool flg = false;
  for (int i = 0; first[i]; i++) flg = flg || s[0] == first[i];
  if (!flg) return false;
  flg = false;
  for (int i = 0; second[i]; i++) flg = flg || s[1] == second[i];
  if (!flg) return false;
  return true;
}
int main() {
  int n;
  scanf("%d", &n);
  set<string> st;
  bool flg = true;
  while (n--) {
    scanf("%s", s);
    flg = flg && check(s) && !st.count(s);
    st.insert(s);
  }
  puts(flg ? "Yes" : "No");
  return 0;
}