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
int n,m;
V<P<int,PII>> edge;
vector<int> Rank;
vector<int> parent;
vector<bool> allowed;
V<int> inc;
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

int krushkal(bool c = false){
    loop(i,0,n){
        parent[i] = i;
        Rank[i] = 0;
    }
    int ans = 0;
    for(int j = 0; j < edge.size(); ++j){
        if(!allowed[j])continue;
        auto &i = edge[j];
        if(findParent(i.second.first) == findParent(i.second.second))continue;
        ans+=i.first;
        UNION(i.second.first,i.second.second);
        if(!c){
            inc.pb(j);
        }
    }
    unordered_map<int,int> m;
    loop(i,0,n)m[findParent(i)]++;
    if(m.size() != 1)return inf;
    return ans;
}
void solve(){
    cin >> n >> m;
    edge = V<P<int,PII>> ();
    allowed = V<bool> (m,true);
    parent = V<int> (n,0);
    Rank = V<int> (n,0);
    inc = V<int>();
    loop(i,0,m){
        int a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        edge.pb(mp(c,mp(a,b)));
    }
    sort(all(edge));
    // cout << edge.size() << "\n";
    int best = krushkal();
    int secBest = inf;
    for(auto &i: inc){
        allowed[i] = false;
        secBest = min(secBest,krushkal(true));
        allowed[i] = true;
    }
    cout << best << " " << secBest << "\n";
}

int main(){
    // FILE_READ_IN
    // FILE_READ_OUT
    FAST
    int t;
    cin >> t;
    while(t--){
        solve();
    }
   return 0;
}