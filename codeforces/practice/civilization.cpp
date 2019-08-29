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
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);
int n,m,q;
V<V<int>> adj;
V<int> dia;
vector<int> Rank;
vector<int> parent;
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
        Rank[b]+=Rank[a];
    }else{
        parent[b] = a;
        Rank[a]+=Rank[b];
    }
}

int findDiameter(int s, int o = 0){
    queue<int> q;
    unordered_map<int,int> visited;
    visited[s] = 1;
    q.push(s);
    unordered_map<int,int> level;
    level[s] = 0;
    while(q.size()){
        int u = q.front();
        q.pop();
        for(auto &i: adj[u]){
            if(visited.find(i) == visited.end()){
                visited[i] = 1;
                level[i] = level[u]+1;
                q.push(i);
            }
        }
    }
    if(visited.size() == 1)return 0;
    int mx = 0;
    int t = 0;
    for(auto &i: level){
        if(i.S > mx){
            mx = i.S;
            t = i.F;
        }
    }
    if(o)return mx;
    return findDiameter(t,1);
}


int main(){
    FAST
    cin >> n >> m >> q;
    parent = V<int> (n,0);
    Rank = V<int> (n,1);
    adj = V<V<int>> (n);
    dia = V<int>(n,0);
    loop(i,0,n)parent[i] = i;
    while(m--){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
        UNION(a,b);
    }
    unordered_set<int> unique_parent;
    loop(i,0,n){
        unique_parent.insert(findParent(i));
    }
    for(auto &i: unique_parent){
        dia[i] = findDiameter(i);
    }
    // cout << "Diameters = ";
    // for(auto &i: dia)cout << i << " ";
    // cout << endl;
    // cout << "Parents = ";
    // for(auto &i: parent)cout << i << " ";
    // cout << endl;
    while(q--){
        int t,a,b;
        cin >> t;
        if(t == 1){
            cin >> b;
            b--;
            cout << dia[findParent(b)] << "\n";
        }else{
            cin >> a >> b;
            a--;
            b--;
            if(findParent(a) == findParent(b))continue;
            int prevB = dia[findParent(b)];
            int prevA = dia[findParent(a)];
            UNION(a,b);
            dia[findParent(a)] = max(prevA,max(prevB,int(ceil(double(prevA)/2))+int(ceil(double(prevB)/2))+1));
            // cout << "Diameters = ";
            // for(auto &i: dia)cout << i << " ";
            // cout << endl;
        }
    }
   return 0;
}