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
ll n;
int ct = 1;
V<ll> arr;
V<ll> tree;
V<bool> lazy;
bool going;
void build(ll node = 0, ll start = 0, ll end = n-1){
    if(start == end){
        tree[node] = arr[start];
        if(tree[node] == 1)lazy[node] = true;
        return;
    }
    build(2*node+1,start,(start+end)/2);
    build(2*node+2,(start+end)/2+1,end);
    lazy[node] = (lazy[2*node+1] && lazy[2*node+2]);
    tree[node] = tree[2*node+1] + tree[2*node+2];
}

ll query(ll l, ll r, ll node = 0, ll start = 0, ll end = n-1){
    if(start > r || end < l)return 0;
    if(l<=start && end <= r)return tree[node];
    ll p1 = query(l,r,2*node+1,start,(start+end)/2);
    ll p2 = query(l,r,2*node+2,(start+end)/2+1,end);
    return p1+p2;
}

void update(ll l, ll r, ll node = 0, ll start = 0, ll end = n-1){
    // cout << "UPDATE: " << l << " " << r << " " << node << " " << start << " " << end << endl;
    if(start > r || end < l)return;
    if(start == end){ 
        arr[start] = sqrt(arr[start]);
        tree[node] = arr[start];
        if(tree[node] == 1)lazy[node] = true;
        return;
    }
    if(lazy[node])return;
    update(l,r,2*node+1,start,(start+end)/2);
    update(l,r,2*node+2,(start+end)/2+1,end);
    lazy[node] = (lazy[2*node+1] && lazy[2*node+2]);
    tree[node] = tree[2*node+1] + tree[2*node+2];
    return;
}

void solve(){
    if(cin >> n){
        if(ct > 1)cout << "\n";
        cout << "Case #" << ct++ << ":\n";

    }else{
        going = false;
        return;
    }
    tree = V<ll> (4*n);
    arr = V<ll> (n);
    lazy = V<bool> (4*n,false);
    loop(i,0,n)cin >> arr[i];
    ll q;
    cin >> q;
    build();
    while(q--){
        ll t,l,r;
        cin >> t >> l >> r;
        l--;
        r--;
        if(l > r)swap(l,r);
        // cout << l << " " << r << " " << n << endl;
        if(t == 0)update(l,r);
        else cout << query(l,r) << "\n";
    }

}

int main(){
    FAST
    // FILE_READ_IN
    // FILE_READ_OUT
    ll t;
    going = true;
    while(going){
        solve();
    }
    return 0;
}