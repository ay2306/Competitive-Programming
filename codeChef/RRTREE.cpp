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
const ll N = 1e5+10;
const ll inf = 1e9;
const double pi = acos(-1);
int ancestor[20][N];
V<int> adj[N];
int level[N];

void setNode(int k, int p){
    ancestor[0][k] = p;
    level[k] = (p == -1 ? 0 : level[p]+1);
    loop(j,1,20){
        if(ancestor[j-1][k] != -1)ancestor[j][k] = ancestor[j-1][ancestor[j-1][k]];
    }
}

int findLCA(int a, int b){
    if(level[a] > level[b])swap(a,b);
    int diff = level[b]-level[a];
    loop(j,0,20){
        if((diff>>j)&1)b=ancestor[j][b];
    }
    if(a == b)return b;
    loopr(j,19,0){
        if(ancestor[j][a] != ancestor[j][b]){
            b = ancestor[j][b];
            a = ancestor[j][a];
        }
    }
    return ancestor[0][a];
}

int distance(int a, int b){
    int l = findLCA(a,b);
    if(l == a || l == b){
        return abs(level[a]-level[b]);
    }
    return (level[a] + level[b] - 2*level[l]);
}

void solve(){
    memset(ancestor,-1,sizeof(ancestor));
    int n;
    cin >> n;
    setNode(1,-1);
    int v1 = 1;
    int v2 = 1;
    int ans = 0;
    loop(i,2,n+1){
        int p;
        cin >> p;
        setNode(i,p);
        int v3 = i;
        int d1 = distance(v1,v3);
        int d2 = distance(v2,v3);
        if(d1 > ans && d1 > d2)v2=i,ans=d1;
        if(d2 > ans)v1=i,ans=d2;
        cout << ans << "\n";
    }
}

int main(){
    FAST
    int t;
    cin >> t;
    while(t--)solve();
   return 0;
}