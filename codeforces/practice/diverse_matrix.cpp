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
const ll N = 4e6;
const ll inf = 1e9;
const double pi = acos(-1);
int p[N];
int main(){
    FAST
    /* V<int> primes(1,1);
    loop(i,2,N){
        if(p[i] == 0){
            primes.pb(i);
            for(int j = 2; i*j < N; ++j)p[i*j]++;
        }
    }
    reverse(all(primes));
     */
    int n,m;
    cin >> n >> m;
    V<V<ll>> arr(n,V<ll>(m,1));
    int cur = 1;
    set<int> s;
    if(n == 1 || m == 1){
        loop(i,0,n){
            loop(j,0,m){
                arr[i][j] = 1 + cur++;
            }
        }
    }else{
        loop(i,0,n){
            int p = cur++;
            // primes.pop_back();
            loop(j,0,m)arr[i][j]*=(1LL*p);
        }
        loopr(j,m-1,0){
            int p = cur++;
            // primes.pop_back();
            loopr(i,n-1,0){
                arr[i][j]*=(1LL*p);
            }
        }
    }
    loop(i,0,n){
        ll g = 0;
        loop(j,0,m)g=__gcd(arr[i][j],g);
        s.insert(g);
    }
    loop(j,0,m){
        ll g = 0;
        loop(i,0,n)g=__gcd(arr[i][j],g);
        s.insert(g);
    }
    if(s.size() != m+n){
        cout << 0;
    }else{
        loop(i,0,n){
            loop(j,0,m)cout << arr[i][j] << " ";
            cout << "\n";
        }
    }
   return 0;
}