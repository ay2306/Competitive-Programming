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
#define ld long double
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

const ll maxn = 1e5;
ll n;
V<PLL> arr;
V<PLL> input;
const ld pi = acos(-1.0);
V<ll> idx;
V<ll> tree;

void update(ll l, ll r, ll val, ll node = 0, ll start = 0, ll end = n-1){
    if(start > r || end < l)return;
    if(start == end){
        tree[node] = val;
        return;
    }
    update(l,r,val,2*node+1,start,(start+end)/2);
    update(l,r,val,2*node+2,(start+end)/2+1,end);
    tree[node] = max(tree[2*node+1],tree[2*node+2]);
}

ll query(ll l, ll r, ll node = 0, ll start = 0, ll end = n-1){
    if(start > r || end < l)return 0;
    if(l <= start && end <= r)return tree[node];
    ll p1 = query(l,r,2*node+1,start,(start+end)/2);
    ll p2 = query(l,r,2*node+2,(start+end)/2+1,end);
    return max(p1,p2);
}

int main(){
    FAST
    cin >> n;
    ll ans = 0;
    arr = V<PLL> (n);
    input = V<PLL> (n);
    idx = V<ll> (n);
    tree = V<ll> (4*n,0);
    loop(i,0,n){
        ld h,r;
        cin >> r >> h;
        arr[i] = mp(r*r*h,i);
        input[i] = mp(r,h);
    }
    sort(arr.begin(), arr.end());
    loop(i,0,n){
        idx[arr[i].S] = i;
    }
    loop(i,0,n){
        ll a = input[i].F * input[i].F * input[i].S;
    ll ans = 0;
        ll x = upper_bound(arr.begin(),arr.end(),mp(a,-1*1LL)) - arr.begin() - 1;
        ll k = query(0,x) + a;
        ans = max(ans,k);
        update(idx[i],idx[i],k);
    }
    ld res = ans*pi;
    cout << fixed << setprecision(10) << res;
    return 0;
}