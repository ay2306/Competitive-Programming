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
const ll inf = 1e7;
const double pi = acos(-1);
struct trap{
    ll pos;
    ll dis;
    ll lev;
};
int main(){
    FAST
    ll m,n,k,t;
    cin >> m >> n >> k >> t;
    V<trap> arr;
    V<ll> ag(m);
    loop(i,0,m)cin >> ag[i];
    while(k--){
        ll l,r,d;
        cin >> l >> r >> d;
        trap a;
        a.pos = l;
        a.dis = r;
        a.lev = d;
        arr.pb(a);
    }
    ll low = 0;
    ll high = *max_element(all(ag)) + 1;
    ll min_ag = high;
    while(low <= high){
        ll mid = (low+high) >> 1;
        ll max_dist = 0;
        ll min_dist = inf;
        ll tot = 0;
        for(auto i: arr){
            if(i.lev > mid){max_dist=max(max_dist,i.dis),min_dist=min(min_dist,i.pos);}
        }
        if(min_dist == inf){
            max_dist = min_dist;
        }else{
            min_dist--;
        }
        tot+=n+1;
        tot+=(max_dist-min_dist);
        tot+=(max_dist-min_dist);
        if(min_dist == inf)tot = -10;
        if(tot <= t){
            high = mid-1;
            min_ag = min(mid,min_ag);
        }else{
            low = mid+1;
        }
    }
    int ans = 0;
    for(auto i: ag)if(min_ag <= i)ans++;
    std::cout << ans;
   return 0;
}