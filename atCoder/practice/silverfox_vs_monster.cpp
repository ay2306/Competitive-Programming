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
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);
V<ll> tree;
V<ll> lazy;
V<int> arr;
int n;

void update(int l, int r, int val, int node = 0, int start = 0, int end = n-1){
    if(lazy[node]){
        tree[node]+=lazy[node];
        if(start != end){
            lazy[2*node+1]+=lazy[node];
            lazy[2*node+2]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(l > end || r < start)return;
    if(l <= start && end <= r){
        tree[node]+=val;
        if(start != end){
            lazy[2*node+1]+=val;
            lazy[2*node+2]+=val;
        }
        return ;
    }
    int mid = start+end>>1;
    update(l,r,val,2*node+1,start,mid);
    update(l,r,val,2*node+2,mid+1,end);

}

ll query(int l, int r, int node = 0, int start=0, int end = n-1){
    if(lazy[node]){
        tree[node]+=lazy[node];
        if(start != end){
            lazy[2*node+1]+=lazy[node];
            lazy[2*node+2]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(l > end || r < start)return 0;
    if(l <= start && end <= r){
        return tree[node];
    }
    int mid = start+end>>1;
    auto p1 = query(l,r,2*node+1,start,mid);
    auto p2 = query(l,r,2*node+2,mid+1,end);
    return p1+p2;
}

int main(){
    ll d,a;
    cin >> n >> d >> a;
    tree = V<ll>(n<<2,0);
    lazy = V<ll>(n<<2,0);
    V<PLL> arr(n);
    loop(i,0,n)cin >> arr[i].F >> arr[i].S;
    sort(all(arr));
    ll ans = 0;
    loop(i,0,n){
        if(arr[i].S - query(i,i) <= 0)continue;
        int r = upper_bound(all(arr),mp(arr[i].F+d+d,inf))-arr.begin();
        r--;
        ll current_val = arr[i].S - query(i,i);
        ll to_del = current_val/a + (current_val%a != 0);
        ans+=to_del;
        to_del*=a;
        update(i,r,to_del);
    }
    cout << ans;
   return 0;
}