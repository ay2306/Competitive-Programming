//https://codeforces.com/contest/682/problem/C
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
ll ans,arr[N],n,a,b,c;
vector<pair<ll,int>> g[N];
void dfs(int s = 1, ll mx = LLONG_MAX, ll mn = LLONG_MIN, ll lev = 0){
    if(lev > mx || lev < mn)return;
    printf("node = %d,  mx = %lld, lev = %lld\n",s,mx,lev);
    ans--,mx = min(mx,lev+abs(arr[s])),mn = max(mn,lev-abs(arr[s]));
    for(auto &i: g[s])dfs(i.second,mx,mn,lev+i.first);
}

int main(){
    scanf("%lld",&n);
    for(int i = 1; i <= n; ++i)scanf("%lld",arr+i);
    for(ll i = 2; i <= n; ++i){
        scanf("%lld%lld",&a,&b);
        g[a].emplace_back(b,i);
    }
    ans = n;
    dfs();
    return printf("%lld\n",ans),0;
}