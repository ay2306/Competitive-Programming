#include<bits/stdc++.h>
using namespace std;

int dp[5050][5050],cnt;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 0; i < n; ++i){
        cnt = 0;
        for(int j = i; j < n; ++j){
            if(s[j] != ')')cnt++;
            else cnt--;
            if(cnt < 0){
                for(int k = j; k < n; ++k)dp[i][k] = -1;
                break;
            }
            dp[i][j] = cnt;
        }
    }
    int ans = 0;
    for(int j = n-1; j >= 0; j--){
        cnt = 0;
        for(int i = j; i >= 0; i--){
            if(s[i] != '(')cnt++;
            else cnt--;
            if(cnt < 0)break;
            if(dp[i][j] == -1)continue;
            else if(j-i & 1){
                ans++;
            }
        }
    }
    return cout << ans , 0;
}