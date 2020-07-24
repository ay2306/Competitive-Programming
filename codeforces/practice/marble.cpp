//https://codeforces.com/contest/1215/problem/E
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e5+10, LN = 21;
int n;
int dp[1<<22], arr[N], cost[LN][LN];
vector<int> col[LN];

signed main(){
    scanf("%lld",&n);
    fill(dp,dp+(1<<LN),LLONG_MAX);
    for(int i = 1; i <= n; ++i)scanf("%lld",arr+i);
    for(int i = 1; i <= n; ++i)col[arr[i]-1].emplace_back(i);
    for(int i = 0; i < LN; ++i){
        for(int j = i+1; j < LN; ++j){
            for(int p2 = 0 , p1 = 0; p2 < col[i].size(); ++p2){
                while(p1 < col[j].size() && col[j][p1] < col[i][p2])p1++;
                if(p1 == col[j].size())break;
                cost[j][i]+=(col[j].size()-p1);
            }
            for(int p2 = 0 , p1 = 0; p2 < col[j].size(); ++p2){
                while(p1 < col[i].size() && col[i][p1] < col[j][p2])p1++;
                if(p1 == col[i].size())break;
                cost[i][j]+=(col[i].size()-p1);
            }
        }
    }
    dp[0] = 0;
    for(int mask = 0; mask < (1 << LN); ++mask){
        if(dp[mask] == LLONG_MAX)continue;
        for(int element = 0; element < LN; ++element){
            int cst = 0;
            if((mask>>element)&1)continue;
            for(int i = 0; i < LN; ++i){
                if((mask>>i)&1)cst+=cost[i][element];
            }
            dp[mask^(1<<element)] = min(dp[mask^(1<<element)],cst+dp[mask]);
            // if((mask^element) == 1)cout << dp[mask^element] << "\n";
        }
    }
    return printf("%lld\n",dp[(1<<LN)-1]),0;
}