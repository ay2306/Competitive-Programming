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
const ll N = 2e5+10;
const ll inf = 1e9;
const double pi = acos(-1);
// *red node to parent
// *green parent to node
int r,g;
V<int> adj[N];
set<int> d[N];
PII cnt[N];

void dfs(int s = 1, int p = -1, int green = 0, int red = 0){
    cnt[s] = {red,green};
    // printf("node = %d, r = %d, g = %d\n",s,red,green);
    for(auto i: adj[s]){
        if(i == p)continue;
        if(d[s].find(i) != d[s].end())dfs(i,s,green+1,red),g++;
        else dfs(i,s,green,red+1),r++;
    }
}

int inversion(int i){
    // printf("node = %d, red = %d, green = %d\n",i,cnt[i].F,cnt[i].S);
    int path_red = cnt[i].F;
    int path_green = cnt[i].S;
    int ans = 0;
    // * invert green on path;
    ans+=path_green;
    int rem_red = r-path_red;
    // * invert rest red;
    ans+=rem_red;
    return ans;
}

int main(){
    FAST
    int n;
    cin >> n;
    loop(i,1,n){
        int a,b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
        d[a].insert(b);
    }
    dfs();
    // cout << r << " " << g << "\n";
    int mn = 2*n;
    loop(i,1,n+1){
        mn = min(mn,inversion(i));
    }
    cout << mn << "\n";
    loop(i,1,n+1){
        if(mn == inversion(i))cout << i << " ";
    }
   return 0;
}