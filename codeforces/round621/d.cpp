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
// using namespace __gnu_pbds;
// template <typename T>
// using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll N = 2e5+10;
const ll inf = 1e9;
const double pi = acos(-1);
int n,m,k;
V<int> g[N];
V<int> sp;
void bfs(int s, V<int> &level){
   V<int> vis(n,0);
   level[s] = 0;
   vis[s] = 1;
   queue<int> q;
   q.push(s);
   while(q.size()){
      int u = q.front();
      q.pop();
      for(auto &v: g[u]){
         if(!vis[v]){
            q.push(v);
            level[v] = level[u]+1;
            vis[v]=1;
         }
      }
   }
}
V<int> d1,dn;

ll tree[N<<2];

void build(int node = 0, int start = 0, int end = k-1){
    if(start == end){
        tree[node] = dn[sp[start]];
        return;
    }
    int mid = start+end>>1;
    build(2*node+1,start,mid);
    build(2*node+2,mid+1,end);
    tree[node] = max(tree[2*node+1],tree[2*node+2]);
}

ll query(int l, int r, int node = 0, int start = 0, int end = k-1){
    if(l > end || r < start)return LLONG_MIN;
    if(l <= start && end <= r){
        return tree[node];
    }
    int mid = start+end>>1;
    ll p1 = query(l,r,2*node+1,start,mid);
    ll p2 = query(l,r,2*node+2,mid+1,end);
    return max(p1,p2);
}


void solve(){
   FAST
   cin >> n >> m >> k;
   loop(i,0,k){
      int a;
      cin >> a;
      a--;
      sp.pb(a);
   }
   while(m--){
      int a,b;
      cin >> a >> b;
      a--;
      b--;
      g[a].pb(b);
      g[b].pb(a);
   }
   d1.resize(n);
   dn.resize(n);
   bfs(0,d1);
   bfs(n-1,dn);
   int ans = d1[n-1];
   sort(all(sp),[](int &a, int &b)->bool{
      return d1[a] < d1[b];
   });
   build();
   // printf("d1 = ");
   // loop(i,0,n)printf("(node = %d, dist = %d) ",i+1,d1[i]);
   // printf("\n");
   // printf("dn = ");
   // loop(i,0,n)printf("(node = %d, dist = %d) ",i+1,dn[i]);
   // printf("\n");
   // printf("sp = ");
   // loop(i,0,k)printf("(node = %d, dist = %d) ",sp[i]+1,d1[sp[i]]);
   // printf("\n");
   int op = ans;
   ans = 0;
   for(int i = 0; i+1 < k; ++i){
      ans = max(ans,int(d1[sp[i]]+query(i+1,k-1)+1));
   }
   ans = min(ans,op);
   cout << ans ;
}

int main(){
   int t = 1;
//    cin >> t;
   while(t--){
       solve();
   }
   return 0;
}