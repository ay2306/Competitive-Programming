#include<bits/stdc++.h>
using namespace std;
const int N = 1010,inf=1e9;
string a[N];
bool vis[N][N][4];
int n,m,dir,dis[N][N][4],x1,Y1,x2,y2,x,y,i,j;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool valid(int i, int j){
    return i >= 0 && j >= 0 && i < n && j < m && a[i][j] != '*';
}

struct state{
    int i, j, dir;
    state(){}
    state(int i, int j, int dir): i(i), j(j), dir(dir){}
};

int main(){
    cin >> n >> m;
    for(int i = 0 ; i < n; ++i)cin >> a[i];
    for(int i = 0 ; i < n; ++i){
        for(int j = 0; j < m; ++j){
            fill(dis[i][j],dis[i][j]+4,inf);
            if(a[i][j] == 'S')x1=i,Y1=j;
            else if(a[i][j] == 'T')x2=i,y2=j;
        }
    }
    deque<state> q;
    q.emplace_back(x1,Y1,0);
    q.emplace_back(x1,Y1,1);
    q.emplace_back(x1,Y1,2);
    q.emplace_back(x1,Y1,3);
    dis[x1][Y1][0] = 0;
    dis[x1][Y1][1] = 0;
    dis[x1][Y1][2] = 0;
    dis[x1][Y1][3] = 0;
    while(q.size()){
        i = q.front().i;
        j = q.front().j;
        dir = q.front().dir;
        q.pop_front();
        if(vis[i][j][dir])continue;
        vis[i][j][dir] = true;
        for(int k = 0; k < 4; ++k){
            x = i + dx[k];
            y = j + dy[k];
            if(!valid(x,y))continue;
            if(k == dir && dis[x][y][k] > dis[i][j][dir])q.emplace_front(x,y,k),dis[x][y][k] = dis[i][j][dir];
            if(k != dir && dis[x][y][k] > dis[i][j][dir]+1)q.emplace_back(x,y,k),dis[x][y][k] = dis[i][j][dir] + 1;
        }
    }
    if(*min_element(dis[x2][y2],dis[x2][y2]+4) > 2)return cout << "NO\n",0;
    return cout << "YES\n",0;
}