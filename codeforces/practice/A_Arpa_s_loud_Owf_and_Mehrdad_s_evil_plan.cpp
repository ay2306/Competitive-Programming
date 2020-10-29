#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n, ans = 1;
    scanf("%lld",&n);
    vector<int> a(n),vis(n);
    for(int &i: a)scanf("%lld",&i);
    for(int &i: a)i--;
    for(int i = 0; i < n; ++i){
        if(vis[i])continue;
        int cur = i, cyc=0;
        while(!vis[cur]){
            cyc++;
            vis[cur] = 1;
            cur = a[cur];
        }
        if(cur != i)return printf("-1"),0;
        cur = (cyc % 2 ? cyc : cyc/2);
        ans = ans/__gcd(ans,cur)*cur;
    }
    if(ans == INT_MAX)ans = -1;
    printf("%lld",ans);
    return 0;
}