//https://codeforces.com/contest/1335/problem/F
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int moves = 2e6;

int n,m;
vector<string> direction,color,visited;
vector<vector<array<pair<int,int>,22>>> dp;

pair<int,int> change(int i, int j){
    switch(direction[i][j]){
        case 'L': return pair<int,int>(i,j-1);
        case 'R': return pair<int,int>(i,j+1);
        case 'U': return pair<int,int>(i-1,j);
        case 'D': return pair<int,int>(i+1,j);
    }
    return pair<int,int> (-1,-1);
}

void dfs(int i, int j){
    pair<int,int> next_move = change(i,j);
    // printf("direction = %c , cur = (%d, %d) next = (%d, %d)\n",direction[i][j],i,j,next_move.first,next_move.second);
    dp[i][j][0] = next_move;
    visited[i][j] = 'Y';
    if(visited[next_move.first][next_move.second] == 'N')dfs(next_move.first,next_move.second);
}

pair<int,int> endPosition(int i, int j){
    pair<int,int> cur(i,j);
    for(int lev = 0; lev < 22; ++lev)if((moves>>lev)&1)cur=dp[cur.first][cur.second][lev];
    return cur;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        dp.clear();
        visited.clear();
        direction.resize(n);
        color.resize(n);
        visited.resize(n,string(m,'N'));
        dp.resize(n,vector<array<pair<int,int>,22>>(m,array<pair<int,int>,22>()));
        for(int i = 0; i < n; ++i)cin >> color[i];
        for(int i = 0; i < n; ++i)cin >> direction[i];
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(visited[i][j] == 'N')dfs(i,j);
        for(int level = 1; level < 22; ++level)
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < m; ++j)dp[i][j][level] = dp[dp[i][j][level-1].first][dp[i][j][level-1].second][level-1];
        visited.clear();
        visited.resize(n,string(m,'N'));
        int total = 0, black = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                pair<int,int> final = endPosition(i,j);
                if(visited[final.first][final.second] == 'B')continue;
                if(visited[final.first][final.second] == 'N'){
                    if(color[i][j] == '0'){
                        visited[final.first][final.second] = 'B';
                        black++,total++;
                    }else{
                        visited[final.first][final.second] = 'W';
                        total++;
                    }
                }
                else if(visited[final.first][final.second] == 'W'){
                    if(color[i][j] == '0'){
                        visited[final.first][final.second] = 'B';
                        black++;
                    }
                }
            }
        }
        cout << total << " " << black << "\n";
    }
    return 0;
}