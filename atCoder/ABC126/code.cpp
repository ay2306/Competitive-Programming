/*
 ____________________________________________________________
|                                                            |
|                   Author: ay2306                           |
|____________________________________________________________|
 
*/
#include <bits/stdc++.h>
//For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define all(a) a.begin(),a.end()
#define ord_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
const ll maxn = 1e5;

int n,m;
V<V<int>> arr;
V<V<int>> dp;
pair<int,int> s;

void dfs(int i = s.F, int j = s.S, int steps = 0){
    dp[i][j] = 0;
    queue<pair<int,int>> q;
    q.push(make_pair(i,j));
    V<V<bool>> vis(n+1,V<bool>(m+1,false));
    vis[i][j] = true;
    while(q.size()){
        auto p = q.front();
        q.pop();
        i = p.F;
        j = p.S;
        for(int i1 = -arr[i][j]; i1 <= arr[i][j]; ++i1){
            int j1 = arr[i][j] - abs(i1);
            if(!(i+i1 < 1 || i+i1 > n || j+j1 < 1 || j+j1 > m) && !vis[i+i1][j+j1]){
                vis[i+i1][j+j1] = true;
                q.push(make_pair(i+i1,j+j1));
                dp[i+i1][j+j1]=dp[i][j]+1;
            }
            j1*=-1;
            if(!(i+i1 < 1 || i+i1 > n || j+j1 < 1 || j+j1 > m) && !vis[i+i1][j+j1]){
                vis[i+i1][j+j1] = true;
                q.push(make_pair(i+i1,j+j1));
                dp[i+i1][j+j1]=dp[i][j]+1;
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    arr = V<V<int>>(n+1,V<int>(m+1,INT_MAX));
    dp = V<V<int>>(n+1,V<int>(m+1,INT_MAX));
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j)cin >> arr[i][j];
    }
    cin >> s.F >> s.S;
    dfs();
    int q;
    cin >> q;
    while(q--){
        int a,b;
        cin >> a >> b;
        if(dp[a][b] == INT_MAX)cout << "-1\n";
        else cout << dp[a][b] << "\n";
    }
}

int main(){
    FAST
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}