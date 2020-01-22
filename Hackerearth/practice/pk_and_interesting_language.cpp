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
const ll N = 26;
const ll inf = 1e9;
const double pi = acos(-1);

ll m[N][N];

void multiply(ll a[N][N], ll b[N][N]){
    ll c[N][N];
    loop(i,0,N){
        loop(j,0,N){
            c[i][j] = 0;
            loop(k,0,N){
                c[i][j]=(c[i][j]+(a[i][k]*b[k][j])%MOD);
                if(c[i][j] >= MOD)c[i][j] -= MOD;
            }
        }
    }
    loop(i,0,N){
        loop(j,0,N){
            a[i][j] = c[i][j];
        }
    }
}

ll power(ll a[N][N], ll n){
    if(n == 0){
        
    }
    if(n == 1){
        ll s = 0;
        loop(i,0,N){
            loop(j,0,N)s=(s+a[i][j])%MOD;
        }
        return s;
    }
    power(a,n/2);
    multiply(a,a);
    if(n&1){
        multiply(a,m);
    }
    ll s = 0;
    loop(i,0,N){
        loop(j,0,N)s=(s+a[i][j])%MOD;
    }
    return s;
}

int main(){
    ll a[N][N];
    loop(i,0,N){
        loop(j,0,N)cin >> m[i][j];
    }
    int t;
    cin >> t;
    while(t--){
        char c;
        ll n;
        cin >> c >> n;
        loop(i,0,N){
            loop(j,0,N)a[i][j] = m[i][j];
        }
        power(a,n-2);
        ll ans = 0;
        loop(i,0,N){
            ans = (ans + a[i][c-'a'])%MOD;
        }
        cout << ans << "\n";
    }
   return 0;
}