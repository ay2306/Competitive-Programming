#include <bits/stdc++.h>
#define ull unsigned long long int
#define ll long long int
#define P pair
#define L list
#define V vector
#define S set
#define MS multiset
#define M map
#define mp make_pair
#define MM multimap
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define PII pair<long long,int>
using namespace std;

class graph{
    int v;
    V<PII> *adj;
public:
    graph(int v){
        this->v = v;
        this->adj = new V<PII>[v+1];
    }
    ll prims(int x);
    void addEdge(int,int,ll);
};

void graph::addEdge(int a, int b, ll w){
    adj[a-1].push_back(mp(w,b-1));
    adj[b-1].push_back(mp(w,a-1));
}
ll graph::prims(int x){
    bool *marked = (bool*)calloc(v+1,sizeof(bool));
    priority_queue<PII, V<PII>, greater<PII> > Q;
    int y;
    ll minCost = 0;
    PII p;
    Q.push(mp(0,x-1));
    while(!Q.empty()){
        p = Q.top();
        Q.pop();
        x = p.second;
        if(marked[x])continue;
        minCost += p.first;
        marked[x] = true;
        for(int i = 0; i < adj[x].size(); ++i){
            y = adj[x][i].second;
            if(!marked[y])Q.push(adj[x][i]);
        }
    }
    return minCost;
}


int main(){
    int n,m;
    cin >> n >> m;
    graph g(n);
    for(int i = 0; i < m; ++i){
        int a,b;
        ll c;
        cin >> a >> b >> c;
        g.addEdge(a,b,c);
    }
    cout << g.prims(1);
}