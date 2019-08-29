/*
 ____________________________________________________________
|                                                            |
|                   Author: ay2306                           |
|____________________________________________________________|

*/
#include <bits/stdc++.h>
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
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
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define MAXN 25
using namespace std;
ll dp[2000][2000][2];


// +3 +2
// -5 -10
// -20 +5

ll cal(ll h, ll a, ll p){
    if(h <= 0 || a <= 0)return 0;
    if(dp[h][a][p]!=-1)return dp[h][a][p];
    if(p == 0)dp[h][a][p] = 1 + max(cal(h-5,a-10,1),cal(h-20,a+5,1));
    if(p == 1)dp[h][a][p] = 1 + cal(h+3,a+2,0);
    return dp[h][a][p];
}

void solve(){
    ll a,b;
    cin >> a >> b;
    cout << cal(a+3,b+2,0)<< "\n";
}

int main(){
    memset(dp,-1,sizeof(dp));
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}