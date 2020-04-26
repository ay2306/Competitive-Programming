//https://codeforces.com/contest/877/problem/D
#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
string s[N];
int n,m,k,j,X1,X2,Y1,Y2,d,dist;
int vis[N][N][4],dp[N][N][4];
int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};

bool valid(int i, int j){
    return i >= 0 && i < n && j >= 0 && j < m && s[i][j] != '#';
}

void bfs(int x, int y){
    deque<pair<pair<int,int>,pair<int,int>>> q;
    for(int j = 0; j < 4; ++j)dp[x][y][j] = 1, q.push_front({{x,y},{j,0}});
    while(q.size()){
        pair<pair<int,int>,pair<int,int>> u = q.front();
        q.pop_front();
        tie(x,y) = u.first;
        tie(d,dist) = u.second;
        if(vis[x][y][d])continue;
        vis[x][y][d] = 1;
        for(int dir = 0; dir < 4; ++dir){
            int i = x+dx[dir], j = y+dy[dir];
            if(!valid(i,j))continue;
            if(dir == d && dist < k && dp[i][j][dir] > dp[x][y][dir]){
                q.push_front({{i,j},{dir,dist+1}});
                dp[i][j][dir] = dp[x][y][dir];
            }else if(dp[i][j][dir] > dp[x][y][d]+1){
                q.push_back({{i,j},{dir,1}});
                dp[i][j][dir] = dp[x][y][d]+1;
            }
        }
    }
}

int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < n; ++i)cin >> s[i];
    cin >> X1 >> Y1 >> X2 >> Y2;
    X1--,Y1--,X2--,Y2--;
    if(X1 == X2 && Y1 == Y2)return cout << 0 , 0;
    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            for(int dir = 0; dir < 4; ++dir)
                dp[i][j][dir] = (int)1e9;
    bfs(X1,Y1);    
    int ans  = *min_element(dp[X2][Y2],dp[X2][Y2]+4);
    if(ans == (int)1e9)ans=-1;
    return cout << ans,0;
}