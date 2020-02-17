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


int main(){
    FAST
    ll n;
    cin >> n;
    ll ans = (n*(n-1)*(n-2))/6;
    map<P<PLL,PLL>,set<PLL>> m;
    V<PLL> p(n);
    for(auto &i: p)cin >> i.F >> i.S;
    loop(i,0,n){
        loop(j,i+1,n){
            ll denom,num;
            ll x1 = p[i].F;
            ll x2 = p[j].F;
            ll y1 = p[i].S;
            ll y2 = p[j].S;
            num = y2-y1;
            denom = x2-x1;
            ll g = __gcd(num,denom);
            num/=g;
            denom/=g;
            PLL p1,p2;
            p1 = mp(num,denom);
            num = y1*x2 - y2*x1;
            denom = x2-x1;
            if(x1 == x2){
                p2 = mp(x1,0);
            }else{
                g = __gcd(num,denom);
                num/=g;
                denom/=g;
                p2 = mp(num,denom);
            }
            m[mp(p1,p2)].insert(p[i]);
            m[mp(p1,p2)].insert(p[j]);
        }
    }
    for(auto &i: m){
        ll k = i.S.size();
        k = ((k)*(k-2)*(k-1))/6;
        ans-=k;
    }
    cout << ans;
   return 0;
}