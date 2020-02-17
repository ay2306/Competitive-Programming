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
int n,q,root;
V<int> g[N];
set<int> vec[N];
int subtree[N];
int col[N];
int cnt[N],maxx[N],ans[N];

void dfs(int s, int p){
    subtree[s] = 1;
    for(auto i: g[s]){
        if(i != p){
            dfs(i,s);
            subtree[s]+=subtree[i];
        }
    }
}

void dsu(int v, int p, bool ok){
    int mx = -1, bigchild = -1;
    for(auto i: g[v]){
        if(i != p){
            if(mx < subtree[i])mx=subtree[i],bigchild = i;
        }
    }
    if(bigchild != -1){
        dsu(bigchild,v,true);
        swap(vec[v],vec[bigchild]);
    }
    for(auto i: g[v]){
        if(i == p || i == bigchild)continue;
        dsu(i,v,false);
        for(auto x: vec[i]){
            vec[v].insert(x);
        }
    }
    vec[v].insert(col[v]);
    ans[v] = vec[v].size();
}

int main(){
    cin >> n >> q >> root;
    root--;
    loop(i,1,n){
        int a,b;
        cin >> a >> b;
        g[a-1].pb(b-1);
        g[b-1].pb(a-1);
    }
    loop(i,0,n){
        cin >> col[i];
    }
    dfs(root,-1);
    dsu(root,-1,true);
    loop(i,0,q){
        int a;
        cin >> a;
        cout << ans[a-1] << "\n";
    }
   return 0;
}