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
int n,m;
V<V<int> > arr;
V<V<bool> > visited;

int dfs(int i, int j){
    if(i < 0 || i >= n || j < 0 || j >= m || visited[i][j] || arr[i][j] == 0)return 0;
    int ans = 1;
    visited[i][j] = true;
    ans+=dfs(i,j-1);
    ans+=dfs(i,j+1);
    ans+=dfs(i-1,j-1);
    ans+=dfs(i-1,j+1);
    ans+=dfs(i-1,j);
    ans+=dfs(i+1,j);
    ans+=dfs(i+1,j+1);
    ans+=dfs(i+1,j-1);
    return ans;
}

void solve(){
    cin >> n >> m;
    arr = V<V<int> > (n,V<int>(m,0));
    visited = V<V<bool> > (n,V<bool>(m,false));
    int ans = 0;
    int mx = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(arr[i][j] && !visited[i][j]){
                ans++;
                mx = max(dfs(i,j),mx);
            }
        }
    }
    cout << ans << " " << mx << "\n";
}

int main(){
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}