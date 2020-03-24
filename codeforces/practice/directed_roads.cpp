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
const ll N = 2e5+100;
const ll inf = 1e9;
const double pi = acos(-1);
V<int> g[N];
int comp[N],cur,lt[N],dt[N],c,in[N];
stack<int> st;

void popper(int stop){
    cur++;
    while(1){
        int n = st.top();
        st.pop();
        comp[n] = cur;
        in[n] = 0;
        if(n == stop)break;
    }
}

void dfs(int s = 0){
    lt[s] = dt[s] = ++c;
    in[s] = 1;
    st.push(s);
    for(int &i: g[s]){
        if(in[i])lt[s]=min(lt[s],lt[i]);
        else if(dt[i] == 0){
            dfs(i);
            lt[s] = min(lt[s],lt[i]);
        }
    }
    if(lt[s] == dt[s])popper(s);
}

ll power(ll a, ll n){
    if(n == 0)return 1;
    if(n == 1)return a%MOD;
    ll p = power(a,n>>1);
    p*=p;
    if(p>=MOD)p%=MOD;
    if(n&1){
        p*=a;
        if(p>=MOD)p%=MOD;
    }
    return p;
}

int main(){
    int n,a;
    scanf("%d",&n);
    loop(i,1,n+1){
        scanf("%d",&a);
        g[i].emplace_back(a);
    }
    loop(i,1,n+1)if(dt[i]==0)dfs(i);
    ll f=0;
    unordered_map<int,ll> cnt;
    loop(i,1,n+1){
        for(auto &j: g[i]){
            if(comp[i] == comp[j])cnt[comp[i]]++;
            else f++;
        }
    }
    ll ans = power(2,f);
    for(auto &i: cnt){
        ans*=((power(2,i.second)-2+MOD)%MOD);
        if(ans >= MOD)ans%=MOD;
    }
    printf("%lld",ans);
   return 0;
}