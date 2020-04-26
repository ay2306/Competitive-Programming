#include<bits/stdc++.h>
using namespace std;
const int BIT = 20,N = 1e5+10, mx = (1<<20);
int n,k;
int dp[1<<BIT];
string a,b;
void solve(){
    memset(dp,-1,sizeof(dp));
    cin >> n >> k;
    cin >> a;
    for(int i = 1; i <= k; ++i){
        int mask = 0;
        cin >> b;
        for(char &j: b)mask|=(1<<(j-'a'));
        dp[mask] = i;
        // cout << "SET " << mask << "\n";
    }
    for(int j = 0; j < BIT; ++j){
        for(int i = 0; i < mx; ++i){
            if(~dp[i]){
                if((i>>j)&1){
                    dp[i^(1LL<<j)] = dp[i];
                    // cout << "SET " << (i^(1LL<<j)) << "\n";
                }
            }
        }
    }
    int cur = 0, len = 0;
    for(int i = 0; i < a.size(); ++i){
        char j = a[i];
        int nxt = (cur|(1<<(j-'a')));
        // cout << nxt << " " << cur << "\n";
        if(~dp[nxt]){
            cur = nxt;
            len++;
        }else{
            while(len--)cout << dp[cur] << " ";
            len = 1, cur = (1<<(j-'a'));
        }
    }
    while(len--)cout << dp[cur] << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}