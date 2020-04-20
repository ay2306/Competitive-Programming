//https://codeforces.com/contest/1037/problem/D
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
vector<int> g[N];
int n,a,b,occ[N],parent[N],cur=0,prv=0;
int main(){
    scanf("%d",&n);
    for(int i = 1; i < n; ++i){
        scanf("%d%d",&a,&b);
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    scanf("%d",&a);
    if(a != 1)return printf("No\n"),0;
    for(int &i: g[a])occ[i]=0,parent[a] = 1;
    for(int i = 2; i <= n; ++i){
        scanf("%d",&a);
        if(++cur > 0 && occ[a] < prv)return printf("No\n"),0;
        for(int &j : g[a])if(parent[a] != j)occ[j]=cur,parent[j]=a;
        prv=occ[a];
    }
    printf("Yes\n");
    return 0;
}