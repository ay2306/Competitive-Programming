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
const ll N = 5e5 + 10;
const ll inf = 1e9;
const double pi = acos(-1);
int n;
PLL a[N];
V<int> g[N];
bool vis[N];

void dfs(int s = 0, int p = -1){
    // printf("%d => ",s);
    vis[s] = true;
    for(auto v: g[s]){
        if(v != p && !vis[v]){
            dfs(v,s);
        }
    }
}

int main(){
    FAST
    cin >> n;
    loop(i,0,n)cin >> a[i].F >> a[i].S;
    V<PLL> evs;
    loop(i,0,n){
        evs.pb(mp(a[i].F,i));
        evs.pb(mp(a[i].S,i));
    }
    sort(all(evs));
    int cnt = 0;
    set<PLL> cur;
    for(auto it: evs){
        // printf("it = (%lld, %lld) For segment = (%lld, %lld)\n",it.F,it.S,a[it.S].F,a[it.S].S);
        if(cnt >= n)break;
        if(cur.count(it)){
            // printf("Already in cur\n");
            cur.erase(it);
        }else{
            int i = it.S;
            int r = a[i].S;
            for(auto jt: cur){
                if(jt.F > r)break;
                // printf("jt = (%lld, %lld)\n",jt.F,jt.S);
                int j = jt.S;
                g[i].pb(j);
                g[j].pb(i);
                cnt++;
                if(cnt >= n)break;
            }
            cur.insert(mp(a[i].S,i));
        }
    }
    dfs();
    // printf("\n");
    if(cnt == n-1 && accumulate(vis,vis+n,0)==n)cout << "YES\n";
    else cout << "NO\n";
   return 0;
}