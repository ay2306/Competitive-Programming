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
// using namespace __gnu_pbds;
// template <typename T>
// using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll N = 2e5+10;
const ll inf = 1e9;
const double pi = acos(-1);
int tree[4*N];
int arr[N];
int n;
void build(int node = 0, int start = 0, int end = n-1){
    if(start == end){
        tree[node] = 1;
        return;
    }
    build(2*node + 1, start, (start+end)>>1);
    build(2*node + 2, ((start+end)>>1)+1, end);
    tree[node] = tree[node*2+1] + tree[2*node+2];
}

void update(int ind, int val, int node = 0, int start = 0, int end = n-1){
    if(start == end){
        tree[node] = val;
        return;
    }
    int mid = (start+end)>>1;
    if(start <= ind && ind <= mid)update(ind,val,2*node+1,start,mid);
    else update(ind,val,2*node+2,mid+1,end);
    tree[node] = tree[node*2+1] + tree[2*node+2];
}

int query(int l, int r, int node = 0, int start = 0, int end = n-1){
    if(start > r || end < l)return 0;
    if(l <= start && end <= r)return tree[node];
    int mid = (start+end)>>1;
    int p1 = query(l,r,2*node+1,start,mid);
    int p2 = query(l,r,2*node+2,mid+1,end);
    // printf("(l = %d, r = %d ,start = %d ,mid = %d) returned p1 = %d\n",l,r,start,mid,p1);
    // printf("(l = %d, r = %d ,mid+1 = %d ,end = %d) returned p2 = %d\n",l,r,mid+1,end,p2);
    // printf("(l = %d, r = %d ,start+1 = %d ,end = %d) returning  p1+p2 = %d\n",l,r,start,end,p2+p1);
    return p1 + p2;
}

int main(){
    FAST
    cin >> n;
    V<PII> a(n);
    V<int> ans(n,0);
    unordered_map<int,int> index;
    loop(i,0,n){
        cin >> a[i].F >> a[i].S;
        arr[i] = a[i].S;
        index[a[i].F] = i;
    }
    sort(all(a));
    sort(arr,arr+n);
    build();
    loop(i,0,n){
        int end_index = lower_bound(arr,arr+n,a[i].S)-arr;
        // printf("end_index = %d for a[i].S = %d\n",end_index,a[i].S);
        if(end_index != 0){
            ans[index[a[i].F]] = query(0,end_index-1);
        }
        update(end_index,0);
    }
    loop(i,0,n)cout << ans[i] << "\n";
return 0;
}