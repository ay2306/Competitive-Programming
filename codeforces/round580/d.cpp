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
int n;
V<V<int>> adj;
vector<int> Rank;
vector<int> parent;
V<int>color;
V<int>par;
V<int> mark;
    int cyclenumber = 0;
int findParent(int x){
    while(x != parent[x]){
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
   return x;
}
void UNION(int a, int b){
    a = findParent(a);
    b = findParent(b);
    if(Rank[a] < Rank[b]){
        parent[a]=b;
    }else if(Rank[a] > Rank[b]){
        parent[b] = a;
    }else{
        parent[a] = b;
        Rank[b]++;
    }
}

vector<vector<int>> cycles;

void dfs_cycle(int u, int p)
{
    cout << u << "\n";
    if (color[u] == 2) {
        return;
    }
    if (color[u] == 1) {

        cyclenumber++;
        int cur = p;
        mark[cur] = cyclenumber;
        while (cur != u) {
            cur = par[cur];
            mark[cur] = cyclenumber;
        }
        // cout << "cyc" << cyclenumber << "\n";
        return;
    }
    par[u] = p;

    color[u] = 1;
    for (int v : adj[u]) {
        if (v == par[u]) {
            continue;
        }
        // cout << "from " << u << " " << v;
        dfs_cycle(v, u);
    }
    color[u] = 2;
}


void printCycles(int edges)
{

    for (int i = 1; i <= edges; i++) {
        if (mark[i] != 0)
            cycles[mark[i]].push_back(i);
    }
    // cout << "AA";
    for (int i = 1; i <= cyclenumber; i++) {
        cout << "Cycle Number " << i << ": ";
        for (int x : cycles[i])
            cout << x << " ";
        cout << endl;
    }
}


map<PII,int> ed;
int main(){
    const int N = 1e6;
    const int B = 62;
    // int n;
    cin >> n;
    adj = V<V<int>> (N);
    V<ll> arr(n+1);
    parent = V<int> (N,0);
    Rank = V<int> (N,0);
    color = V<int>(N,0);
    par = V<int>(N,0);
    mark = V<int>(N,0);
    loop(i,1,n+1){
        cin >> arr[i];
        parent[i] = i;
    }
    int edges = 0;
    for(int bit = 0; bit <= B; ++bit){
        V<int> a;
        loop(i,1,n+1){
            if((arr[i]&(1LL << bit)) > 0){
                a.pb(i);
            }
        }
        if(a.size() > 2){
            cout << "3";
            return 0;
        }
        if(a.size() <= 1)continue;
        else{
            if(ed.find(mp(a[0],a[1])) != ed.end() || ed.find(mp(a[1],a[0])) != ed.end())continue;
            ed[mp(a[0],a[1])]++;
            adj[a[0]].pb(a[1]);
            adj[a[1]].pb(a[0]);
            edges++;
        }
    }
    dfs_cycle(1, 0);
    // cout << "HELLO";
    printCycles(edges);
   return 0;
}