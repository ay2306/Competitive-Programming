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
const ll inf = 1e15;
const double pi = acos(-1);
int n; ll s;
V<PLL> a;

bool check(ll mi){
    ll sum = 0;
    int c = 0;
    V<ll> v;
    loop(i,0,n){
        if(a[i].S < mi)sum+=a[i].F;
        else if(a[i].F > mi)sum+=a[i].F,c++;
        else v.emplace_back(a[i].F);
    }
    ll req = max(0,(n+1)/2-c); // * Minimum number of elements which should have been greater than mi
    if(req > v.size())return false;
    // printf("mi = %lld, sum = %lld\n",mi,sum);
    sum+=accumulate(v.begin(),v.end()-req,0LL);
    sum+=(req*1LL*mi);
    // printf("mi = %lld, sum = %lld\n",mi,sum);
    return sum <= s;
}

void solve(){
    scanf("%d%lld",&n,&s);
    a.resize(n);
    loop(i,0,n)scanf("%lld%lld",&a[i].F,&a[i].S);
    sort(all(a));
    ll lo = 1;
    ll hi = inf;
    ll ans = 0;
    while(lo <= hi){
        ll mi = lo + hi >> 1;
        if(check(mi)){
            ans = mi;
            lo = mi+1;
        }else hi = mi - 1;
    }
    printf("%lld\n",ans);
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--)solve();
   return 0;
}