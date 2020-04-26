//https://codeforces.com/problemset/problem/486/D
#include<bits/stdc++.h>
using namespace std;
const int N = 2020, mod = 1e9+7;
int n,a[N],d,e,f,vis[N];
pair<int,int> arr[N];
vector<int> g[N];
long long dfs(int s, int p, int root){
    long long ans = 1;
    if((a[s] == a[root]  && s < root) || a[s] > a[root] || a[s] < a[root]-d)return 1;
    for(int &i : g[s]){
        if(i == p)continue;
        ans = ans*dfs(i,s,root)%mod;
    }
    return (ans+(s != root))%mod;
}

int main(){
    scanf("%d%d",&d,&n);
    for(int i = 1; i <= n; ++i){
        scanf("%d",a+i);
        arr[i] = make_pair(a[i],i);
    }
    for(int i = 1; i < n; ++i){
        scanf("%d%d",&e,&f);
        g[e].emplace_back(f);
        g[f].emplace_back(e);
    }
    sort(arr+1,arr+n+1);
    long long ans = 0;
    for(int i = 1; i <= n; ++i){
        ans = (ans+dfs(i,-1,i))%mod;
    }
    return printf("%lld",ans),0;
}