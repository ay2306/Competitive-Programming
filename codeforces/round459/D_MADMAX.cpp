#include<bits/stdc++.h>
using namespace std;
const int N = 110;
vector<pair<char,int>> g[N];
int dp[N][N][200];
int n,m,a,b;
char c;

bool pos(int i, int j, char prv){
    int &res = dp[i][j][prv];
    if(~res)return res;
    res = false;
    for(auto x: g[i]){
        if(x.first >= prv && !(pos(j,x.second,x.first))){
            res = true;
            return true;
        }
    }
    return res;
}

int main(){
    memset(dp,-1,sizeof(dp));
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        cin >> a >> b >> c;
        g[a].emplace_back(c,b);
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(pos(i,j,'a'))cout << "A";
            else cout << "B";
        }
        cout << "\n";
    }
    return 0;
}