#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;
int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) scanf("%d", &b[i]);
  int same = 0;
  ll sum = 0;
  map<int, int> cnt;
  for (int i = 0; i < n; i++) cnt[b[i]]++;
  for (int i = 0; i < n; i++) {
    same += a[i] == b[i];
    cnt[b[i]]--;
    sum += cnt[a[i]];
    cnt[b[i]]++;
  }
  printf("%d\n", same);
  printf("%lld\n", sum);
  return 0;
}