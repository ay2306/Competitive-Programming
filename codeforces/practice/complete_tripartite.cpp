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
    int n,m;
    cin >> n >> m;
    V<set<int>> g(n+1);
    loop(i,0,m){
        int a,b;
        cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
    }
    V<int> gr(n+1,-1);
    loop(i,0,3){
        int f;
        for(f=1;f<=n;++f)if(gr[f]==-1)break;
        if(f == n+1){
            cout << "-1\n";
            return 0;
        }
        gr[f] = i;
        loop(s,1,n+1)if(f!=s && gr[s] == -1 && g[f].find(s)==g[f].end())gr[s]=i;
    }
    V<V<int>> adj(3);
    loop(i,1,n+1){
        if(gr[i] == -1){
            cout << -1;
            return 0;
        }
        else adj[gr[i]].pb(i);
    }
    int ed=0;
    loop(i,0,3){
        loop(j,i+1,3){
            for(auto v1: adj[i]){
                for(auto v2: adj[j]){
                    if(g[v1].find(v2) == g[v1].end()){
                        cout << "-1";
                        return 0;
                    }else{
                        ed++;
                    }
                }
            }
        }
    }
    if(ed != m){
        cout << -1;
        return 0;
    }
    loop(i,1,n+1)cout << gr[i]+1 << " ";
   return 0;
}