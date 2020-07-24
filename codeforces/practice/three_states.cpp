#include<bits/stdc++.h>
using namespace std;
const int N = 1010, inf = 1e8;
char a[N][N];
int dp[4][N][N],n,m,vis[N][N];
vector<pair<int,int>> g = {{0,1},{0,-1},{1,0},{-1,0}};

bool valid(int i, int j){
    return i > 0 && i <= n && j > 0 && j <= m && a[i][j] != '#' && !vis[i][j];
}

void bfs(char c){
    memset(vis,0,sizeof(vis));
    int I = c-'0';
    deque<pair<int,int>> q;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(a[i][j] == c){
                q.emplace_back(i,j);
                dp[I][i][j] = 0;
            }
        }
    }
    while(q.size()){
        auto u = q.front();
        q.pop_front();
        int i,j;
        tie(i,j) = u;
        if(vis[i][j])continue;
        vis[i][j] = 1;
        for(auto [x,y]: g){
            x+=i,y+=j;
            if(valid(x,y) && dp[I][x][y] == inf){
                q.emplace_back(x,y);
                dp[I][x][y] = dp[I][i][j] + 1;
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> a[i][j];

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            a[i][j]-=isdigit(a[i][j]);
   
    fill(dp[0][0],dp[3][N-1]+N,inf);
    bfs('1'-1);
    bfs('2'-1);
    bfs('3'-1);
    int ans = inf;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            int res = 1;
            for(int k = 0; k < 3; ++k){
                res+=max(0,dp[k][i][j]-1);
            }
            ans = min(res,ans);
        }
    }
    for(int k = 0; k < 3; ++k){
        int d1 = inf, d2 = inf;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                if(a[i][j]-'0' != k)continue;
                d1 = min(d1,dp[(k+1)%3][i][j]);
                d2 = min(d2,dp[(k+2)%3][i][j]);
            }
        }
        ans = min(ans,d1+d2-2);
    }
    
 
    if(ans > m*n)ans = -1;
    cout << ans << "\n";
    return 0;
}