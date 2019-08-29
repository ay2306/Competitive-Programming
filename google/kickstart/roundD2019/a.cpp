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
V<int> tree;
V<int> lazy;
V<ll> arr;
V<int> b;

struct node{
    int left1;
    int left0;
    int right1;
    int right0;
    void display(){
    }
    void reverse(){
        swap(left1,left0);
        swap(right1,right0);
    }
};

V<struct node> Data;

void build(int node = 0, int start = 0, int end = n-1){
    if(start == end){
       tree[node] = b[start];
       if(b[start] == 1){
        Data[node].left1 = start;
        Data[node].left0 = n+1;
        Data[node].right0 = -1;
        Data[node].right1 = start;
       }
       if(b[start] == 0){
        Data[node].left0 = start;
        Data[node].left1 = n+1;
        Data[node].right1 = -1;
        Data[node].right0 = start;
       }
        return;
    }
    build(2*node+1,start,(start+end)>>1);
    build(2*node+2,((start+end)>>1)+1,end);
    tree[node] = tree[2*node+1] + tree[2*node+2];
    Data[node].left1 = min(Data[2*node+1].left1,Data[2*node+2].left1);
    Data[node].right1 = max(Data[2*node+1].right1,Data[2*node+2].right1);
    Data[node].left0 = min(Data[2*node+1].left0,Data[2*node+2].left0);
    Data[node].right0 = max(Data[2*node+1].right0,Data[2*node+2].right0);
}

void update(int l, int r, int node = 0, int start = 0, int end = n-1){
    if(lazy[node] == 1){
        tree[node] = (end-start+1)-tree[node];
        Data[node].reverse();
        if(start != end){
            lazy[2*node+1]^=1;
            lazy[2*node+2]^=1;
        }
        lazy[node] = 0;
    }
    if(start > r || end < l)return;
    if(l <= start && end <= r){
        tree[node] = (end-start+1)-tree[node];
        Data[node].reverse();
        if(start != end){
            lazy[2*node+1]^=1;
            lazy[2*node+2]^=1;
        }
        return;
    }

    update(l,r,2*node+1,start,(start+end)>>1);
    update(l,r,2*node+2,((start+end)>>1)+1,end);
    tree[node] = tree[2*node+1] + tree[2*node+2];
    Data[node].left1 = min(Data[2*node+1].left1,Data[2*node+2].left1);
    Data[node].right1 = max(Data[2*node+1].right1,Data[2*node+2].right1);
    Data[node].left0 = min(Data[2*node+1].left0,Data[2*node+2].left0);
    Data[node].right0 = max(Data[2*node+1].right0,Data[2*node+2].right0);
}

int query_left1(int l, int r, int node = 0, int start = 0, int end = n-1){
    if(lazy[node] == 1){
        tree[node] = (end-start+1)-tree[node];
        Data[node].reverse();
        if(start != end){
            lazy[2*node+1]^=1;
            lazy[2*node+2]^=1;
        }
        lazy[node] = 0;
    }
    if(start > r || end < l)return n+1;
    if(l <= start && end <= r)return Data[node].left1;
    int p1 = query_left1(l,r,2*node+1,start,(start+end)>>1);
    int p2 = query_left1(l,r,2*node+2,((start+end)>>1)+1,end);
    return min(p1,p2);
}
int query_right1(int l, int r, int node = 0, int start = 0, int end = n-1){
    if(lazy[node] == 1){
        tree[node] = (end-start+1)-tree[node];
        Data[node].reverse();
        if(start != end){
            lazy[2*node+1]^=1;
            lazy[2*node+2]^=1;
        }
        lazy[node] = 0;
     }
    if(start > r || end < l)return -1;
    if(l <= start && end <= r)return Data[node].right1;
    int p1 = query_right1(l,r,2*node+1,start,(start+end)>>1);
    int p2 = query_right1(l,r,2*node+2,((start+end)>>1)+1,end);
    return max(p1,p2);
}
int query_left0(int l, int r, int node = 0, int start = 0, int end = n-1){
    if(lazy[node] == 1){
        tree[node] = (end-start+1)-tree[node];
        Data[node].reverse();
        if(start != end){
            lazy[2*node+1]^=1;
            lazy[2*node+2]^=1;
        }
        lazy[node] = 0;
    }
    if(start > r || end < l)return n+1;
    if(l <= start && end <= r)return Data[node].left0;
    int p1 = query_left0(l,r,2*node+1,start,(start+end)>>1);
    int p2 = query_left0(l,r,2*node+2,((start+end)>>1)+1,end);
    return min(p1,p2);
}
int query_right0(int l, int r, int node = 0, int start = 0, int end = n-1){
    if(lazy[node] == 1){
        tree[node] = (end-start+1)-tree[node];
        Data[node].reverse();
        if(start != end){
            lazy[2*node+1]^=1;
            lazy[2*node+2]^=1;
        }
        lazy[node] = 0;
     }
    if(start > r || end < l)return -1;
    if(l <= start && end <= r)return Data[node].right0;
    int p1 = query_right0(l,r,2*node+1,start,(start+end)>>1);
    int p2 = query_right0(l,r,2*node+2,((start+end)>>1)+1,end);
    return max(p1,p2);
}
void solve(){
    int m;
    cin >> n >> m;
    tree = V<int> (4*n,0);
    lazy = V<int> (4*n,0);
    arr = V<ll> (n);
    b = V<int> (n);
    Data = V<node> (4*n);
    loop(i,0,n){
        cin >> arr[i];
        b[i] = __builtin_popcount(arr[i])%2;
    }
    loop(i,1,n){
        b[i]^=b[i-1];
    }
    build();
    ll ans = -1;
    ll r1,l1,r0,l0;
    while(m--){
        int i; ll k;
        cin >> i >> k;
        if(__builtin_popcount(arr[i]) != __builtin_popcount(k)){
            arr[i] = k;
            update(i,n-1);
        }
        ans = 0;
        r1 = Data[0].right1;
        l1 = Data[0].left1;
        r0 = Data[0].right0;
        ans = max(ans,r1-l1);
        ans = max(ans,r0+1);
        cout << ans << " ";
    }
}

int main(){
    int t;
    cin >> t;
    loop(i,1,t+1){
        printf("Case #%d: ",i);
        solve();
        cout << endl;
    }
    return 0;
}