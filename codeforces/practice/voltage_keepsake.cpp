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
using namespace std;
#define PDD pair<ld,ld>
int main(){
    FAST
    ll n,p;
    cin >> n >> p;
    V<PDD> a(n);
    loop(i,0,n)cin >> a[i].F >> a[i].S;
    ld s = 0;
    loop(i,0,n)s+=a[i].F;
    if(s <= p){
        cout << -1;
        return 0;
    }
    ld low = 0;
    ld high = 1e18;
    ld ans = 0;
    ld z = 0;
    while(high-low >= 1e-6){
        ld mid = (low+high)/2.0;
        ld cons = 0.0;
        loop(i,0,n)cons+=max((a[i].F*mid)-a[i].S,z);
        ld avail = p*mid;
        // printf("mid = %Lf, cons = %Lf, avail = %Lf\n",mid,cons,avail);
        if(avail-cons >= 1e-9){
            low = mid;
            ans = max(ans,mid);
        }else{
            high = mid;
        }
    }
    printf("%.10Lf",ans);
    return 0;
}