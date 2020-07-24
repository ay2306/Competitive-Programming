#include<bits/stdc++.h>
using namespace std;
int dp[12][12];
pair<int,int> optimal[12][4];

int main(){
    ios::sync_with_stdio(false);
    int n,m,k,s;
    cin >> n >> m >> k >> s;
    vector<vector<int>> a(n+1,vector<int>(m+1));
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)cin >> a[i][j];
    vector<int> b(s);
    for(int &i: b)cin >> i;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(optimal[a[i][j]][0] == pair<int,int> (0,0)){
                optimal[a[i][j]][0] = make_pair(i,j);
                optimal[a[i][j]][1] = make_pair(i,j);
                optimal[a[i][j]][2] = make_pair(i,j);
                optimal[a[i][j]][3] = make_pair(i,j);
            }else{
                auto &res = optimal[a[i][j]];
                if(res[0].second+res[0].first > i+j)res[0] = make_pair(i,j);
                if(res[1].second-res[1].first > j-i)res[1] = make_pair(i,j);
                if(-res[2].second+res[2].first > -j+i)res[2] = make_pair(i,j);
                if(-res[3].second-res[3].first > -i-j)res[3] = make_pair(i,j);
            }
        }
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            int note = a[i][j];
            for(int note1 = 1; note1 <= k; ++note1){
                for(int x = 0; x < 4; ++x)
                    dp[note][note1] = max(dp[note][note1],abs(i-optimal[note1][x].first)+abs(j-optimal[note1][x].second));
            }
        }
    }
    int ans = 0;
    for(int i = 1; i < s; ++i){
        ans = max(ans,dp[b[i-1]][b[i]]);
    }
    return cout << ans , 0;
}