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
ll power(ll a, ll n){
    if(n == 0)return 1;
    if(n == 1)return a%MOD;
    ll p = power(a,n/2);
    p*=p;
    p%=MOD;
    if(n&1){p*=a;p%=MOD;}
    return p;
}
int main(){
    ll p = 998244353;
    ll inv = power(p,MOD-2);
    string a,valid;
    int k;
    int ans = 0;
    cin >> a >> valid >> k;
    for(int length = 1; length <= a.size(); ++length){
        ll hash = 0;
        string o = "";
        int cnt = 0;
        ll high = power(p,length-1);
        loop(i,0,length){
            hash+=(a[i]*power(p,i));
            hash%=MOD;
            o+=a[i];
            cnt+=(valid[a[i]-'a'] == '0');
        }
        // cout << o << " " << hash << "\n";
        unordered_map<ll,set<string>> m;
        if(cnt <= k)m[hash].insert(o);
        loop(i,length,a.size()){
            o.erase(o.begin());
            o+=a[i];
            cnt-=(valid[a[i-length]-'a'] == '0');
            hash-=a[i-length];
            hash*=inv;
            hash%=MOD;
            // cout << hash << "\n";
            hash+=(a[i]*high);
            hash%=MOD;
            cnt+=(valid[a[i]-'a'] == '0');
            if(cnt <= k)m[hash].insert(o);
            // cout << o << " " << hash << "\n";
        }
        for(auto i: m){
            // for(auto j: i.S)cout << j << endl;
            ans+=i.S.size();
        }
    }
    cout << ans;
   return 0;
}