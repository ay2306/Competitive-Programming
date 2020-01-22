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
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);
int n;
V<ll> arr;
V<P<PLL,ll>> q;
class stree1{
    V<ll> tree;
    V<ll> lazy;
    public:
        stree1(){
            tree = V<ll> (n << 2,0);
            lazy = V<ll> (n << 2,0);
        }
        void update(int l, int r, ll mask, int node = 0,int start = 0, int end = n-1){
            if(lazy[node]){
                tree[node]|=lazy[node];
                if(start!=end){
                    lazy[2*node+1]|=lazy[node];
                    lazy[2*node+2]|=lazy[node];
                }
                lazy[node]=0;
            }
            if(end < l || start > r)return;
            if(l <= start && end <= r){
                tree[node]|=mask;
                if(start != end){
                    lazy[2*node+1]|=mask;
                    lazy[2*node+2]|=mask;
                }
                return;
            }
            int mid = start+end>>1;
            update(l,r,mask,2*node+1,start,mid);
            update(l,r,mask,2*node+2,mid+1,end);
            tree[node] = (tree[2*node+1]|tree[2*node+2]);
        }
        ll query(int l, int r, int node = 0,int start = 0, int end = n-1){
            if(lazy[node]){
                tree[node]|=lazy[node];
                if(start!=end){
                    lazy[2*node+1]|=lazy[node];
                    lazy[2*node+2]|=lazy[node];
                }
                lazy[node]=0;
            }
            if(end < l || start > r)return 0;
            if(l <= start && end <= r){
                return tree[node];
            }
            int mid = start+end>>1;
            ll a = query(l,r,2*node+1,start,mid);
            ll b = query(l,r,2*node+2,mid+1,end);
            return (a|b);
        }
};
class stree2{
    V<ll> tree;
    public:
        stree2(){
            tree = V<ll> (n << 2,0);
        }
        void build(int node = 0,int start = 0, int end = n-1){
            if(start == end){
                tree[node] = arr[start];
                return;
            }
            int mid = start+end>>1;
            build(2*node+1,start,mid);
            build(2*node+2,mid+1,end);
            tree[node] = (tree[2*node+1]&tree[2*node+2]);
        }
        ll query(int l, int r, int node = 0,int start = 0, int end = n-1){
            if(end < l || start > r)return LLONG_MAX;
            if(l <= start && end <= r){
                return tree[node];
            }
            int mid = start+end>>1;
            ll a = query(l,r,2*node+1,start,mid);
            ll b = query(l,r,2*node+2,mid+1,end);
            return (a&b);
        }
};
int main(){
    FAST
    int m;
    cin >> n >> m;
    arr = V<ll> (n,0);
    q = V<P<PLL,ll>> (m);
    stree1 s1;
    stree2 s2;
    loop(i,0,m){
        cin >> q[i].F.F >> q[i].F.S >> q[i].S;
        q[i].F.F--;
        q[i].F.S--;
        s1.update(q[i].F.F,q[i].F.S,q[i].S);
    }
    loop(i,0,n){
        arr[i] = s1.query(i,i);
    }
    s2.build();
    loop(i,0,m){
        if(s2.query(q[i].F.F,q[i].F.S) != q[i].S){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES\n";
    loop(i,0,n)cout << arr[i] << " ";
   return 0;
}