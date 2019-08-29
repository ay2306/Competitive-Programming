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
#define ord_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
const ll maxn = 1e5;
ll x;
V<ll> flavor;
V<ll> option;
ll ans = LLONG_MAX;
ll diff = LLONG_MAX;
void rec(ll i, ll cost, int choosen){
    if(choosen > 2)return;
    if(abs(cost-x) < diff){
        ans = cost;
        diff = abs(cost-x);
    }else if(abs(cost-x) == diff){
        ans = min(cost,ans);
    }
    if(choosen == 2 || i == option.size()){
        return;
    }
    rec(i+1,cost+option[i],choosen+1);
    rec(i+1,cost,choosen);
}

void solve(){
    ans = LLONG_MAX;
    diff = LLONG_MAX;
    cin >> x;
    ll n;
    cin >> n;
    flavor = V<ll> ();
    option = V<ll> ();
    loop(i,0,n){
        string a;
        cin >> a;
        ll p;
        cin >> p;
        flavor.pb(p);
    }
    cin >> n;
    loop(i,0,n){
        string a;
        cin >> a;
        ll p;
        cin >> p;
        option.pb(p);
    }
    for(int i = 0; i < flavor.size(); ++i){
        rec(0,flavor[i],0);
    }
    printf("%lld\n",ans);
}

int main(){
    freopen("main_input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin >> t;
    loop(i,1,t+1){
        printf("Case #%d: ",i);
        solve();
    }
    return 0;
}