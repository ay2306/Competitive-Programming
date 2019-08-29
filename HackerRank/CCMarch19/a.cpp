#include<iostream>
using namespace std;
long dp[100];
long f(int n){
    if(n == 1)return 1;
    if(n == 2)return 2;
    if(dp[n] != 0)return dp[n];
    dp[n] = f(n-1) + f(n-2);
    return dp[n];
}
int main(){
    // freopen("output.txt","w",stdout);    
    cout << f(60);
}