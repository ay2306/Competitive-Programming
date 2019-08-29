/*
 ____________________________________________________________
|                                                            |
|                   Author: ay2306                           |
|____________________________________________________________|

*/
#include <bits/stdc++.h>
using namespace std;
int dp[20000001];
int c = 1;
void solve(){
    int n;
    cin >> n;
    cout << "Case " << c++ << ": " << dp[n] << "\n";
}

int main(){
    for(int i = 2; i < 20000001; ++i){
        dp[i] = dp[i-1]+1;
        if(i%2 == 0){
            dp[i] = min(dp[i],1+dp[i/2]);
        }
        if(i%3 == 0){
            dp[i] = min(dp[i],1+dp[i/3]);
        }
    }
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}