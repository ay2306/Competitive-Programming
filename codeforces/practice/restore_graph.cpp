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
int n,k;
PII d[maxn+5];
V<int> g[maxn+5];
V<int> lev[maxn+5];
int main(){
    cin >> n >> k;
    loop(i,1,n+1){cin >> d[i].F;d[i].S=i;}
    sort(d+1,d+1+n);
    lev[0].pb(d[1].S);
    V<PII> ans;
    if(d[1].F != 0 || (n > 1 && d[2].F == 0)){
        cout << -1;
        return 0;
    }
    loop(i,2,n+1){
        while(lev[d[i].F-1].size() && g[lev[d[i].F-1].back()].size() == k)lev[d[i].F-1].pop_back();
        if(lev[d[i].F-1].size() == 0){
            cout << -1;
            return 0;
        }
        g[lev[d[i].F-1].back()].pb(d[i].S);
        g[d[i].S].pb(lev[d[i].F-1].back());
        lev[d[i].F].pb(d[i].S);
        ans.pb(mp(lev[d[i].F-1].back(),d[i].S));
    }
    cout << ans.size() << "\n";
    for(auto &i: ans)cout << i.F << " " << i.S << "\n";
   return 0;
}