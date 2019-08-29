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
using namespace std;

const ll n = 2e5;
V<ll> tree;
V<ll> lazy;
void update(ll l, ll r, ll val, ll node = 0, ll start = 0, ll end = n-1){
    if(lazy[node] != 0){
        tree[node] = lazy[node];
        if(start != end){
            lazy[2*node+1] = lazy[node];
            lazy[2*node+2] = lazy[node];
        }
        lazy[node] = 0;
    }
    if(start > r || end < l)return;
    if(l <= start && end <= r){
        tree[node] = val;
        if(start != end){
            lazy[2*node+1] = tree[node];
            lazy[2*node+2] = tree[node];
        }
        return;
    }
    update(l,r,val,2*node+1,start,(start+end)/2);
    update(l,r,val,2*node+2,(start+end)/2+1,end);
    tree[node] = max(tree[2*node+1],tree[2*node+2]);
}

ll query(ll l, ll r, ll node = 0, ll start = 0, ll end = n-1){
    if(r < l)return LLONG_MIN;
    if(lazy[node] != 0){
        tree[node] = lazy[node];
        if(start != end){
            lazy[2*node+1] = lazy[node];
            lazy[2*node+2] = lazy[node];
        }
        lazy[node] = 0;
    }
    if(start > r || end < l)return LLONG_MAX;
    if(l <= start && end <= r){
        return tree[node];
    }
    ll p1 = query(l,r,2*node+1,start,(start+end)/2);
    ll p2 = query(l,r,2*node+2,(start+end)/2+1,end);
    return max(p1,p2);    
}

int main(){
    ll m;
    cin >> m;
    tree = V<ll> (4*n,0);
    lazy = V<ll> (4*n,0);
    ll l,h,p,c,x;
    while(m--){
        cin >> l >> h >> p >> c >> x;
        if(c == 0){
            ll q1 = query(x,x+p-2);
            ll q2 = query(x+p,x+l-1);
            ll q3 = query(x+p-1,x+p-1);
            ll nh = max(q1,max(q2,q3+h))+1;
            update(x,x+l-1,nh);
        }
        else if(c == 1){
            ll q = query(x,x+l-1)+1;
            update(x,x+l-1,q);
            update(x+p-1,x+p-1,q+h);
        }
    }
    cout << query(0,150000);
    return 0;
}