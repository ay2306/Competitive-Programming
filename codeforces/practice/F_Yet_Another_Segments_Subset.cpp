#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,cur=0;
        scanf("%d",&n);
        vector<pair<int,int>> a(n);
        for(auto& [x,y]: a)scanf("%d%d",&x,&y);
        map<int,int> m;
        for(auto [x,y]: a)m[x],m[y];
        for(auto &i: m)i.second = ++cur;
        for(auto& [x,y]: a)x=m[x],y=m[y];
        vector<vector<int>> dp(cur+10,vector<int> (cur+10,-1));
        vector<vector<int>> rg(cur+10);
        for(auto& [x,y]: a)rg[x].emplace_back(y);
        function<int(int,int)> solve = [&](int l, int r)->int{
            int &res = dp[l][r];
            if(~res)return res;
            res = 0;
            if(l > r)return res;
            int cnt = count(rg[l].begin(),rg[l].end(),r);
            res = max(res, cnt + solve(l+1, r));
            for(auto R: rg[l]){
                if(R >= r)continue;
                res = max(res,cnt + solve(l,R) + solve(R+1,r));
            }
            return res;
        };
        printf("%d\n",solve(0,cur+1));
    }
    return 0;
}