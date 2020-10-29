#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,m,W;
    cin >> n >> m >> W;
    map<int,vector<pair<int,int>>> f;
    vector<int> w(n),b(n);
    for(int &i: w)cin >> i;
    for(int &i: b)cin >> i;
    {
        vector<int> p(n);
        iota(p.begin(),p.end(),0);
        function<int(int)> fp = [&](int x)->int{
            if(p[x] != x)p[x] = fp(p[x]);
            return p[x];
        };
        auto un = [&](int a, int b){
            p[fp(a)] = fp(b);
        };
        while(m--){
            int x,y;
            cin >> x >> y;
            un(x-1,y-1);
        }
        for(int i = 0; i < n; ++i)f[fp(i)].emplace_back(w[i],b[i]);
    }
    for(auto &i: f){
        int weight = 0, beaut = 0;
        for(auto& [x,y]: i.second)
            weight+=x,beaut+=y;
        i.second.emplace_back(weight,beaut);
        // for(auto& [x,y]: i.second)cout << "(" << x << ", " << y << ") ";
        // cout << endl;
    }
    int index = 0,ans = 0;
    vector<vector<int>> dp(f.size()+1,vector<int>(W+1,0));
    for(auto &variable: f){
        index++;
        for(int j = 0; j <= W; ++j){
            dp[index][j] = dp[index-1][j];
            for(auto i: variable.second){
                if(i.first > j)continue;
                dp[index][j] = max(dp[index][j],dp[index-1][j-i.first]+i.second);
                ans = max(ans,dp[index][j]);
            }
        }
    }
    cout << ans;
    return 0;
}