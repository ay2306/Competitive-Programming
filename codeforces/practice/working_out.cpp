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
#define FILE_READ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define MAXN 25
using namespace std;
ll arr[1010][1010];
ll dp1[1010][1010];
ll dp2[1010][1010];
ll dp3[1010][1010];
ll dp4[1010][1010];

int main(){
    FAST
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j)cin >> arr[i][j];
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            dp1[i][j] = arr[i][j] + max(dp1[i-1][j],dp1[i][j-1]);
        }
    }
    for(int i = n; i > 0; --i){
        for(int j = 1; j < m; ++j){
            dp2[i][j] = arr[i][j] + max(dp2[i+1][j],dp2[i][j-1]);
        }
    }
    for(int i = n; i > 0; --i){
        for(int j = m ; j > 0; --j){
            dp3[i][j] = arr[i][j] + max(dp3[i+1][j],dp3[i][j+1]);
        }
    }
    for(int i = 1; i <= n; ++i){
        for(int j = m; j > 0; --j){
            dp4[i][j] = arr[i][j] + max(dp4[i-1][j],dp4[i][j+1]);
        }
    }
    ll ans = 0;
    for(int i = 2; i < n; ++i){
        for(int j = 2; j < m; ++j){
            ans = max(dp1[i-1][j]+ dp2[i][j-1] + dp3[i+1][j] + dp4[i][j+1], ans);
            ans = max(dp1[i][j-1]+ dp2[i+1][j] + dp3[i][j+1] + dp4[i-1][j], ans);
        }
    }
    cout << ans;
    return 0;
}