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
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);

int main(){
    // FILE_READ_OUT
    FAST
    ll n,q;
    cin >> n >> q;
    list<ll> arr;
    unordered_map<ll,PLL> m;
    loop(i,0,n){
        ll a;
        cin >> a;
        arr.pb(a);
    }
    loop(i,0,n-1){
        ll a = arr.front();
        arr.pop_front();
        ll b = arr.front();
        arr.pop_front();
        m[i+1] = mp(a,b);
        arr.push_back(min(a,b));
        arr.push_front(max(a,b));
    }
    V<ll> a(n-1);
    ll mx = arr.front();
    arr.pop_front();
    loop(i,0,n-1){
        a[i] = arr.front();
        arr.pop_front();
    }
    while(q--){
        ll k;
        cin >> k;
        if(k <= n-1){
            cout << m[k].F << " " << m[k].S << "\n";
        }else{
            cout << mx << " " << a[(k-1)%(n-1)] << "\n";
        }
    }
    return 0;
}