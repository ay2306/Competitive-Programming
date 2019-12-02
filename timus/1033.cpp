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
#define ld long double
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);
V<V<int>> ans;
V<V<int>> vis;
V<string> arr;
int n;
bool f = false;
void dfs(int i = 0, int j = 0){
    if(vis[i][j])return;
    vis[i][j] = 1;
    if(i == n-1 && j == n-1){
        f = true;
    }
    if(i == 0 || arr[i-1][j] == '#')ans[i][j]++;
    if(j == 0 || arr[i][j-1] == '#')ans[i][j]++;
    if(i == n-1 || arr[i+1][j] == '#')ans[i][j]++;
    if(j == n-1 || arr[i][j+1] == '#')ans[i][j]++;
    if(i+1 < n && arr[i+1][j] != '#')dfs(i+1,j);
    if(j+1 < n && arr[i][j+1] != '#')dfs(i,j+1);
    if(i > 0 && arr[i-1][j] != '#')dfs(i-1,j);
    if(j > 0 && arr[i][j-1] != '#')dfs(i,j-1);
}
int main(){
    cin >> n;
    arr = V<string> (n);
    ans = V<V<int>> (n,V<int> (n,0));
    vis = V<V<int>> (n,V<int> (n,0));
    loop(i,0,n){
        cin >> arr[i];
    }
    // loop(i,0,n){
    //     loop(j,0,n){
    //         if(arr[i][j] == '.' && !vis[i][j])dfs(i,j);
    //     }
    // }
    dfs(0,0);
    if(!vis[n-1][n-1])dfs(n-1,n-1);
    // if(!f){
    //     cout << 0;
    //     return 0;
    // }
    int cnt = -4;
    loop(i,0,n){
        loop(j,0,n){
            // cout << ans[i][j] << " ";
            cnt+=ans[i][j];
        }
        // cout << "\n";
    }
    cout << cnt*9 ;
   return 0;
}