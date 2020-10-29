#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<int> num;
int dp[100][2][2];

int solve(int pos, int f, int prv){
    if(pos == num.size())return 1;
    int &res = dp[pos][f][prv];
    if(~res)return res;
    res = 0;
    int limit = !prv;
    if(!f)limit = min(limit,num[pos]);
    for(int i = 0; i <= limit; ++i){
        res += solve(pos + 1, f || (i != limit), i);
    }
    return res;
}

int cnt(int k){
    // cout << k << " ";
    num.clear();
    while(k){
        num.emplace_back(k%2);
        k/=2;
    }
    reverse(num.begin(),num.end());
    memset(dp,-1,sizeof(dp));
    return solve(0,0,0);
}

signed main(){
    int n,k;
    cin >> n >> k;
    int ans = LLONG_MAX/2, lo = 0, hi = ans, mid;
    while(lo <= hi){
        mid = lo + hi >> 1;
        int cal = cnt(mid);
        // cout << mid << " " << cal << " " << k << " " << lo << " " << hi << endl;
        if(cal < k)lo = mid + 1;
        else ans = mid, hi = mid - 1;
    }
    string res = "";
    while(ans){
        res += (ans % 2 + '0');
        ans >>= 1;
    }
    while(res.size() < n)res+="0";
    if(res.size() != n)cout << -1 << endl;
    else cout << res << endl;
    return 0;
}