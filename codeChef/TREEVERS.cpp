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
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);
int n;
V<V<int>> adj;
V<int> w;

struct A{
    int node;
    int zero;
    int one;
    ll inv;
    A():zero(0),one(0),inv(0){}
    A(int a, int b, int c, int d):zero(a),one(b),inv(c),node(d){}
    void print(){
        printf("{node = %d, zeros = %d, one = %d, inverse = %lld}\n",node,zero,one,inv);
    }
    // bool operator<(A &rhs){
    //     return (inv < rhs.inv || (inv == rhs.inv && zero > rhs.zero));
    // }
    // bool operator()(const A &rhs){
    //     return (inv < rhs.inv || (inv == rhs.inv && zero > rhs.zero));
    // }
};
bool compare(A &lhs, A &rhs){
    return (lhs.one < rhs.one || (lhs.one == rhs.one && lhs.zero > rhs.zero));
}
A dfs(int s = 0, int p = -1){
    // multiset<A,function<bool(A,A)>> m(compare);
    V<A> arr;
    for(auto &i: adj[s]){
        if(i == p)continue;
        arr.pb(dfs(i,s));
    }
    if(arr.size() == 0){
        return A(int(w[s] == 0),int(w[s]==1),0,s);
    }
    sort(arr.begin(),arr.end(),compare);
    V<int> zero(arr.size(),0);
    ll inv = 0;
    int o = 0;
    int i = 0;
    for(auto &k: arr){
        // arr[i] = k;
        // k.print();
        if(i > 0)zero[i] = zero[i-1];
        zero[i++]+=k.zero;
        inv+=k.inv;
        o+=k.one;
    }
    for(int j = 0; j+1 < arr.size(); ++j){
        if(w[arr[j].node] == 1){
            inv+=(zero.back() - zero[j]);
        }
    }
    if(w[s] == 1){
        inv+=zero.back();
    }
    return A(zero.back()+int(w[s] == 0),o+int(w[s] == 1),inv,s);
}

void solve(){
    cin >> n;
    adj = V<V<int>> (n);
    w = V<int> (n);
    loop(i,0,n){
        cin >> w[i];
    }
    loop(i,1,n){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    cout << dfs().inv << "\n";
}

int main(){
   FAST
   int t = 0;
   cin >> t;
   while(t--){
       solve();
   }
   return 0;
}