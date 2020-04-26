#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,k;
const ll inf = LLONG_MIN/100LL; 
ll dp[5050][5050];
ll arr[5050];
int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)cin >> arr[i];
    for(int i = 0; i < 5050; ++i){
        for(int j = 0; j < 5050; ++j)dp[i][j] = inf;
    }
    
    dp[0][0] = 0;
    for(int i = 1; i <= k; ++i){
        for(int len = 1; i < n; ++i){

        }
    }
}