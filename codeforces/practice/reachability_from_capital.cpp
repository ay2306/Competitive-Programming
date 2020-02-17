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
const ll N = 5e3+100;
const ll inf = 1e9;
const double pi = acos(-1);

int lt[N],dt[N],in[N],ct,scc_number[N],sc,d[N];
stack<int> s;
V<int> g[N];

void popper(int st){
    ++sc;
    while(s.size()){
        int n = s.top();
        s.pop();
        in[n] = 0;
        scc_number[n]=sc;
        if(n == st)break;
    }
}

void dfs(int u){
    lt[u] = dt[u] = ++ct;
    in[u]=1;
    s.push(u);
    for(auto &v: g[u]){
        if(in[v])lt[u]=min(lt[u],lt[v]);
        else if(dt[v] == 0){
            dfs(v);
            lt[u]=min(lt[u],lt[v]);
        }
    }
    if(lt[u]==dt[u]){
        popper(u);
    }
}


int main(){
    int n,m,k;
    cin >> n >> m >> k;
    loop(i,0,m){
        int a,b;
        cin >> a >> b;
        g[a].pb(b);
    }
    loop(i,1,n+1)if(dt[i] == 0)dfs(i);
    loop(i,1,n+1){
        for(auto &j: g[i])if(scc_number[i] != scc_number[j])d[scc_number[j]]++;
    }
    int ans = 0;
    ans-=(d[scc_number[k]] == 0);
    loop(i,1,sc +1){
        ans+=(d[i]==0);
    }
    cout << ans;
   return 0;
}