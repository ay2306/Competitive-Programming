#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9+7;

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    int suff = 0;
    while(s.size() && s.back() == '0')suff++,s.pop_back();
    if(s.empty())return cout << suff, 0;
    int n = s.size();
    vector<int> dis(n);
    for(int i = 0 ; i < n; ++i){
        if(s[i] == '0')dis[i] = (i?dis[i-1]:0) + 1;
    }
    vector<int> dp(n+2),nxt(n+2,n);
    auto get = [&](int i)->int{
        return (nxt[i] < n ? dp[nxt[i]] : 0);
    };
    for(int i = n-1; ~i; --i){
        dp[i] = (s[i] == '1')  + get(0) + get(dis[i] + 1);
        dp[i] %= mod;
        nxt[dis[i]] = i; 
    }
    int ans = get(0) * (nxt[0] + 1) % mod;
    ans = ans * (suff+1) % mod;
    cout << ans;
    return 0;
}