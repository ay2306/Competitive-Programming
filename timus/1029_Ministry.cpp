#include<bits/stdc++.h>
#define PII pair<int,int>
using namespace std;

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    map<PII,vector<PII>> g;
    auto arr = vector<vector<int>> (n+1, vector<int> (m+1,0));
    auto vis = vector<vector<int>> (n+1, vector<int> (m+1,0));
    auto dis = vector<vector<int>> (n+1, vector<int> (m+1,INT_MAX));
    auto par = vector<vector<PII>> (n+1, vector<PII> (m+1,PII(-1,-1)));
    set<pair<int,PII>> q;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j)scanf("%d",&arr[i][j]);
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(i == 1)g[PII(0,0)].emplace_back(PII(i,j));
            if(i+1 <= n)g[PII(i,j)].emplace_back(PII(i+1,j));
            if(j+1 <= m)g[PII(i,j)].emplace_back(PII(i,j+1));
            if(j-1 > 0)g[PII(i,j)].emplace_back(PII(i,j-1));
        }
    }
    q.emplace(0,PII(0,0));
    dis[0][0] = 0;
    while(q.size()){
        int i,j;
        tie(i,j) = q.begin()->second;
        q.erase(q.begin());
        if(vis[i][j])continue;
        vis[i][j] = true;
        for(auto k: g[PII(i,j)]){
            int x,y;
            tie(x,y) = k;
            int w = arr[x][y];
            if(dis[x][y] > dis[i][j] + w){
                dis[x][y] = dis[i][j] + w;
                par[x][y] = PII(i,j);
                q.emplace(dis[x][y],k);
            }
        }
    }
    PII cur(n,-1);
    cur.second = min_element(dis[n].begin(),dis[n].end()) - dis[n].begin();
    vector<int> ans;
    while(cur.first > 0){
        ans.emplace_back(cur.second);
        cur = par[cur.first][cur.second];
    }
    reverse(ans.begin(),ans.end());
    for(int i: ans)printf("%d ",i);
    return 0;
}
// for(int i = 1; i <= n; ++i){
//     for(int j = 1; j <= m; ++j){
//         if(dis[i][j] != INT_MAX)printf("(dis = %3d, par = { %3d, %3d }) ",dis[i][j],par[i][j].first,par[i][j].second);
//         if(dis[i][j] == INT_MAX)printf("(dis = inf, par = { %3d, %3d }) ",par[i][j].first,par[i][j].second);
//     }
//     printf("\n");
// }
// printf("cur = %d %d\n",cur.first,cur.second);