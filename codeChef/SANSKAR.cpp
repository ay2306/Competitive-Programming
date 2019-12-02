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
const int N = 22;
const int K = 10;
bool dp[K][(1 << N)];
ll arr[N];
void solve(){
    ll n,k;
    cin >> n >> k;
    loop(i,0,n){
        cin >> arr[i];
    }
    ll x = accumulate(arr,arr+n,0*1LL);
    if(x % k != 0 || n < k){
        cout << "no\n";
        return;
    }
    if( x == 0 ){
        cout << "yes\n";
        return ;
    }
    x/=k;
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    loop(i,0,k){
        loop(bit,0,(1 << n)){
            if(!dp[i][bit])continue;
            ll s = 0;
            for(int j = 0; j < n; ++j){
                if(bit & (1 << j))s+=arr[j];
            }
            s-=i*x;
            for(int j = 0; j < n; ++j){
                if(bit & (1 << j))continue;
                if(s + arr[j] == x){
                    dp[i+1][bit|(1 << j)] = 1;
                }
                if(s + arr[j] < x){
                    dp[i][bit | (1 << j)] = 1;
                }
            }
            printf("dp[%d][%d] = %d\n",i,bit,int(dp[i][bit]));
        }
    }
    if(dp[k][(1 << n)-1]){
        cout << "yes\n";
    }else{
        cout << "no\n";
    }
}

int main(){
   int t = 0;
   cin >> t;
   while(t--){
       solve();
   }
   return 0;
}