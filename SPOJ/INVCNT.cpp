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
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);

const int N = 2e5 + 15;
ll arr[N];

ll mergeSort(int l, int r){
    if(r <= l)return 0;
    ll mid = ((l+r)>>1);
    ll ans = mergeSort(l,mid);
    ans += mergeSort(mid+1,r);
    vector<int> a;
    vector<int> b;
    loop(i,l,mid+1){
       a.pb(arr[i]);
    }
    loop(i,mid+1,r+1){
       b.pb(arr[i]);
    }
    // printf("l = %d r = %d\n",l,r);
    // printf("A: ");
    // for(auto i: a)cout << i << " ";
    // printf("\nB: ");
    // for(auto i: b)cout << i << " ";
    // printf("\n");
    for(auto &i: b){
        ll f;
        auto k = upper_bound(all(a),i) - a.begin();
        f = (a.size() - k);
        // printf("element = %d, inversion = %d\n",i,f);
        ans+=f;
    }
    reverse(all(a));
    reverse(all(b));
    ll i = l;
    while(a.size() || b.size()){
        ll one = inf, two = inf;
        if(a.size())one=a.back();
        if(b.size())two=b.back();
        if(one <= two){
            a.pop_back();
            arr[i] = one;
        }else{
            b.pop_back();
            arr[i] = two;
        }
        ++i;
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    loop(i,0,n){
        cin >> arr[i];
    }
    cout << mergeSort(0,n-1) << "\n";
}

int main(){
    FAST
   int t;
   cin >> t;
   while(t--)solve();
   return 0;
}