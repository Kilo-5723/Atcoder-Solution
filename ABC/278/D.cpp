#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
int main() {
  int n;
  scanf("%d", &n);
  int x = 0;
  map<int, ll> a;
  for (int i = 0; i < n; i++) scanf("%lld", &a[i + 1]);
  int q;
  scanf("%d", &q);
  while (q--) {
    int t, p, q;
    scanf("%d", &t);
    switch (t) {
      case 1:
        scanf("%d", &p);
        a.clear();
        x = p;
        break;
      case 2:
        scanf("%d%d", &p, &q);
        if (!a.count(p)) a[p] = x;
        a[p] += q;
        break;
      case 3:
        scanf("%d", &p);
        if (!a.count(p)) a[p] = x;
        printf("%lld\n", a[p]);
        break;
    }
  }
  return 0;
}