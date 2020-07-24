#include<bits/stdc++.h>
using namespace std;

int dis[9][9][9][9];

int dx[] = {-1,-1,1,1,-2,-2,2,2};
int dy[] = {2,-2,2,-2,1,-1,1,-1};
bool valid(int i, int j){
    return i >= 1 && i <= 8 && j >= 1 && j <= 8;
}

void bfs(int sx, int sy){
    dis[sx][sy][sx][sy] = 0;
    queue<pair<int,int>> q;
    q.push({sx,sy}); 
    while(q.size()){
        int x,y;
        tie(x,y) = q.front();
        q.pop();
        for(int i = 0; i < 8; ++i){
            if(valid(x+dx[i],y+dy[i]) && dis[sx][sy][x+dx[i]][y+dy[i]] == -1){
                dis[sx][sy][x+dx[i]][y+dy[i]] = dis[sx][sy][x][y] + 1;
                q.push({x+dx[i],y+dy[i]});
            }
        }
    }    
}


int main(){
    memset(dis,-1,sizeof(dis));
    for(int i = 1; i <= 8; ++i)
        for(int j = 1; j <= 8; ++j)
            bfs(i,j);
    int q;
    char a[5],b[5];
    scanf("%d",&q);
    while(q--){
        scanf("%s %s",a,b);
        printf("%d\n",dis[a[0]-'a'+1][a[1]-'0'][b[0]-'a'+1][b[1]-'0']);
    }
    return 0;
}