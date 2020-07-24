//https://codeforces.com/contest/1198/problem/D
#include<iostream>
const int N = 55;

char s[N][N];
int dp[N][N][N][N];
int pref[N][N];
int n;

int cost(int i, int j, int k, int l){
    return pref[k][l] - pref[k][j-1] - pref[i-1][l] + pref[i-1][j-1];
}

int main(){
    std::cin >> n;
    for(int i = 1; i <= n; ++i)std::cin >> (s[i]+1);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + (s[i][j] == '#');
        }
    }

    for(int length = 1; length <= n; ++length){
        for(int width = 1; width <= n; ++width){
            for(int i = 1; i <= n; ++i){
                for(int j = 1; j <= n; ++j){
                    int k = i + length - 1;
                    int l = j + width - 1;
                    if(k > n || l > n)continue;
                    if(cost(i,j,k,l) == 0){
                        dp[i][j][k][l] = 0;
                        continue;
                    }
                    int &res = dp[i][j][k][l];
                    res = std::max(length,width);
                    for(int part = i; part < k; ++part){
                        res = std::min(res,dp[i][j][part][l] + dp[part+1][j][k][l]);
                    }
                    for(int part = j; part < l; ++part){
                        res = std::min(res,dp[i][j][k][part] + dp[i][part+1][k][l]);
                    }
                }
            }
        }
    }
    return std::cout << dp[1][1][n][n] << "\n",0; 
}