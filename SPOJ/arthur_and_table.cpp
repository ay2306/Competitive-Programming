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

int main(){
    int n;
    cin >> n;
    V<PLL> arr(n);
    loop(i,0,n)cin >> arr[i].F;
    loop(i,0,n)cin >> arr[i].S;
    sort(all(arr),greater<PLL>());
    map<ll,ll> e;
    loop(i,0,n)e[arr[i].S]++;
    ll ans = LLONG_MAX;
    ll s = 0;
    int i = 0;
    while(i < n){
        ll cnt = 0;
        ll thispower = 0;
        ll cur = arr[i].F;
        while(arr[i].F==cur){
            thispower+=arr[i].S;
            e[arr[i].S]--;
            cnt++;
            i++;
        }
        ll power = 0;
        ll rst = n-i;
        ll req = cnt/2 - (cnt%2==0);
        ll to_del = max(0LL,rst-req);
        for(auto &j: e){
            if(to_del == 0)break;
            if(j.S >= to_del){
                power+=(to_del*j.F);
                to_del = 0;
                break;
            }else{
                power+=(j.S*j.F);
                to_del -= j.S;
            }
        }
        ans = min(ans,s+power);
        s=thispower;
    }
    cout << ans << "\n";
   return 0;
}