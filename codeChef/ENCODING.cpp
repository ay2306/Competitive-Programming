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
V<int> num;
ll dp[maxn+10][2][10];
ll sum[maxn+10][2][10];
ll ans = 0;
ll power[maxn+10];
ll calc(int pos, int state, int prev, ll &_child_process){
    if(pos == num.size()){
        return 1;
    }
    ll &res = dp[pos][state][prev];
    ll &SUM = sum[pos][state][prev];
    if(res != -1){ans+=SUM;ans%=MOD;return res%MOD;}
    int last = 9;
    if(state){
        last = num[pos];
    }
    res = 0;
    SUM = 0;
    ll child_sum = 0;
    for(ll i = 0; i <= last; ++i){
        int s = (i == last && state);
        ll k = calc(pos+1,s,i,child_sum)%MOD;
        if(i != prev){
            ans = (ans + ((power[num.size() - pos - 1] * i)%MOD * k)%MOD)%MOD;
            child_sum += ((power[num.size() - pos - 1] * i)%MOD * k)%MOD;
            child_sum %= MOD;
        }
        res = (res + k)%MOD;
    }
    _child_process += child_sum;
    SUM = child_sum;
    _child_process%=MOD;
    SUM%=MOD;
    return res;
}

void solve(){
    int as,bs;
    string a,b;
    cin >> as >> a >> bs >> b;
    num.clear();
    for(auto i: a){
        num.pb(int(i-'0'));
    }
    ll oppp = 0;
    memset(dp,-1,sizeof(dp));
    memset(sum,-1,sizeof(sum));
    int k = num.size()-1;
    if(num[k] == 0){
        do{
            num[k] = 9;
            k--;
        }while(k >= 0 && num[k] == 0);
        num[k]--;
    }else{
        num[k]--;
    }
    ans = 0;
    ll s1 = calc(0,1,0,oppp);
    s1 = ans;
    num.clear();
    oppp = 0;
    memset(dp,-1,sizeof(dp));
    memset(sum,-1,sizeof(sum));
    for(auto i: b){
        num.pb(int(i-'0'));
    }
    ans = 0;
    ll s2 = calc(0,1,0,oppp);
    s2 = ans;
    cout << ((s2%MOD - s1%MOD)+MOD)%MOD << "\n";
}

int main(){
    freopen("output.txt","w",stdout);
    freopen("input.txt","r",stdin);
    ll k = 1;
    loop(i,0,maxn+10){
        power[i] = k;
        k = (k*10)%MOD;
    }
   int t = 1;
//    cin >> t;
   while(t--){
       solve();
   }
   return 0;
}