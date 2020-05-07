/*Let's start*/
//Now you see...
#define  ll               long long
#define  pb               push_back
#define  ff               first
#define  ss               second
#define  srt(v)           sort(v.begin(),v.end())
#define  inf              1000000000
#define  mxn              1009
#define  pi               acos(-1)
#define  MOD              1000000007
#define  ordered_set      sum<ll, null_type,less<ll>, rb_sum_tag,sum_order_statistics_node_update>
#define  db(x)            printf("### VALUE: (%lld) ###\n",(ll)x)
#include <bits/stdc++.h>
using namespace std;
char c;
string s;
ll dp[mxn][mxn][3];
int solve(int i,int j,int f)
{
    if(i > j ){
        if(f == 1) return 0;
        else return -inf;
    }
    if(dp[i][j][f] != -1) return dp[i][j][f];
    int nf = f;
    int ret = 0;
    if(s[i] == s[j]){
        if(s[i] == c) nf = 1;
        int q = 2;
        if(i == j) q = 1;
        ret = q + solve(i+1,j-1,nf);
    }
    else{
        ret = max(solve(i+1,j,nf),solve(i,j-1,nf));
    }
    return dp[i][j][f] =  ret;
}
int main()
{
    int t;scanf("%d",&t);
    while(t--){
        memset(dp,-1,sizeof dp);
        cin >> c;
        cin >> s;
        ll keep = max(0,solve(0,s.size(),0));
        cout << keep << endl;
    }
    return 0;
}