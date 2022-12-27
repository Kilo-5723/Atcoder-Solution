#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const ll mod=998244353;
int main() {
  ll a,b,c,d,e,f;
  scanf("%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e,&f);
  a%=mod;b%=mod;c%=mod;d%=mod;e%=mod;f%=mod;
  ll ans=a*b%mod*c%mod-d*e%mod*f%mod;
  printf("%lld\n",(ans%mod+mod)%mod);
  return 0;
}