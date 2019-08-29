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

void solve(){
    string a;
    cin >> a;
    int o = 1;
    int z = o*o;
    ll ans = 0;
    unordered_map<char,int> f;
    for(auto &i: a)f[i]++;
    int g = min(f['1'],int(sqrt(f['0'])));
    V<int> oc(a.size(),0);
    oc[0] = (a[0] == '1');
    V<int> zc(a.size(),0);
    zc[0] = (a[0] == '0');
    loop(i,1,a.size()){
        oc[i] = oc[i-1] + (a[i] == '1');
        zc[i] = zc[i-1] + (a[i] == '0');
    }
    while(o+z <= a.length() && o <= g){
        int l = o + z;
        ans+=(zc[l-1] == oc[l-1]*oc[l-1]);
        for(int i = l; i < a.size(); ++i){
            ans+=((zc[i]-zc[i-l]) == ((oc[i]-oc[i-l])*(oc[i]-oc[i-l])));
        }
        o++;
        z = o*o;
    }
    cout << ans << "\n";
}

int main(){
    FAST
    int t;
    cin >> t;
    while(t--){
        solve();
    }
   return 0;
}