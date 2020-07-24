#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int t;
    scanf("%lld",&t);
    while(t--){
        int l,r,m,a,b,c,rem;
        scanf("%lld%lld%lld",&l,&r,&m);
        for(a = l; a <= r; ++a){
            rem = m%a;
            b = r, c = r - rem;
            if(c >= l && m/a)break;
            rem = a - rem;
            b = l, c = l + rem;
            if(c <= r)break;
        }
        printf("%lld %lld %lld\n",a,b,c);
    }
    return 0;
}