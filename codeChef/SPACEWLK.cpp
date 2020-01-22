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
const int N = 3e5+10;
const int sz = 350;
ll b[N],a[N];
PLL blk[sz],c[N];

ll mult(ll a,ll b){ return ((a*1LL*b)%MOD);}
void update(ll l, ll r, ll x, ll y){
    int i = l/sz;
    for(int j = i*sz; j < (i+1)*sz; ++j){
        b[j]=mult(b[j],blk[i].F)+blk[i].S;
        b[j]%=MOD;
    }
    blk[i] = {1,0};
    i = r/sz;
    for(int j = i*sz; j < (i+1)*sz; ++j){
        b[j]=mult(b[j],blk[i].F)+blk[i].S;
        b[j]%=MOD;
    }
    blk[i] = {1,0};
    while(l <= r && l%sz!=0){
        b[l]=mult(b[l],x)+y;
        b[l]%=MOD;
        l++;
    }
    while(l <= r && (r+1)%sz!=0){
        b[r]=mult(b[r],x)+y;
        b[r]%=MOD;
        r--;
    }
    while(l<r){
        int i = l/sz;
        blk[i].F = mult(blk[i].F,x);
        blk[i].S = mult(blk[i].S,x) + y;
        blk[i].S%=MOD;
        l+=sz;
    }
}

int main(){
    FAST
    fill(blk,blk+sz,make_pair(1,0));
    int n,q;
    cin >> n >> q;
    loop(i,0,n)cin >> a[i],c[i]={a[i],i};
    sort(a,a+n);
    sort(c,c+n);
    while(q--){
        ll l,r,x,y;
        cin >> l >> r >> x >> y;
        int i = lower_bound(a,a+n,l)-a;
        int j = upper_bound(a,a+n,r)-a-1;
        if(i > j)continue;
        update(i,j,x%MOD,y%MOD);
    }
    ll ans[n];
    loop(i,0,n){
        ans[c[i].S] = (mult(b[i],blk[i/sz].F) + blk[i/sz].S)%MOD ;
    }
    loop(i,0,n){
        cout << ans[i] << " ";
    }
   return 0;
}