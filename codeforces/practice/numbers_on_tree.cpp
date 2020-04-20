//https://codeforces.com/contest/1286/problem/B
// Approach idea: lollihunter
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 2e3+10;

int n,p,root,c[N],sub[N],ans[N];
vector<int> g[N],res[N];

void dfs(int s, int p = -1){
    for(int &i: g[s]){
        if(i == p)continue;
        dfs(i,s);
        sub[s]+=sub[i];
        for(auto &j: res[i])res[s].emplace_back(j);
    }
    if(c[s] > sub[s]){
        printf("NO\n");
        exit(0);
    }
    sub[s]++;
    res[s].insert(res[s].begin()+c[s],s);
}

int main(){
    scanf("%d",&n);
    for(int i = 1; i <= n; ++i){
        scanf("%d%d",&p,c+i);
        if(p != 0)g[p].emplace_back(i),g[i].emplace_back(p);
        else root = i;
    }
    dfs(root);
    printf("YES\n");
    for(int i = 0; i < res[root].size(); ++i)ans[res[root][i]]=i+1;
    for(int i = 1; i <= n; ++i)printf("%d ",ans[i]);
    return 0;
}