//https://codeforces.com/problemset/problem/208/E
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
const int LN = 17;
int sub[N],anc[N][LN],lev[N],ans[N];
vector<int> g[N],v[N];
//p,index
vector<pair<int,int>> queries[N];
int n,q,a,b;
void dfs(int s = 1, int p = 0){
    sub[s] = 1;
    for(int &i: g[s]){
        anc[i][0] = s;
        lev[i] = lev[s]+1;
        dfs(i,s);
        if(sub[i] > sub[g[s][0]])swap(g[s][0],i);
    }

}

void dsu(int s = 1){
    if(g[s].size() == 0)return;
    dsu(g[s][0]);
    swap(v[s],v[g[s][0]]);
    for(int &i: g[s]){
        if(i == g[s][0])continue;
        dsu(i);
        for(int j = 0; j < v[i].size(); ++j){
            if(j == v[s].size())v[s].emplace_back(v[i][j]);
            else v[s][j]+=v[i][j];
        }
    }
    v[s].insert(v[s].begin(),1);
    for(auto &i: queries[s])if(i.first < v[s].size())ans[i.second]=v[s][i.first]-1;
}

void pre(){
    for(int j = 1; j < LN; ++j){
        for(int i = 1; i <= n; ++i)anc[i][j] = anc[anc[i][j-1]][j-1];
    }
}

int kth_parent(int a,int k){
    for(int i = 0; i < LN; ++i)if((k>>i)&1)a=anc[a][i];
    return a;
}

int main(){
    vector<int> ind;
    scanf("%d",&n);
    for(int i = 1; i <= n; ++i){
        v[i].emplace_back(1);
        scanf("%d",&a);
        if(a)g[a].emplace_back(i);
        else ind.emplace_back(i);
    }
    for(auto &i: ind)dfs(i);
    pre();
    scanf("%d",&q);
    for(int i = 0; i < q; ++i){
        scanf("%d%d",&a,&b);
        queries[kth_parent(a,b)].emplace_back(b,i);
    }
    for(auto &i: ind)dsu(i);
    for(int i = 0; i < q; ++i)printf("%d ",ans[i]);
    return 0;
}