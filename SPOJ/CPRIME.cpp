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
const ll N = 1e8+2;
const ll inf = 1e9;
const double pi = acos(-1);
vector<int> prime;
bitset<N> isPrime;

int main(){
    isPrime[0] = isPrime[1] = 1;
    for(int i = 3; i < N; i+=2){
        if(isPrime[i] == 0){
            for(int j = 3; i*j < N; j+=2){
                isPrime[i*j] = 1;
            }
        }
    }
    prime.pb(2);
    for(int i = 3; i < N; i+=2){
        if(isPrime[i] == 0)prime.pb(i);
    }
    // cout << "DONE\n";
   int t = 0;
    // scanf("%d",&t);
   while(1){
       double x;
       scanf("%lf",&x);
       if(x < 0.5)break;
       double val = x/log(x);
       double real = double(upper_bound(all(prime),x) - prime.begin());
       printf("%.1f\n",(fabs(real-val)/real)*100.0);
   }
   return 0;
}