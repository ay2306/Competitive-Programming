#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll dp[(int)1e3+10][1<<6][4];
int a[(int)1e4+10];
map<char,int> v;

void solve(){
    memset(dp,0,sizeof(dp));
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        string s;
        cin >> s;
        a[i] = 0;
        for(auto &j: s)if(v.count(j))a[i] |= (1 << v[j]);
        dp[i][a[i]][1] = 1;
    }
    int ans = 0;
    for(int i = 2; i <= n; ++i){
        for(int mask = 0; mask < (1 << 5); ++mask){
            for(int pos = 2; pos <= 3; ++pos){
                dp[i][mask&a[i]][pos] += dp[i-1][mask][pos-1];
            }
            if(mask&a[i])ans+=dp[i][mask][3];
            for(int pos = 1; pos <= 3; ++pos){
                dp[i][mask][pos] += dp[i-1][mask][pos];
            }
        }
        // printf("index = %d, ans = %lld\n",i,ans);
    }
    cout << ans << "\n";
}

int main(){
    v['a'] = 0;
    v['e'] = 1;
    v['i'] = 2;
    v['o'] = 3;
    v['u'] = 4;
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}