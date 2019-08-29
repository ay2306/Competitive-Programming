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
int n;
V<V<PLL> > adj;
V<ll> arr;
V<ll> harr;
V<ll> first;
map<PLL,ll> m;
V<ll> min_tree;
V<ll> max_tree;
void dfs(ll s = 0, ll p = -1){
    arr.pb(s);
    for(auto i: adj[s]){
        if(i.F == p)continue;
        dfs(i.F,s);
        arr.pb(s);
    }
}

void build(ll node = 0, ll start = 0, ll end = harr.size()-1){
    if(start == end){
        min_tree[node] = harr[start];
        max_tree[node] = harr[start];
        return;
    }
    build(2*node+1,start,(start+end)/2);
    build(2*node+2,(start+end)/2+1,end);
    max_tree[node] = max(max_tree[2*node+1],max_tree[2*node+2]);
    min_tree[node] = min(min_tree[2*node+1],min_tree[2*node+2]);
}

ll query(ll l, ll r, ll node = 0, ll start = 0, ll end = harr.size()-1){
    if(start > r || end < l)return LLONG_MAX;
    if(l <= start && end <= r)return min_tree[node];
    ll a = query(l,r,2*node+1,start,(start+end)/2);
    ll b = query(l,r,2*node+2,(start+end)/2+1,end);
    return min(a,b);
}
ll query1(ll l, ll r, ll node = 0, ll start = 0, ll end = harr.size()-1){
    if(start > r || end < l)return LLONG_MIN;
    if(l <= start && end <= r)return max_tree[node];
    ll a = query1(l,r,2*node+1,start,(start+end)/2);
    ll b = query1(l,r,2*node+2,(start+end)/2+1,end);
    return max(a,b);
}

int main(){
    FAST
    cin >> n;
    adj = V<V<PLL> > (n);
    first = V<ll> (n,-1);
    loop(i,1,n){
        ll a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        adj[a].pb(mp(b,c));
        adj[b].pb(mp(a,c));
        m[mp(a,b)] = c;
        m[mp(b,a)] = c;
    }
    dfs();
    for(int i = 0; i < arr.size(); ++i){
        if(first[arr[i]] == -1)first[arr[i]] = i;
    }
    for(int i  = 1; i < arr.size(); ++i){
        ll a = arr[i-1];
        ll b = arr[i];
        harr.pb(m[mp(a,b)]);
    }
    cout << "ARR: ";
    for(auto i: arr)cout << i+1 << " ";
    cout << "\n";
    cout << "First: ";
    for(auto i: first)cout << i << " ";
    cout << "\n";
    cout << "HARR ";
    for(auto i: harr)cout << i << " ";
    cout << "\n";
    max_tree = V<ll> (4*harr.size());
    min_tree = V<ll> (4*harr.size());
    build();
    int q;
    cin >> q;
    while(q--){
        int a,b;
        cin >> a >> b;
        a = first[a-1];
        b = first[b-1];
        if(a > b)swap(a,b);
        b--;
        cout << a << " " << b << "\n";
        cout << query(a,b) << " " << query1(a,b) << "\n";

    }
    return 0;
}