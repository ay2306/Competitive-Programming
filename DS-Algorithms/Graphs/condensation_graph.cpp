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
int cap;
class graph{
    int v,e;
    vector<unordered_set<int>> g;
    stack<int> s;
    int *in, *dis_time, *low_time, cur, *scc_numbers, totalScc ;
public:
    int _scc_cap;
    graph(){}
    graph(int v, int e = 0){
        this->v = v;
        this->e = e;
        g = vector<unordered_set<int>> (this->v+1);
        in = new int[this->v+1];
        low_time = new int[this->v+1];
        dis_time = new int[this->v+1];
        scc_numbers = new int[this->v+1];
        cur = 0;
        totalScc = 0;
    }
    void addEdge(int from, int to){
        this->g[from].insert(to);
    }
    graph* condensation(){
        scc();
        graph *con = new graph(totalScc);
        for(int _i = 1; _i <= this->v; ++_i){
            for(auto _j: g[_i]){
                if(scc_numbers[_j] == scc_numbers[_i])continue;
                con->addEdge(scc_numbers[_i],scc_numbers[_j]);
            }
        }
        con->_scc_cap=scc_numbers[cap];
        return con;
    }
    void scc(){
        for(int i = 1; i <= this->v; ++i)dis_time[i]=0;
        for(int i = 1; i <= this->v; ++i){
            if(dis_time[i] == 0)dfs(i);
        }

    }
    void dfs(int u){
        s.push(u);
        in[u] = true;
        dis_time[u] = low_time[u] = ++cur;
        for(auto v: g[u]){
            if(in[v])low_time[u]=min(low_time[v],low_time[u]);
            else if(dis_time[v] == 0){
                dfs(v);
                low_time[u] = min(low_time[u],low_time[v]);
            }
        }
        if(dis_time[u] == low_time[v]){
            stack_popper(u);
        }
    }
    void stack_popper(int start){
        totalScc++;
        while(1){
            int node = s.top();
            s.top();
            in[node] = false;
            scc_numbers[node] = totalScc;
            if(node == start)break;
        }
    }
    //* Function to be worked on condensation graph
    int dfs1(){
        int *in = new int[this->v];
        int ans = 0;
        loop(i,1,this->v+1){
            for(auto &j: g[i])in[j]++;
        }
        loop(i,1,this->v+1){
            ans+=(in[i]==0);
        }
        if(in[_scc_cap] == 0)ans--;
        return ans;
    }
};

int main(){
    int n,m;
    cin >> n >> m >> cap;
    graph obj(n);
    while(m--){
        int a,b;
        cin >> a >> b;
        obj.addEdge(a,b);
    }
    cout << obj.condensation()->dfs1();
   return 0;
}