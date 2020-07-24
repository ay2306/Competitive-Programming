//https://codeforces.com/contest/862/problem/B
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+1;
vector<int> g[N];
int n,a,b,cnt[2];

void dfs(int s, int p, int c){
    cnt[c]++;
    for(int i: g[s])if(i != p)dfs(i,s,1-c);
}

int main(){
    scanf("%d",&n);
    for(int i = 1; i < n; ++i){
        scanf("%d%d",&a,&b);
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    dfs(1,-1,0);
    return printf("%lld",cnt[0]*1LL*cnt[1] - n + 1),0;
}