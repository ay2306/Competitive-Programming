//https://codeforces.com/contest/16/problem/E
#include<bits/stdc++.h>
#define ld long double
using namespace std;
const int N = 20;
ld dp[(1 << N)], arr[N][N];
int n;
int main(){
    cin >> n;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)cin >> arr[i][j];
    dp[(1<<n)-1] = 1.0;
    for(int mask = (1 << n)-1; mask > 0; --mask){
        int ways = __builtin_popcount(mask);
        ways = ways*(ways-1)/2;
        for(int i = 0; i < n; ++i){
            if((mask >> i) & 1){
                for(int j = i+1; j < n; ++j){
                    if(i == j)continue;
                    if((mask >> j) & 1){
                        dp[mask^(1 << j)] += dp[mask]*arr[i][j]/((ld)ways); 
                        dp[mask^(1 << i)] += dp[mask]*arr[j][i]/((ld)ways); 
                    }
                }
            }
        }
    }
    for(int i = 0; i < n; ++i)printf("%.15Lf ",dp[1<<i]);
    return 0;
}