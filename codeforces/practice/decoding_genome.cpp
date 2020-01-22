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
ll n,m,k;
const int N = 52;
ll g[N][N];
int val(char c){
    if(c >= 'a' && c <= 'z')return c-'a';
    return c-'A'+26;
}

void multiply(ll a[N][N],ll b[N][N]){
    ll c[N][N];
    loop(i,0,m){
        loop(j,0,m){
            c[i][j] = 0;
            ll &p = c[i][j];
            loop(k,0,m){
                p = (p + (a[i][k]*b[k][j])%MOD);
                if(p >= MOD)p-=MOD;
            }
        }
    }
    loop(i,0,m){
        loop(j,0,m){
           a[i][j] =  c[i][j];
        }
    }
}

ll power(ll a[N][N], ll p){
    if(p == 1){
        ll s = 0;
        loop(i,0,m){
            loop(j,0,m){
               s+=a[i][j];
               if(s >= MOD)s-=MOD;
            }
        }
        return s;
    }
    power(a,p/2);
    multiply(a,a);
    if(p&1)multiply(a,g);
    ll s = 0;
    loop(i,0,m){
        loop(j,0,m){
            s+=a[i][j];
            if(s >= MOD)s-=MOD;
        }
    }
    return s;
}

int main(){
    cin >> n >> m >> k;
    loop(i,0,N){
        loop(j,0,N)g[i][j]=1;
    }
    ll a[N][N];
    while(k--){
        char a,b;
        cin >> a >> b;
        g[val(a)][val(b)] = 0;
    }
    loop(i,0,N){
        loop(j,0,N)a[i][j]=g[i][j];
    }
    if(n == 1){
        cout << m << "\n";
        return 0;
    }
    cout << power(a,n-1);
   return 0;
}