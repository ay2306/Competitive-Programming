#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n,ans=0;
    scanf("%lld",&n);
    vector<int> a(n+1),q(n),par(n+1),sum(n+1),del(n+1,1),res;
    for(int i = 1; i <= n; ++i)scanf("%lld",&a[i]);
    for(int i = 0; i < n; ++i)scanf("%lld",&q[i]);
    for(int i = 1; i <= n; ++i)sum[i] = a[i];
    iota(par.begin(),par.end(),0);
    function<int(int)> findParent = [&](int x)->int{
        if(x != par[x]) par[x] = findParent(par[x]);
        return par[x];
    };
    auto join = [&](int a, int b){
        a = findParent(a), b = findParent(b);
        if(a == b)return;
        sum[b] += sum[a];
        par[a] = b;
    };
    while(q.size()){
        res.emplace_back(ans);
        int i = q.back();
        del[i] = 0;
        if(i-1 > 0 && !del[i-1])join(i-1,i);
        if(i+1 <= n && !del[i+1])join(i+1,i);
        ans = max(ans,sum[findParent(i)]);
        q.pop_back();
    }
    while(res.size()){
        printf("%lld\n",res.back());
        res.pop_back();
    }
    return 0;
}