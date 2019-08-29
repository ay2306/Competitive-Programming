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
int n,m;
V<string> arr;
V<V<int>> dp;
bool valid(int i, int j){
    return (i >= 0 && i < n && j >= 0 && j < m);
}

int dfs(int i, int j){
    if(!(i >= 0 && i < n && j >= 0 && j < m))return 0;
    int &chain = dp[i][j];
    if(chain != -1)return chain;
    chain = 0;
    V<int> x {-1,0,1};
    V<int> y {-1,0,1};
    for(int o1: x){
        for(int o2: y){
            if(o1 == 0 && o2 == 0)continue;
            if(valid(i+o1,j+o2) && arr[i+o1][j+o2] == arr[i][j]+1){
                chain = max(chain,dfs(i+o1,j+o2));
            }
        }
    }
    chain++;
    return chain;
}

void solve(){
    arr = V<string>(n);
    loop(i,0,n)cin >> arr[i];
    dp = V<V<int>> (n,V<int>(m,-1));
    int ans = 0;
    loop(i,0,n){
        loop(j,0,m){
            if(arr[i][j] == 'A')ans = max(ans,dfs(i,j));
        }
    }
    printf("%d\n",ans);
}

int main(){
    FAST
    // FILE_READ_IN
    int t = 1;
    while(1){
        cin >> n >> m;
        if(n == 0 && m == 0)break;
        printf("Case %d: ",t++);
        solve();

    }
   return 0;
}