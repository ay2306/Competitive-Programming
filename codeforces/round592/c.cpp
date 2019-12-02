#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll gcdExtended(ll a, ll b, ll &x, ll &y)
{
    if (a == 0)
    {
        x = 0, y = 1;
        return b;
    }

    ll x1, y1; // To store results of recursive call
    ll gcd = gcdExtended(b%a, a, x1, y1);
    x = y1 - (b/a) * x1;
    y = x1;

    return gcd;
}

ll modInverse(ll a, ll m)
{
    ll x, y;
    ll g = gcdExtended(a, m, x, y);
    if (g != 1)
        return -1;
    ll res = (x%m + m) % m;
    return res;
}


int main(){
   ll n,p,w,d,y=0,x,z,ymw,g;
   scanf("%lld %lld %lld %lld",&n,&p,&w,&d);
   g = __gcd(w,d);
   if(p % g){
      printf("-1");
      return 0;
   }

   ymw = p % w;
   // while((y * d)%w != ymw)y++;
   y = modInverse(d/g,w/g) * ymw;
   x = (p - y*d)/w;
   z = n - (x+y);
   if(x+y > n || x < 0 || y < 0){
      printf("-1");
   }else{
      printf("%lld %lld %lld",x,y,z);
   }
   return 0;
}