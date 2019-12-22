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
const double eps = 1e-6;
ll dist(PLL a, PLL b,bool display = false){
    if(display){
        printf("p1 = (%lld, %lld) , p2= (%lld, %lld) , distance = %.10f\n",a.F,a.S,b.F,b.S,sqrt((a.F-b.F)*(a.F-b.F) + (a.S-b.S)*(a.S-b.S)));
    }
    return (a.F-b.F)*(a.F-b.F) + (a.S-b.S)*(a.S-b.S);
}
void solve(){
    int n,m,k;
    PLL x;
    scanf("%lld %lld",&x.F,&x.S);
    scanf("%d %d %d",&n,&m,&k);
    V<PLL> a(n),b(m),c(k);
    loop(i,0,n)scanf("%lld %lld",&a[i].F,&a[i].S);
    loop(i,0,m)scanf("%lld %lld",&b[i].F,&b[i].S);
    loop(i,0,k)scanf("%lld %lld",&c[i].F,&c[i].S);
    V<int> ac(n),bc(m);
    loop(i,0,n){
        ac[i] = 0;
        ll current = dist(a[i],c[0]);
        loop(j,1,k){
            ll dis = dist(a[i],c[j]);
            if(current > dis){
                ac[i] = j;
            }
        }
    }
    loop(i,0,m){
        bc[i] = 0;
        ll current = dist(b[i],c[0]);
        loop(j,1,k){
            double dis = dist(b[i],c[j]);
            if(current > dis){
                bc[i] = j;
            }
        }
    }
    double ans = LLONG_MAX;
    loop(i,0,n){
        ll o_a = dist(x,a[i]);
        loop(j,0,m){
            ll o_b = dist(x,b[j]);
            ll a_b = dist(a[i],b[j]);
            ans = min({ans, sqrt(o_a) + sqrt(a_b) + sqrt(dist(c[bc[j]],b[j])), sqrt(o_b) + sqrt(a_b) + sqrt(dist(c[ac[i]],a[j]))});
        }
    }
    printf("%.10f\n",ans);
}

int main(){
    // FAST
   int t = 0;
   cin >> t;
   while(t--){
       solve();
   }
   return 0;
}