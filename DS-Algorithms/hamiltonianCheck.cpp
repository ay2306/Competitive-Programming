#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> *adj;
    bool hamiltonianCheckUtil(int v, bool visited[]);
public:
    Graph(int V);
    void addEdge(int v, int w);
    bool hamiltonianCheck(int v);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

bool Graph::hamiltonianCheckUtil(int v, bool visited[]){
    int k = 1;
    for(int i = 0; i < V; ++i){
        if(i == v)continue;
        if(visited[i] == true)++k;
        else{break;}
    }
    if(k == V)return true;
    if(visited[v])return false;
    visited[v] = true;
    list<int>::iterator itr;
    for(itr = adj[v].begin(); itr != adj[v].end(); ++itr){
        if(!visited[*itr]){
            if(hamiltonianCheckUtil(*itr,visited))return true;
        }
    }
    visited[v] = false;
    return false;
}

bool Graph::hamiltonianCheck(int v){
    bool *visited = new bool[V];
    for(int i = 0; i < V; ++i)visited[i]=false;
    return hamiltonianCheckUtil(v,visited);
}

int main(){
    int n,m,a,b;
    cin >> n >> m;
    Graph g(n);
    for(int i = 0; i < m ; ++i){
        cin >> a >> b;
        g.addEdge(a,b);
    }
    if(g.hamiltonianCheck(0))cout << "YES\n";
    else{cout << "NO";}
    return 0;
}