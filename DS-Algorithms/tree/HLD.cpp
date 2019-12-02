#include <bits/stdc++.h>
//For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
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

class HLD_tree{
    size_t sz;
    unsigned int cur_pos;
    vector<int> parent,depth,heavy,head,pos;
    vector<vector<int>> adj;
    public:
        HLD_tree(){
            sz = 0;
            cur_pos = 0;
        }
        HLD_tree(int n){
            sz = (size_t)n;
            parent = vector<int> (n,0);
            depth = vector<int> (n,0);
            heavy = vector<int> (n,-1);
            head = vector<int> (n,0);
            pos = vector<int> (n,0);
            adj = vector<vector<int>> (n);
            cur_pos = 0;
        }
        void set_edges(){
            for(size_t i = 1; i < sz; ++i){
                int a,b;
                cin >> a >> b;
                a--;
                b--;
                adj[a].push_back(b);
                adj[b].push_back(a);
            }
        }
        int dfs(int v){
            int size = 1;
            int max_c_size = 0;
            for(int c: adj[v]){
                if(c == parent[v])continue;
                parent[c] = v;
                depth[c] = depth[v]+1;
                int c_size = dfs(c);
                size+=c_size;
                if(c_size > max_c_size){
                    max_c_size = c_size;
                    heavy[v] = c;
                }
            }
            return size;
        }
        void decompose(int v, int h){
            head[v] = h;
            pos[v] = cur_pos++;
            if(heavy[v] != -1){
                decompose(heavy[v],h);
            }
            for(int c : adj[v]){
                if(c == parent[v] || c == heavy[v])continue;
                decompose(c,c);
            }
        }
        void init(){
            dfs(0);
            decompose(0,0);
        }
};

int main(){

   return 0;
}