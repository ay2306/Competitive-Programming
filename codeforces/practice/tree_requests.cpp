// * This is code from Ashishgup
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
const ll N = 5e5+100;
const ll inf = 1e9;
const double pi = acos(-1);
int n,q,tim=0;
string s;
V<int> g[N];
unordered_map<int,int> m[N];
V<PII> queries[N];
int ans[N];
int sub[N];
int h[N];
void dfs(int s = 1, int p = -1){
    sub[s] = 1;
    if(p == -1)h[s] = 1;
    else h[s] = h[p]+1;
    for(auto i: g[s]){
        if(i != p){
            dfs(i,s);
            sub[s]+=sub[i];
        }
    }
}

void dsu(int v = 1, int p = -1, bool ok = true){
    int mx = -1, bigchild = -1;
    for(auto i: g[v]){
        if(i != p){
            if(sub[i] > mx)mx=sub[i],bigchild=i;
        }
    }
    if(bigchild != -1){
        dsu(bigchild,v,true);
        swap(m[bigchild],m[v]);
    }
    for(auto i: g[v]){
        if(i == p || i == bigchild)continue;
        dsu(i,v,false);
        for(auto it: m[i]){
            m[v][it.first]^=it.second;
        }
    }
    m[v][h[v]]^=(1<<(s[v-1]-'a'));
    for(auto i: queries[v]){
        int j = m[v][i.F];
        if(__builtin_popcount(j) > 1 )ans[i.S] = 0;
        else ans[i.S] = 1;
    }
}

int main(){
    FAST
    cin >> n >> q;
    loop(i,2,n+1){
        int a;
        cin >> a;
        g[a].pb(i);
        g[i].pb(a);
    }
    cin >> s;
    loop(i,0,q){
        int a,b;
        cin >> a >> b;
        queries[a].pb(mp(b,i));
    }
    dfs();
    dsu();
    loop(i,0,q){
        if(ans[i])cout << "Yes\n";
        else cout << "No\n";
    }
   return 0;
}