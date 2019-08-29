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
unordered_map<ll,bool> m;

bool isPrime(ll a){
    if(a < 2)return false;
    if(a == 2) return true;
    if(a == 3)return true;
    if((a & 1) == 0)return false;
    for(ll i = 3; i*i <= a; i+=2){
        if(a%i == 0)return false;
    }
    return true;
}

void solve(){
    ll a,b;
    cin >> a >> b;
    while(a <= b){
        if(m.find(a) == m.end()){
            m[a] = isPrime(a);
        }
        if(m[a])printf("%lld\n",a);
        a++;
    }
}

int main(){
   int t = 0;
   scanf("%d",&t);
   while(t--){
       solve();
        if(t)printf("\n");
   }
   return 0;
}