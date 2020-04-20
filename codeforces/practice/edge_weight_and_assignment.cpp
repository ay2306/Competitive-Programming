//https://codeforces.com/contest/1338/problem/B
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 1e5+10;
vector<int> g[N];
int n,a,b,lev[N],leaves,edges,leaf_parent,mn=1;

int dfs(int s = 1, int p = 0){
    int l = (int)g[p].size()==1;
    for(int &i : g[s]){
        lev[i]=lev[s]+1;
        if(i == p)continue;
        l+=dfs(i,s);
    }
    leaves+=((int)g[s].size()==1);
    if(l)leaf_parent++;
    if((int)g[s].size() == 1 && lev[s] % 2)mn=3;
    return ((int)g[s].size()==1);
}

int main(){
    scanf("%d",&n);
    for(int i = 1; i < n; ++i){
        scanf("%d%d",&a,&b);
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    for(int i = 1; i <= n; ++i){
        if((int)g[i].size()==1){
            dfs(i);
            break;
        }
    }
    printf("%d %d",mn,n-1+leaf_parent-leaves);
    return 0;
}