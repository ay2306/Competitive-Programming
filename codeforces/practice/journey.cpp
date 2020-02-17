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
const ll N = 5e3+2;
const ll inf = 1e9;
const double pi = acos(-1);
int n,m,T;
int dp[N][N];
int p[N][N];
V<PII> g[N];
int main(){
    FAST
    cin >> n >> m >> T;
    loop(i,0,N){
        loop(j,0,N)dp[i][j]=-1,p[i][j]=-1;
    }
    while(m--){
        ll a,b,c;
        cin >> a >> b >> c;
        g[a].pb({b,c});
    }
    dp[1][1] = 0;
    int mx = -1;
    loop(j,1,n){
        loop(i,1,n+1){
            if(dp[i][j] == -1)continue;
            for(auto k: g[i]){
                if(dp[k.F][j+1] == -1 || dp[k.F][j+1] > dp[i][j]+k.second){
                    dp[k.F][j+1] = dp[i][j]+k.second;
                    p[k.first][j+1]=i;
                }
            }
        }
    }
    loopr(i,n,0){
        if(dp[n][i] <= T && dp[n][i] >= 0){
            mx = i;
            break;
        }
    }
    stack<int> s;
    while(n > 0){
        s.push(n);
        n = p[n][mx--];
    }
    cout << s.size() << "\n";
    while(s.size()){
        cout << s.top() << " ";
        s.pop();
    }
   return 0;
}