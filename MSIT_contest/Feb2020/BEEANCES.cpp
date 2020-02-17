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

ll m[2][2] = {{1,1},{1,0}};

void multiply(ll a[2][2], ll b[2][2]){
    ll c[2][2];
    loop(i,0,2){
        loop(j,0,2){
            c[i][j] = 0;
            loop(k,0,2){
                c[i][j]+=(a[i][k]*b[k][j]);
                if(c[i][j] >= MOD)c[i][j]%=MOD;
            }
        }
    }
    loop(i,0,2)loop(j,0,2)a[i][j]=c[i][j];
}

ll power(ll a[2][2], ll n){
    if(n == 0)return 1;
    if(n == 1)return (a[0][1] + a[0][0])%MOD;
    power(a,n>>1);
    multiply(a,a);
    if(n&1)multiply(a,m);
    return (a[0][0] + a[0][1])%MOD;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        char c;ll n;
        cin >> c >> n;
        ll a[2][2] = {{1,1},{1,0}};
        if(c == 'm')cout << power(a,n-1) << "\n";
        else cout << power(a,n) << "\n";
    }
   return 0;
}