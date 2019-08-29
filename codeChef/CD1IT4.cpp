/*
 ____________________________________________________________
|                                                            |
|                   Author: ay2306                           |
|____________________________________________________________|

*/
#include <bits/stdc++.h>
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(dp,val) memset(dp,val,sizeof(dp))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
#define looprs(i,a,b,step) for(int i=a;i>=b;i-=step)
#define ull unsigned long long int
#define ll long long int
#define P pair
#define PLL pair<long long, long long>
#define PII pair<int, int>
#define PUU pair<unsigned long long int, unsigned long long int>
#define L list
#define V vector
#define D deque
#define ST set
#define MS multiset
#define M map
#define UM unordered_map
#define mp make_pair
#define pb push_back
#define pf push_front
#define MM multimap
#define F first
#define S second
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define MAXN 25
using namespace std;

ll dp[1001][1001];

void solve(){
    int n,m;
    cin >> n >> m;
    int p;
    cin >> p;
    while(p--){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        dp[a][b] = -1;
    }
    if(dp[0][0] == -1){
        cout << 0;
        return ;
    }
    for(int i = 0; i < m; ++i){
        if(dp[0][i] == -1)break;
        dp[0][i] = 1;
    }
    for(int i = 0; i < n; ++i){
        if(dp[i][0] == -1)break;
        dp[i][0] = 1;
    }
    for(int i = 1; i < n; ++i){
        for(int j = 1; j < m; ++j){
            if(dp[i][j] == -1)continue;
            dp[i][j] = 0;
            if(dp[i-1][j] != -1)dp[i][j] = dp[i-1][j];
            if(dp[i][j-1] != -1)dp[i][j]+=dp[i][j-1];
            dp[i][j] = dp[i][j]%1000000007;
        }
    }
    if(dp[n-1][m-1] == -1){
        cout << 0 << "\n";
    }else{
        cout << dp[n-1][m-1] << "\n";
    }
}

int main(){
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}