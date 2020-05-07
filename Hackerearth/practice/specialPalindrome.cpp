#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
void solve(){
    char c;
    string s;
    cin >> c >> s;
    int n = s.size();
    string t = s;
    reverse(s.begin(),s.end());
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(2,0)));
    for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= n; ++j){
            dp[i][j][1] = inf; 
            if(!i || !j)continue;
            if(s[i-1] == t[j-1] && s[i-1] != c){
                dp[i][j][0] = dp[i-1][j-1][0] + 1; 
                if(dp[i-1][j-1][1] != inf)dp[i][j][1] = dp[i-1][j-1][1] + 1;
            }
            else if(s[i-1] == t[j-1] && s[i-1] == c){
                if(dp[i-1][j-1][1] != inf)
                    dp[i][j][1] = max(dp[i-1][j-1][1],dp[i-1][j-1][0])+1;
                else
                    dp[i][j][1] = dp[i-1][j-1][0] + 1;
                dp[i][j][0] = max(dp[i-1][j][0],dp[i][j-1][0]); 
            }
            else if(s[i-1] != t[j-1]){
                dp[i][j][0] = max(dp[i-1][j][0],dp[i][j-1][0]);
                if(dp[i-1][j][1] != inf && dp[i][j-1][1] != inf)
                    dp[i][j][1] = max(dp[i-1][j][1],dp[i][j-1][1]);
                else if(dp[i-1][j][1] != inf)
                    dp[i][j][1] = dp[i-1][j][1];
                else if(dp[i][j-1][1] != inf)
                    dp[i][j][1] = dp[i][j-1][1];
            }
        }
    }
    if(dp[n][n][1] == inf)dp[n][n][1] = 0;
    cout << dp[n][n][1] << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}