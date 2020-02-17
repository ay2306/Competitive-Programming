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
const ll N = 1e6;
const ll inf = 1e9;
const double pi = acos(-1);
int n;
ll lazy[N],tree[N],arr[N];

void build(int node = 0, int start = 0, int end = n-1){
    if(start == end){
        tree[node] = arr[start];
        return;
    }
    int mid = start+end>>1;
    build(2*node+1,start,mid);
    build(2*node+2,mid+1,end);
    tree[node] = min(tree[2*node+1],tree[2*node+2]);
}
void update(int l, int r, ll v, int node = 0, int start = 0, int end = n-1){
    if(lazy[node]){
        tree[node]+=lazy[node];
        if(start != end){
            lazy[2*node+1]+=lazy[node];
            lazy[2*node+2]+=lazy[node];
        }
        lazy[node] = 0;
    }
    if(l > end || r < start)return;
    if(l <= start && end <= r){
        tree[node]+=v;
        if(start != end){
            lazy[2*node+1]+=v;
            lazy[2*node+2]+=v;
        }
        return;
    }
    int mid = start+end>>1;
    update(l,r,v,2*node+1,start,mid);
    update(l,r,v,2*node+2,mid+1,end);
    tree[node] = min(tree[2*node+1],tree[2*node+2]);
}

ll query(int l, int r, int node = 0, int start = 0, int end = n-1){
    if(lazy[node]){
        tree[node]+=lazy[node];
        if(start != end){
            lazy[2*node+1]+=lazy[node];
            lazy[2*node+2]+=lazy[node];
        }
        lazy[node] = 0;
    }
    if(l > end || r < start)return LLONG_MAX;
    if(l <= start && end <= r){
        return tree[node];
    }
    int mid = start+end>>1;
    ll p1 = query(l,r,2*node+1,start,mid);
    ll p2 = query(l,r,2*node+2,mid+1,end);
    return min(p1,p2);
}

int main(){
    FAST
    cin >> n;
    loop(i,0,n)cin >> arr[i];
    build();
    int q;
    cin >> q;
    cin.ignore();
    string s;
    while(q--){
        getline(cin,s);
        stringstream a(s);
        ll x;
        V<ll> k;
        while(a >> x){
            k.pb(x);
        }
        if(k.size() == 2){
            if(k[1] < k[0]){
                cout << min(query(k[0],n-1),query(0,k[1])) << "\n";
            }else{
                cout << query(k[0],k[1]) << "\n";
            }
        }else{
            if(k[1] < k[0]){
                update(k[0],n-1,k[2]);
                update(0,k[1],k[2]);
            }else{
                update(k[0],k[1],k[2]);
            }
        }
    }
   return 0;
}