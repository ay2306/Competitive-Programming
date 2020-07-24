#include<bits/stdc++.h>
using namespace std;
signed main(){
    long long n,t;
    scanf("%lld",&t);
    while(t--){
        long long ans = 0, mx = 0, s[2] = {0}, sum = 0, mn[2] = {LLONG_MAX/1234,0};
        scanf("%lld",&n);
        vector<long long> a(n);
        for(long long &i: a)scanf("%lld",&i);
        for(long long i = 0; i < n; a[i]=-a[i],i+=2)ans+=a[i];
        for(long long i = 0; i < n; i++){
            sum+=a[i];
            s[i&1] = max(s[i&1],sum-mn[i&1]);
            mn[i&1] = min(sum,mn[i&1]);
        }
        printf("%lld\n",ans+max(s[0],s[1]));
    }
    return 0;
}