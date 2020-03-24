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
const ll N = 1e5+100;
const ll inf = 1e9;
const double pi = acos(-1);

V<int> g[N];
int lev[N];
V<int> p;
int n,m,d;
int dp[20][N];
void dfs(int s, int p = -1){
    ((p == -1)?lev[s]=0:lev[s]=lev[p]+1);
    dp[0][s] = p;
    for(auto &i: g[s]){
        if(i != p)dfs(i,s);
    }
}

void pre(){
    loop(i,1,20){
        loop(j,1,n+1){
            if(dp[i-1][j] == -1)dp[i][j] = -1;
            else dp[i][j] = dp[i-1][dp[i-1][j]];
        }
    }
}

int lca(int a, int b){
    if(lev[a] > lev[b])swap(a,b);
    int diff = lev[b]-lev[a];
    loop(i,0,20)if((diff>>i)&1)b=dp[i][b];
    if(a == b)return a;
    loopr(i,19,0){
        if(dp[i][a] != dp[i][b]){
            a = dp[i][a];
            b = dp[i][b];
        }
    }
    return dp[0][a];
}

int dist(int a, int b){
    // printf("lev[%d] = %d, lev[%d] = %d, lev[lca=%d] = %d\n",a,lev[a],b,lev[b],lca(a,b),lev[lca(a,b)]);
    return lev[a]+lev[b]-2*lev[lca(a,b)];
}

int main(){
    scanf("%d%d%d",&n,&m,&d);
    loop(i,0,m){
        int a;
        scanf("%d",&a);
        p.emplace_back(a);
    }
    loop(i,1,n){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    dfs(1);
    int mxi = p[0];
    loop(i,1,m)if(lev[mxi] < lev[p[i]])mxi=p[i];
    int a = mxi;
    dfs(a);
    mxi = p[0];
    loop(i,1,m)if(lev[mxi] < lev[p[i]])mxi=p[i];
    int b = mxi;
    int ans = 0;
    pre();
    // printf("a = %d, b = %d\n",a,b);
    loop(i,1,n+1){
        // printf("dist(%d,%d) = %d, dist(%d,%d) = %d\n",i,a,dist(a,i),i,b,dist(i,b));
        if(dist(a,i) <= d && dist(b,i) <= d){
            ans++;
        }
    }
    cout << ans;
   return 0;
}