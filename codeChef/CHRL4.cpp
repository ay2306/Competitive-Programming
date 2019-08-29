#include <bits/stdc++.h>
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
#define MAXN 25
using namespace std;
V<ll> arr;
V<double> dp;
V<ll> tree;
ll n,k;
void update(ll l, ll r, ll node = 0, ll start = 0, ll end = n-1){
    if(start > r || end < l)return;
    if(l <= start && end <= r){
        tree[node] = start;
        return;
    }
    update(l,r,2*node+1,start,(start+end)/2);
    update(l,r,2*node+2,(start+end)/2+1,end);
    tree[node] = (dp[tree[2*node+1]] < dp[tree[2*node+2]])?tree[2*node+1]:tree[2*node+2];
}
ll query(ll l, ll r, ll node = 0, ll start = 0, ll end = n-1){
    if(start > r || end < l)return LLONG_MAX;
    if(l <= start && end <= r)return tree[node];
    ll p1 = query(l,r,2*node+1,start,(start+end)/2);
    ll p2 = query(l,r,2*node+2,(start+end)/2+1,end);
    if(p1 == LLONG_MAX)return p2;
    if(p2 == LLONG_MAX)return p1;
    if(dp[p1] < dp[p2])return p1;
    return p2;
}

void solve(){
    cin >> n >> k;
    V<ll> parent(n,-1);
    arr = V<ll> (n,0);
    dp = V<double> (n,MOD);
    tree = V<ll> (4*n,LLONG_MAX);
    loop(i,0,n)cin >> arr[i];
    // cout << "5 ";
    dp[0] = log(arr[0]);
    update(0,0);
    for(ll i = 1; i < n; ++i){
        ll mn = query(max(0*1LL,i-k),i-1);
        parent[i] =  mn;
        dp[i] = dp[mn] + log(arr[i]);
        // printf("i = %lld, dp[i] = %lf, parent = %lld\n",i,dp[i],mn);
        update(i,i);
    }
    int x = n-1;
    ll ans = 1;
    while(1){
        // cout << x << " ";
        ans*=arr[x];
        ans%=MOD;
        x = parent[x];
        if(x == -1)break;
    }
    cout << ans;
}

int main(){
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}