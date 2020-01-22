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
const ll N = 1e6 + 10;
const ll inf = 1e9;
const double pi = acos(-1);
ll fact[N];
ll infact[N];
ll power(ll a, ll n){
    if(n == 0)return 1;
    if(n == 1)return a%MOD;
    ll p = power(a,n/2);
    p*=p;
    p%=MOD;
    if(n&1){
        p*=a;
        p%=MOD;
    }
    return p;
}
int main(){
    int a,b,n;
    cin >> a >> b >> n;
    fact[0] = 1;
    fact[1] = 1;
    infact[0] = 1;
    infact[1] = 1;
    loop(i,2,N){
        fact[i]=fact[i-1]*i;
        fact[i]%=MOD;
        infact[i]=infact[i-1];
        infact[i]*=power(i,MOD-2);
        infact[i]%=MOD;
    }
    ll ans = 0;
    for(ll A = 0; A <= n; ++A){
        ll B = n-A;
        ll s = A*a+B*b;
        bool ex = true;
        while(s){
            if(s%10 != a && s%10 != b){
                ex = false;
                break;
            }
            s/=10;
        }
        if(ex){
            ll c = fact[n]*infact[A];
            // cout << A << " " << c << "\n";
            // cout << fact[n] << " " << infact[A] << "\n";
            c%=MOD;
            c*=infact[B];
            c%=MOD;
            // cout << A << " " << c << "\n";
            ans+=c;
            ans%=MOD;
        }
    }
    cout << ans;
   return 0;
}