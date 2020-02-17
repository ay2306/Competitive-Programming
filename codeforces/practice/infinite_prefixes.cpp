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

string a;
ll n,x;

int f(char a){
    if(a == '0')return 1;
    return -1;
}
void solve(){
    cin >> n >> x;
    cin >> a;
    ll s = 0;
    loop(i,0,n){
        s+=f(a[i]);
    }
    ll c = 0;
    ll ans = 0;
    loop(i,0,n){
        // * ks + c = x
        // * ks = x-c
        if(s == 0 && c == x){
            cout << -1 << "\n";
            return ;
        }
        if(s != 0 && (x-c)%s == 0 && (x-c)/s >= 0){
            // printf("c = %lld, x = %lld, x-c = %lld, (x-c)/s = %lld, i = %d\n",c,x,x-c,(x-c)/s,i);
            ans++;
        }
        c+=f(a[i]);
    }
    cout << ans << "\n";
}

int main(){
    FAST
    int t;
    cin >> t;
    while(t--)solve();
   return 0;
}