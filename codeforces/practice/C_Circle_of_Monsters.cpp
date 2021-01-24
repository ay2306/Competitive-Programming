#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int t;
    scanf("%lld",&t);
    while(t--){
        int n,s,ans=LLONG_MAX;
        scanf("%lld",&n);
        vector<int> a(n),b(n),z(n);
        for(int i = 0; i < n; ++i)scanf("%lld%lld",&a[i],&b[i]);
        for(int i = 0; i < n; ++i)z[i] = max(0LL,a[i]-b[(i-1+n)%n]);
        s = accumulate(z.begin(),z.end(),0LL);
        for(int i = 0; i < n; ++i)ans = min(ans,a[i]+s-z[i]);
        printf("%lld\n",ans);
    }
    return 0;
}