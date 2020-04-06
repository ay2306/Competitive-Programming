//https://codeforces.com/contest/543/problem/B
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 3e3+10;
int n,m,a,b;
int d[N][N];
int vis[N],st[2],to[2],t[2];
vector<int> g[N];
void bfs(int s){
    queue<int> q;
    q.push(s);
    d[s][s] = 0;
    vis[s] = s;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int &i : g[u]){
            if(vis[i] == s)continue;
            q.push(i);
            vis[i] = s;
            d[s][i] = d[s][u] + 1;
        }
    }
    // printf("Node = %d: ",s);
    // for(int i = 1; i <= n; ++i)printf("%d ",d[s][i]);
    // printf("\n");
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 0; i < m; ++i){
        scanf("%d%d",&a,&b);
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    for(int i = 1; i <= n; ++i)bfs(i);
    int ans = INT_MAX;
    for(int i = 0; i < 2; ++i)cin >> st[i] >> to[i] >> t[i];
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            int c1 = min(d[st[0]][i]+d[i][j]+d[j][to[0]],d[j][st[0]]+d[i][j]+d[to[0]][i]);
            int c2 = min(d[st[1]][i]+d[i][j]+d[j][to[1]],d[j][st[1]]+d[i][j]+d[to[1]][i]);
            // int c2 = d[st[1]][i]+d[i][j]+d[j][to[1]];
            if(c1 <= t[0] && c2 <= t[1] && ans > (c1+c2-d[i][j])){
                // printf("i = %d, j = %d, c1 = %d, c2 = %d, d[i][j] = %d\n",i,j,c1,c2,d[i][j]);
                ans = c1+c2-d[i][j];
            }
        }
    }
    // direct paths
    int c1 = d[st[0]][to[0]] , c2 = d[st[1]][to[1]];
    if(c1 <= t[0] && c2 <= t[1] && ans > (c1+c2)){
        // printf("c1 = %d, c2 = %d\n",c1,c2);
        ans = c1+c2;
    }
    if(ans == INT_MAX)printf("-1");
    else printf("%d",m-ans);
    return 0;
}