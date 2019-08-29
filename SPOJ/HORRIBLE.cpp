/*
 ____________________________________________________________
|                                                            |
|                   Author: ay2306                           |
|____________________________________________________________|

*/
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
V<ll> tree;
V<ll> lazy;
int n;

void build(ll node = 0, ll start = 0, ll end = n-1){
    if(start == end){
        tree[node] = arr[start];
        return;
    }
    build(2*node + 1, start, (start+end)/2);
    build(2*node + 2, (start+end)/2 + 1, end);
    tree[node] = tree[2*node + 1] + tree[2*node + 2];
    return;
}

void update(ll l, ll r, ll val, ll node = 0, ll start = 0, ll end = n-1){
    if(lazy[node] != 0){
        tree[node]+=(end-start+1)*lazy[node];
        if(start != end){
            lazy[2*node + 1]+= lazy[node];
            lazy[2*node + 2]+= lazy[node];
        }
        lazy[node] = 0;
    }
    if(start > r || end < l)return;
    if(start >= l && end <= r){
        tree[node]+=(end-start+1)*val;
        if(start != end){
            lazy[2*node + 1]+= val;
            lazy[2*node + 2]+= val;
        }
        return;
    }
    update(l,r,val,2*node+1,start,(start+end)/2);
    update(l,r,val,2*node+2,(start+end)/2+1,end);
    tree[node] = tree[2*node+1] + tree[2*node+2];
}

ll query(ll l, ll r, ll node = 0, ll start = 0, ll end = n-1){
    if(start > r || end < l)return 0;

    if(lazy[node] != 0){
        tree[node]+=(end-start+1)*lazy[node];
        if(start != end){
            lazy[2*node + 1]+= lazy[node];
            lazy[2*node + 2]+= lazy[node];
        }
        lazy[node] = 0;
    }
    if(start >= l && end <= r){
        return tree[node];
    }
    ll p1 = query(l,r,2*node+1,start,(start+end)/2);
    ll p2 = query(l,r,2*node+2,(start+end)/2+1,end);
    return p1+p2;
}

void solve(){
    int q;
    cin >> n >> q;
    arr = V<ll> (n,0);
    tree = V<ll> (4*n);
    lazy = V<ll> (4*n,0);
    while(q--){
        int t,p,q;
        cin >> t >> p >> q;
        if(t == 0){
            ll a ;
            cin >> a;
            update(p-1,q-1,a);
        }else{
            cout << query(p-1,q-1) << "\n";
        }
    }
}

int main(){
    FAST
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}