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
V<ll> Tree;
int n;
void update(int ind, int val, int node = 0, int start = 0, int end = n-1){
    if(start == end){
        Tree[node]=val;
        return;
    }
    int mid = start+end>>1;
    if(ind <= mid)update(ind,val,2*node+1,start,mid);
    if(ind > mid)update(ind,val,2*node+2,mid+1,end);
    Tree[node] = Tree[2*node+1]+Tree[2*node+2];
}

ll query(int l, int r, int node = 0, int start = 0, int end=n-1){
    if(l > end || r < start)return 0;
    if(l <= start && end <= r)return Tree[node];
    int mid = start+end>>1;
    return query(l,r,2*node+1,start,mid)+query(l,r,2*node+2,mid+1,end);
}

int main(){
    FAST
    cin >> n;
    map<int,int> m;
    ord_set<int> s;
    V<int> arr(n);
    Tree = V<ll> (n<<2,0);
    loop(i,0,n)cin >> arr[i],m[arr[i]]=1;
    int cnt = 1;
    for(auto i: m){
        m[i.F]=cnt++;
    }
    loop(i,0,n)arr[i]=m[arr[i]];
    reverse(all(arr));
    ll ans = 0;
    loop(i,0,n){
        ans+=query(0,arr[i]-1);
        s.insert(arr[i]);
        update(arr[i]-1,s.order_of_key(arr[i]));
        // cout << arr[i] << " Tree: "; for(auto j: Tree)cout << j << " "; cout << endl;
    }
    cout << ans << "\n";
   return 0;
}