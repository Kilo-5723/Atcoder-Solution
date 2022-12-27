#include <cstdio>
#include <iostream>
#include <map>
#include <set>
using namespace std;
int main() {
  int t, n;
  scanf("%d%d", &t, &n);
  map<int, set<int>> follow;
  while (n--) {
    int t, a, b;
    scanf("%d%d%d", &t, &a, &b);
    switch (t) {
      case 1:
        follow[a].insert(b);
        break;
      case 2:
        follow[a].erase(b);
        break;
      case 3:
        puts(follow[a].count(b) && follow[b].count(a) ? "Yes" : "No");
        break;
    }
  }
  return 0;
}