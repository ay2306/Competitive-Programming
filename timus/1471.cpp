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
const ll N = 5e4 + 50;
const ll inf = 1e9;
const double pi = acos(-1);
int dp[20][N];
ll level[N];
ll lev[N];
V<P<ll,int>> g[N];
int n;
void dfs(int s, int p){
    if(p == -1)level[s] = 0,lev[s]=0;
    else level[s] = level[p]+1;
    dp[0][s] = p;
    for(auto &i: g[s]){
        if(i.S != p){
            lev[i.S] = lev[s]+i.F;
            dfs(i.S,s);
        }
    }
}

void pre(){
    loop(i,1,20){
        loop(j,0,n){
            if(dp[i-1][j] == -1)dp[i][j]=-1;
            else dp[i][j] = dp[i-1][dp[i-1][j]];
        }
    }
}

int lca(int a, int b){
    if(level[a] > level[b])swap(a,b);
    int diff = level[b] - level[a];
    loop(i,0,20)if((diff>>i)&1)b=dp[i][b];
    if(a == b)return b;
    loopr(i,19,0)if(dp[i][a] != dp[i][b])a=dp[i][a],b=dp[i][b];
    return dp[0][a];
}

int distance(int a, int b){
    return lev[a]+lev[b]-2*lev[lca(a,b)];
}

int main(){
    cin >> n;
    loop(i,1,n){
        int a,b,c;
        cin >> a >> b >> c;
        g[a].pb({c,b});
        g[b].pb({c,a});
    }
    dfs(0,-1);
    pre();
    int q;
    cin >> q;
    while(q--){
        int a,b;
        cin >> a >> b;
        cout << distance(a,b) << "\n";
    }
   return 0;
}