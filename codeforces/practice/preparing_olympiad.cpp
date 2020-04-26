//https://codeforces.com/contest/550/problem/B
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,ans=0,l,r,x,a[20],mask,mn,mx,s;
    scanf("%d%d%d%d",&n,&l,&r,&x);
    for(int i = 0; i < n; ++i)scanf("%d",a+i);
    for(mask = 1; mask < (1 << n); ++mask){
        mn = (int)1e6, mx = 0 , s = 0;
        if(__builtin_popcount(mask) < 2)continue;
        for(int j = 0; j < n; ++j)if((mask >> j) & 1)mx = max(a[j],mx),mn = min(a[j],mn),s+=a[j];
        if(mx-mn >= x && s >= l && s <= r)ans++;
    }
    return printf("%d",ans),0;
}