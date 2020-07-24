#include<bits/stdc++.h>
using namespace std;
const int inf = 1e8;
vector<vector<char>> a;
vector<vector<int>> dis1,dis2,dis3,vis;
int n,m;
vector<int> play;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

bool valid(int i, int j){
    return i >= 0 && j >= 0 && i <= n+1 && j <= m+1 && a[i][j] != '*';
}

void bfs(deque<pair<int,int>> &q, vector<vector<int>> &dis){
    vis = vector<vector<int>> (n+2,vector<int> (m+2, 0));
    int i,j,x,y;
    while(!q.empty()){
        tie(i,j) = q.front();
        q.pop_front();
        if(vis[i][j])continue;
        vis[i][j] = 1;
        for(int k = 0;  k < 4; ++k){
            x = i+dx[k];
            y = j+dy[k];
            if(!valid(x,y))continue;
            if(vis[x][y])continue;
            if(a[x][y] == '#' && dis[x][y] > dis[i][j] + 1)q.emplace_back(x,y), dis[x][y] = dis[i][j] + 1;
            if(a[x][y] == '.' && dis[x][y] > dis[i][j])q.emplace_front(x,y), dis[x][y] = dis[i][j];
        }
    }
}

void solve(){
    play.clear();
    cin >> n >> m;
    a = vector<vector<char>> (n+2,vector<char>(m+2,'.'));
    for(int i = 1; i <= n; ++i){
        string s;
        cin >> s;
        for(int j = 1; j <= m; ++j)a[i][j] = s[j-1];
        for(int j = 1; j <= m; ++j)if(a[i][j] == '$')play.emplace_back(i),play.emplace_back(j),a[i][j] = '.';
    
    }
    dis1 = vector<vector<int>> (n+2,vector<int> (m+2, inf));
    dis2 = vector<vector<int>> (n+2,vector<int> (m+2, inf));
    dis3 = vector<vector<int>> (n+2,vector<int> (m+2, inf));
    vector<pair<int,int>> all_outside;
    for(int i = 0; i <= m+1; ++i)all_outside.emplace_back(0,i),all_outside.emplace_back(n+1,i);
    for(int i = 0; i <= n+1; ++i)all_outside.emplace_back(i,0),all_outside.emplace_back(i,m+1);
    deque<pair<int,int>> q;
    for(auto& [x,y]: all_outside){
        dis1[x][y] = 0;
        q.emplace_back(x,y);
    }
    bfs(q,dis1);
    {
        int x = play[0], y = play[1];
        dis2[x][y] = 0;
        q.emplace_back(x,y);
        bfs(q,dis2);
    }
    {
        int x = play[2], y = play[3];
        dis3[x][y] = 0;
        q.emplace_back(x,y);
        bfs(q,dis3);
    }
    a[play[0]][play[1]] = '$';
    a[play[2]][play[3]] = '$';
    int ans = dis1[play[0]][play[1]] + dis1[play[2]][play[3]];
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            for(int k = 0; k < 4; ++k){
                int x = i + dx[k], y = j + dy[k];
                if(!valid(x,y))continue;
                for(int k1 = 0; k1 < 4; ++k1){
                    int X = x+dx[k1], Y = y+dy[k1];
                    if(!valid(X,Y))continue;
                    ans = min(ans,dis1[i][j]+dis2[X][Y]+dis3[x][y]);
                }
            }
    cout << ans << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}