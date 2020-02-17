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
const ll maxn = 3e5+10;
const ll inf = 1e9;
const double pi = acos(-1);
set<int> g[maxn];
set<int> s;
int n,m,k,cnt,a,b;

void dfs(int u,int p = -1){
   s.erase(u);
   V<int> nxt;
   for(auto &i: s)if(g[u].find(i) == g[u].end() && i != p)nxt.pb(i);
   for(auto &i: nxt)s.erase(i);
   for(auto &i: nxt)dfs(i,p);
}


int main(){
   FAST
   cin >> n >> m >> k;
   while(m--){
      cin >> a >> b;
      g[a].insert(b);
      g[b].insert(a);
   }
   set<int> one;
   loop(i,1,n+1)s.insert(i),one.insert(i);
   one.erase(1);
   for(auto &i: g[1])one.erase(i);
   int imp = 0;
   for(auto &i: one)if(s.find(i) != s.end())dfs(i,1),imp++;
   s.clear();
   loop(i,1,n+1)s.insert(i);
   loop(i,1,n+1)if(s.find(i) != s.end())dfs(i),cnt++;
   // printf("cnt = %d, n-1-g[1].size() = %d, g[1].size() = %d, imp = %d\n",cnt,n-1-g[1].size(),g[1].size(),imp);
   if(cnt == 1 && n-1-g[1].size() >= k && imp <= k)cout << "possible\n";
   else cout << "impossible\n";
   return 0;
}