#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> g[1010][1010];
int vis[1010][1010];
string canReach(int x1, int y1, int x2, int y2){
    memset(vis,0,sizeof(vis));
    for(int x = x1; x <= x2; x++){
        for(int y = y1; y <= y2; ++y){
            g[x][y].clear();
            if(x+y <= x2){
                g[x+y][y].clear();
                g[x][y].emplace_back(x+y,y);
            }
            if(x+y <= y2){
                g[x][y+y].clear();
                g[x][y].emplace_back(x,x+y);
            }
        }
    }
    int x,y,i,j;
    queue<pair<int,int>> q;
    q.emplace(x1,y1);
    vis[x1][y1] = true;
    while(q.size()){
        tie(x,y) = q.front();
        if(x == x2 && y == y2)return "Yes";
        q.pop();
        for(auto a: g[x][y]){
            tie(i,j) = a;
            if(!vis[i][j]){
                q.emplace(i,j);
                vis[i][j] = true;
            }
        }
    }
    return "No";
}

int main(){
    cout << canReach(1,2,2,1) << "\n";
    cout << canReach(1,4,5,9) << "\n";
}