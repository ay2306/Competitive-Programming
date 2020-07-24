//https://codeforces.com/problemset/problem/156/C
#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int dp[110][26*110];

int main(){
    for(int i = 0; i < 26; ++i){
        dp[1][i] = 1;
    }
    for(int len = 2; len <= 105; ++len){
        for(int sum = 0; sum <= 25*len; ++sum){
            for(int i = 0; i < 26; ++i){
                if(sum < i)break;
                dp[len][sum]+=dp[len-1][sum-i];
                if(dp[len][sum] >= mod)dp[len][sum]-=mod;
            }
        }
    }
    int t;
    cin >> t;
    while(t--){
        string a;
        cin >> a;
        int s = 0;
        for(char i: a)s+=(i-'a');
        cout << dp[(int)a.size()][s]-1 << "\n";
    }
    return 0;
}