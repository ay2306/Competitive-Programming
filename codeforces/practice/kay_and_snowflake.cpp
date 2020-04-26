//https://codeforces.com/contest/685/problem/B
#include<bits/stdc++.h>
using namespace std;
const int N = 3e5+10;
int sub[N],centroid[N],parent[N];
int n,a,b,q;
vector<int> g[N];

void dfs(int s = 1){
    sub[s] = 1;
    for(int &i: g[s]){
        parent[i] = s;
        dfs(i);
        sub[s] += sub[i];
        if(sub[i] > sub[g[s][0]])swap(g[s][0],i);
    }
    if(g[s].size() == 0){centroid[s] = s;return;}
    centroid[s] = centroid[g[s][0]];
    while(centroid[s] != s){
        if(sub[s]-sub[centroid[s]] <= sub[s]/2)break;
        centroid[s] = parent[centroid[s]];
    }
}

int main(){
    scanf("%d%d",&n,&q);
    for(int i = 2; i <= n; ++i){
        scanf("%d",&a);
        g[a].emplace_back(i);
    }
    dfs();
    while(q--){
        scanf("%d",&a);
        printf("%d\n",centroid[a]);
    }
    return 0;
}