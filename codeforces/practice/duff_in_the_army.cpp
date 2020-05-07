//https://codeforces.com/contest/587/problem/C
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10, LN = 17;

vector<int> mn[N][LN],g[N],city_peep[N];

int dp[N][20],lev[N],arr[N];
int n,m,a,b,q,k;

void unite(vector<int> &a, vector<int> &b, vector<int> &c){
    merge(a.begin(),a.end(),b.begin(),b.end(),back_inserter(c));
    while(c.size() > 10)c.pop_back();
}


void dfs(int s = 1, int p = 0){
    vector<int> a;
    unite(a,city_peep[s],mn[s][0]);
    dp[s][0] = p;
    for(int &i: g[s]){
        if(i == p)continue;
        lev[i] = lev[s] + 1;
        dfs(i,s);
    }
}


void pre(){
    for(int j = 1; j < LN; ++j){
        for(int i = 1; i <= n; ++i){
            dp[i][j] = dp[dp[i][j-1]][j-1];
            unite(mn[i][j-1],mn[dp[i][j-1]][j-1],mn[i][j]);
        }
    }
}

int lca(int a, int b){
    if(lev[a] > lev[b])swap(a,b);
    int diff = lev[b]-lev[a];
    for(int i = 0; i < LN; ++i)if((diff >> i)&1)b=dp[b][i];
    if(a==b)return a;
    for(int i = LN-1; i >= 0; i--)
        if(dp[a][i] != dp[b][i])
            a=dp[a][i],b=dp[b][i];
    return dp[a][0];
}

vector<int> result(int a, int b){
    vector<int> aux,c;
    int l = lca(a,b),d;
    d = lev[b] - lev[l];
    for(int i = 0; i < LN; ++i){
        if((d >> i)&1){
            unite(mn[b][i],c,aux);
            c = aux;
            b = dp[b][i];
            aux.clear();
        }
    }
    d = lev[a] - lev[l];
    for(int i = 0; i < LN; ++i){
        if((d >> i)&1){
            unite(mn[a][i],c,aux);
            a = dp[a][i];
            c = aux;
            aux.clear();
        }
    }
    unite(city_peep[l],c,aux);
    return aux;
}

int main(){
    scanf("%d%d%d",&n,&m,&q);
    for(int i = 1; i < n; ++i){
        scanf("%d%d",&a,&b);
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    for(int i = 1; i <= m; ++i){
        scanf("%d",&a);
        city_peep[a].emplace_back(i);
    }
    for(int i = 1; i <= n; ++i){
        sort(city_peep[i].begin(),city_peep[i].end());
        while(city_peep[i].size() > 10)city_peep[i].pop_back();
    }
    dfs();
    pre();
    #ifdef _all_parents
        for(int i = 1; i <= n; ++i){
            printf("Node = %d\n",i);
            for(int j = 0; j < 3; ++j){
                printf("%d - th parent = ",j+1);
                for(auto &p: mn[i][j])printf("%d ",p);
                printf("\n");
            }
        }
    #endif
    while(q--){
        scanf("%d%d%d",&a,&b,&k);
        vector<int> res = result(a,b);
        printf("%d ",min(k,(int)res.size()));
        for(int i = 0; i < k && i < (int)res.size(); ++i)printf("%d ",res[i]);
        printf("\n");
    }
    return 0;
}


