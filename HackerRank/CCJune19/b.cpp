#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    const int mx = 1010;
    int n; //Number of Squares
    long c;
    std::cin >> n >> c;
    std::vector<long> arr(n);
    for(int i = 0; i < n; ++i){
        std::cin >> arr[i];
        arr[i]*=arr[i]; //Computing area of square
    }
    std::vector<int> dp(mx+1,-1);
    dp[0] = 0;
    for(int i = 1; i <= mx; ++i){
        int mn = mx*mx;
        for(int j = 0; j < n; ++j){
            if(i - arr[j] < 0)continue;
            else if(dp[i-arr[j]] != -1){
                mn = min(mn,dp[i-arr[j]]+1);
            }
        }
        if(mn != mx*mx){
            dp[i] = mn;
        }
    }
    int q;
    std::cin >> q;
    while(q--){
        int a;
        std::cin >> a;
        if(dp[a] == -1){
            cout << "NO\n";
        }else{
            cout << "YES " << c*dp[a] << "\n";
        }
    }
    return 0;
}