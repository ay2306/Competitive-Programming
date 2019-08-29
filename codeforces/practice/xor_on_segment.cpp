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
V<int> arr;
class bit{
    int bit_number;
    V<int> tree;
    V<int> lazy;
public:
    bit(){}
    void __init(int bit_number){
        this->bit_number = bit_number;
        tree = V<int> ((arr.size() << 2),0);
        lazy = V<int> ((arr.size() << 2),0);
        build();
    }
    void build(int node = 0, int start = 0, int end = arr.size()-1){
        if(start == end){
            tree[node] = ((arr[start] & (1 << bit_number)) > 0);
            return;
        }
        build(2*node+1,start,((start+end)>>1));
        build(2*node+2,((start+end)>>1)+1,end);
        tree[node] = tree[2*node+1] + tree[2*node+2];
    }
    void update(int l, int r, int node = 0, int start = 0, int end = arr.size()-1){
        if(lazy[node] != 0){
            tree[node] = (end-start+1)-tree[node];
            if(start != end){
                lazy[2*node+1]^=1;
                lazy[2*node+2]^=1;
            }
            lazy[node] = 0;
        }
        if(start > r || end < l)return;
        if(l <= start && end <= r){
            tree[node] = (end-start+1)-tree[node];
            if(start != end){
                lazy[2*node+1]^=1;
                lazy[2*node+2]^=1;
            }
            return;
        }
        update(l,r,2*node+1,start,((start+end)>>1));
        update(l,r,2*node+2,((start+end)>>1)+1,end);
        tree[node] = tree[2*node+1] + tree[2*node+2];
    }
    int query(int l, int r, int node = 0, int start = 0, int end = arr.size()-1){
        if(lazy[node] != 0){
            tree[node] = (end-start+1)-tree[node];
            if(start != end){
                lazy[2*node+1]^=1;
                lazy[2*node+2]^=1;
            }
            lazy[node] = 0;
        }
        if(start > r || end < l)return 0;
        if(l <= start && end <= r){
            return tree[node];
        }
        return query(l,r,2*node+1,start,((start+end)>>1)) + query(l,r,2*node+2,((start+end)>>1)+1,end);
    }
};

ll power(ll n){
    if(n == 0)return 1;
    if(n == 1)return 2;
    ll p = power(n/2);
    p*=p;
    if(n%2)p*=2;
    return p;
}

int main(){
    FAST
    int n;
    cin >> n;
    arr = V<int> (n);
    loop(i,0,n)cin >> arr[i];
    V<bit> tree(21);
    loop(i,0,21){
        tree[i].__init(i);
    }
    int q;
    cin >> q;
    while(q--){
        int t,l,r;
        cin >> t >> l >> r;
        l--;
        r--;
        if(t == 1){
            ll ans = 0;
            loop(i,0,21){
                ans+=(tree[i].query(l,r)*power(i));
            }
            cout << ans << "\n";
        }else{
            int x;
            cin >> x;
            loop(i,0,21){
                if((x & (1 << i)) == 0)continue;
                tree[i].update(l,r);
            }
        }
    }
   return 0;
}