#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e6+3;

int32_t main(){
    int n,ans=1;
    cin >> n;
    for(int i = 1; i < n; ++i)ans = ans*3LL%mod;
    cout << ans;
    return 0;
}