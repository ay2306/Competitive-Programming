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
using namespace std;
// For ordered_set
// using namespace __gnu_pbds;
// template <typename T>
// using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);
const int N = 21;
int a[1 << N];
ll c[2][N];
int n,m,q;
void build(int l = 1, int r = (1 << n), int dep = n){
    if(l == r)return;
    int mid = (l+r)>>1;
    build(l,mid,dep-1);
    build(mid+1,r,dep-1);
    //Understanding the logic here
    // there are two sorted arrays here: a[l ... mid], a[mid+1 ... r]
    // We need to calculate normal that is number of pairs (i,j) such that
    // a[i] > a[j] and l <= i <= mid <= j <= r
    // We need to calculate reverse that is number of pairs (i,j) such that
    // a[i] < a[j] and l <= i <= mid <= j <= r
    // To calculate normal this is what we do
    // Now for each i in a[l ... mid], we need to find number of elements greater than a[i] in second a[mid+1 ... r]
    // Explained with code
    for(int i = l; i <= mid; ++i){
        int pos = lower_bound(a+mid+1,a+r+1,a[i]) - a - 1;
        // Now lower_bound returns first element in given range that is not less than a[i], so we ask for one elements (last element smaller than a[i])
        // Now there is edged possibilities
        // pos == a+mid, this means a+mid+1 was greater than a[i], thus no element will be smaller than a[i].
        if(a[pos] < a[i])c[0][dep]+=pos-mid;
        pos = upper_bound(a+mid+1,a+r+1,a[i]) - a;
        // Now upper_bound returns first element in given range that is greater than a[i]
        if(a[pos] > a[i])c[1][dep]+=r-pos+1;
    }
    sort(a+l,a+r+1);
}
int main(){
    FAST
    cin >> n;
    loop(i,1,(1 << n)+1)cin >> a[i];
    cin >> m;
    build();
    while(m--){
        int q;
        cin >> q;
        ll ans = 0;
        for(int i = 0; i <= q; ++i)swap(c[0][i],c[1][i]);
        for(int i = 0; i <= n; ++i)ans+=c[0][i];
        cout << ans << "\n";
    }
   return 0;
}