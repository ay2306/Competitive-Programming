#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<string> res;

string dir = "DURL";
bool vis[7][7];

pair<int,int> nxtMove(int i, int j, char dir){
    if(dir == 'D')i++;
    if(dir == 'U')i--;
    if(dir == 'R')j++;
    if(dir == 'L')j--;
    return make_pair(i,j);
}

bool valid(int i, int j){
    return i >= 0 && i < 7 && j >= 0 && j < 7 && !vis[i][j];
}


void dfs(int i, int j, string &s){
    if(res.size() == 48 && i == 6 && j == 6){
        res.emplace_back(s);
        return;
    }
    if(i == 6 && j == 6)return;
    vis[i][j] = true;
    for(auto k: dir){
        int x,y;
        tie(x,y) = nxtMove(i,j,k);
        if(!valid(x,y))continue;
        s+=k;
        dfs(x,y,s);
        s.pop_back();
    }
    vis[i][j] = false;
}

signed main(){
    string s;
    // cin >> s;
    string ans = "";
    dfs(0,0,ans);
    return 0;
}