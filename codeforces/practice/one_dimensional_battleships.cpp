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
ll n,k,a;
ll bn(ll j){
    ll lo = 0;
    ll hi = j;
    ll ans = 0;
    while(lo <= hi){
        ll mi = lo+hi>>1;
        if(mi*a+(mi-1) <= j){
            ans = mi;
            lo = mi+1;
        }else hi = mi - 1;
    }
    return ans;
}

int main(){
    FAST
    cin >> n >> k >> a;
    ll ships = bn(n);
    if(ships < k){
        cout << 0;
        return 0;
    }
    ll ans = 0,q,v;
    set<PLL> s;
    s.insert(mp(1,n));
    cin >> q;
    while(q--){
        ans++;
        cin >> v;
        auto i = s.upper_bound(mp(v,inf));
        if(i == s.begin())continue;
        i--;
        if(!(i->F <= v && v <= i->S))continue;
        ships-=bn(i->S-i->F+1);
        PII p1 = mp(i->F,v-1);
        PII p2 = mp(v+1,i->S);
        s.erase(i);
        if(p1.F <= p1.S)s.insert(p1),ships+=bn(p1.S-p1.F+1);
        if(p2.F <= p2.S)s.insert(p2),ships+=bn(p2.S-p2.F+1);
        if(ships < k){
            cout << ans;
            return 0;
        }
    }
    cout << -1;
   return 0;
}