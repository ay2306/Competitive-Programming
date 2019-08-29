/*
 ____________________________________________________________
|                                                            |
|                   Author: ay2306                           |
|____________________________________________________________|

*/
#include <bits/stdc++.h>
#include <vector>
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
#define FILE_READ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define MAXN 1001000
using namespace std;

class Graph{
    int V;
    std::vector<int> *adj;
    std::set<int> forest;
    std::vector<int> Rank;
    std::vector<int> sz;
    std::vector<int> parent;
    int acorn;
    int tree;
    bool isCyclicUtil(int v, bool *visited, int parent);
public:
    Graph(int V);
    void addEdge(int a, int b);
    void UNION(int a, int b);
    int findParent(int a);
    void setForest();
    bool checkCycles(int i);
    pair<int,int> solve(){
        for(auto i: forest){
            // cout << "\n" << i;
            // if(adj[i].size() == 0)acorn++;
            // else{
            //     if(checkCycles(i))acorn++;
            // else tree++;

            // }
            if(sz[i] == 0)acorn++;
            else tree++;
        }
        // cout << "\n";
        return mp(acorn,tree);
    }
};

Graph::Graph(int V){
    this->V = V;
    this->tree = 0;
    this->acorn = 0;
    adj = new std::vector<int> [this->V];
    parent = std::vector<int> (this->V,0);
    sz = std::vector<int> (this->V,0);
    for(int i = 0; i < parent.size(); ++i)parent[i] = i;
    Rank = std::vector<int> (this->V,0);
}

void Graph::addEdge(int a, int b){
    adj[a].pb(b);
    adj[b].pb(a);
    UNION(a,b);
}

bool Graph::isCyclicUtil(int v, bool *visited, int parent){
    visited[v] = true;
    for(auto i: adj[v]){
        if(!visited[i])if(isCyclicUtil(i,visited,v))return true;
        else if(i != parent)return true;
    }
    return false;
}

void Graph::UNION(int x,int y){
    int px = findParent(x);
    int py = findParent(y);
    if(Rank[px] < Rank[py]){
        parent[px] = parent[py];
    }
    else if(Rank[px] > Rank[py]){
        parent[py] = parent[px];
    }
    else{
        parent[px] = parent[py];
        Rank[px]++;
        sz[py] = Rank[py]+1;
        // cout << "INC\n";
    }
}

int Graph::findParent(int x){
    while(x!=parent[x])x=parent[x];
    return x;
}

void Graph::setForest(){
    // for(int i = 0; i < this->V; ++i)cout << findParent(i) << " ";
    // cout << "\n";
    // for(int i = 0; i < this->V; ++i)cout << Rank[findParent(i)] << " ";
    // cout << "\n";
    for(int i = 0; i < this->V; ++i){
        if(!binary_search(forest.begin(),forest.end(),findParent(i))){
            forest.insert(findParent(i));
        }
    }
    // cout << "\n";
}
bool Graph::checkCycles(int a){
    bool *visited = new bool[this->V];
    for(int i = 0; i < this->V; ++i){
        visited[i] = false;
    }
    // visited[a] = true;
    for(auto i: adj[a]){
        if(!visited[i]){
            if(isCyclicUtil(i,visited,a))return true;
        }
    }
    return false;
}

void solve(){
    string a;
    cin >> a;
    vector<pair<char,char> > adj;
    while(a[0] != '*'){
        adj.pb(mp(a[1],a[3]));
        cin >> a;
    }
    cin >> a;
    unordered_map<char,int> m;
    int cnt = 0;
    for(int i = 0; i < a.length(); ++i){
        if(a[i]!=',')m[a[i]] = cnt++;
    }
    Graph g(cnt);
    for(auto i: adj){
        g.addEdge(m[i.first],m[i.second]);
    }
    g.setForest();
    auto ans = g.solve();
    printf("There are %d tree(s) and %d acorn(s).\n",ans.second,ans.first);
    // cout << ans.first << " " << ans.second << endl;
}

int main(){
    // FILE_READ
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}