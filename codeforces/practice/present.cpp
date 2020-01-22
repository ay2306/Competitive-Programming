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
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);
V<PII> tree;
V<int> lazy;
V<int> arr;
int n;
void build(int node = 0, int start = 0, int end = n-1){
    if(start == end){
        tree[node] = {arr[start],start};
        return ;
    }
    int mid = start+end>>1;
    build(2*node+1,start,mid);
    build(2*node+2,mid+1,end);
    if(tree[2*node+1].F < tree[2*node+2].F)tree[node]=tree[2*node+1];
    else if(tree[2*node+1].F > tree[2*node+2].F)tree[node]=tree[2*node+2];
    else tree[node] = {tree[2*node+1].F,min(tree[2*node+1].S,tree[2*node+2].S)};
}

void update(int l, int r, int val, int node = 0, int start = 0, int end = n-1){
    if(lazy[node]){
        tree[node].F+=lazy[node];
        if(start != end){
            lazy[2*node+1]+=lazy[node];
            lazy[2*node+2]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(l > end || r < start)return;
    if(l <= start && end <= r){
        tree[node].F+=val;
        if(start != end){
            lazy[2*node+1]+=val;
            lazy[2*node+2]+=val;
        }
        return ;
    }
    int mid = start+end>>1;
    update(l,r,val,2*node+1,start,mid);
    update(l,r,val,2*node+2,mid+1,end);
    if(tree[2*node+1].F < tree[2*node+2].F)tree[node]=tree[2*node+1];
    else if(tree[2*node+1].F > tree[2*node+2].F)tree[node]=tree[2*node+2];
    else tree[node] = {tree[2*node+1].F,min(tree[2*node+1].S,tree[2*node+2].S)};
}

PII query(int l, int r, int node = 0, int start=0, int end = n-1){
    if(lazy[node]){
        tree[node].F+=lazy[node];
        if(start != end){
            lazy[2*node+1]+=lazy[node];
            lazy[2*node+2]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(l > end || r < start)return {2*inf,2*inf};
    if(l <= start && end <= r){
        return tree[node];
    }
    int mid = start+end>>1;
    auto p1 = query(l,r,2*node+1,start,mid);
    auto p2 = query(l,r,2*node+2,mid+1,end);
    if(p1.F < p2.F)return p1;
    else if(p1.F > p2.F)return p2;
    else return {p1.F,min(p1.S,p2.S)};
}

int main(){
    int m,w;
    cin >> n >> m >> w;
    arr = V<int> (n);
    tree = V<PII> (n<<2);
    lazy = V<int> (n<<2);
    loop(i,0,n)cin >> arr[i];
    build();
    while(m--){
        auto p = query(0,n-1);
        int b = min(p.S+w-1,n-1);
        int a = max(0,b-w+1);
        update(a,b,1);
        // printf("p = (%d, %d), a = %d, b = %d\n",p.F,p.S,a,b);
        // loop(i,a,b+1)++arr[i];
        // loop(i,0,n)printf("%d(%d) ",query(i,i).F,i);
        // printf("\n");
    }
    // int ans = query(0,0).F;
    // loop(i,1,n)ans=min(ans,query(i,i).F);
    cout << tree[0].F;

   return 0;
}