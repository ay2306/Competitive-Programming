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

int dp[maxn+100];
int arr[maxn+100];
int primes[maxn+100];
int cnt[maxn+100];

void sieve(){
    for(int i = 2; i < maxn+100; ++i){
        if(primes[i] == 0){
            for(ll j = i; j < maxn+100; j+=i)primes[j]=i;
        }
    }
}
int main(){
    sieve();
    int n;
    cin >> n;
    loop(i,1,n+1)cin >> arr[i];
    int ans = 0;
    loop(i,1,n+1){
        int a = arr[i];
        while(a > 1){
            int div = primes[a];
            if(div == 0)div=a;
            cnt[div]++;
            dp[i] = max(dp[i],cnt[div]);
            while(a > 1 && a%div == 0)a/=div;
        }
        a = arr[i];
        while(a > 1){
            int div = primes[a];
            if(div == 0)div=a;
            cnt[div] = dp[i];
            while(a > 1 && a%div == 0)a/=div;
        }
        ans = max(ans,dp[i]);
    }
    cout << max(ans,1);
   return 0;
}