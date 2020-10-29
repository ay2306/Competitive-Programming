#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int t;
    scanf("%lld",&t);
    while(t--){
        int n;
        scanf("%lld",&n);
        int mx = LLONG_MIN,a,ans = 0;
        while(n--){
            scanf("%lld",&a);
            if(a>=mx)mx=a;
            else ans=max(ans,(int)log2(mx-a)+1);
        }
        printf("%lld\n",ans);
    }
    return 0;
}