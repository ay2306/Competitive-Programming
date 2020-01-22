#include <bits/stdc++.h>
//For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MOD 998244353
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
const int N = 3e5+100;
ll f[N];
void pre(){\
    f[0] = 1;
    loop(i,1,N){
        f[i] = f[i-1]*i;
        f[i]%=MOD;
    }
}
int main(){
    pre();
    int n;
    cin >> n;
    map<int,int> m1;
    map<int,int> m2;
    map<PII,int> m12;
    loop(i,0,n){
        int a,b;
        cin >> a >> b;
        m1[a]++;
        m2[b]++;
        m12[{a,b}]++;
    }
    ll ans = f[n];
    ll cnt1 = 1;
    ll cnt2 = 1;
    ll cnt12 = 1;
    for(auto i: m1){
        cnt1*=f[i.S];
        cnt1%=MOD;
    }
    for(auto i: m2){
        cnt2*=f[i.S];
        cnt2%=MOD;
    }
    cnt12 = f[m12.begin()->second];
    auto i = m12.begin();
    i++;
    for(; i != m12.end(); ++i){
        if(prev(i)->first.second> i->first.second){
            cnt12 = 0;
            break;
        }else{
            cnt12*=f[i->second];
            cnt12%=MOD;
        }
    }
    ans+=(cnt12);
    ans-=(cnt1+cnt2);
    while(ans<0)ans+=MOD;
    while(ans >= MOD)ans-=MOD;
    cout << ans;
   return 0;
}