#include<iostream>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int> *adj;
    void APUtil(int v, bool visited[], int disc[], int low[], int parent[], bool ap[]);
public:
    Graph(int V);
    void addEdge(int v, int w);
    void AP();
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::APUtil(int u, bool visited[], int disc[], int low[], int parent[], int ap[]){
    static int time = 0;
    int children = 0;
    visited[u] = true;
    disc[u] = low[u] = ++time;
    list<int>::iterator itr;
    for(itr = adj[u].begin(); itr!=adj[u].end(); ++itr){
        int v = *itr;
        if(!visited[v]){
            children++;
            parent[v] = u;
            APUtil(v,visited,disc,low,parent,ap);
            low[u] = min(low[u],low[v]);
            if(parent[u] == NULL && children > 1){
                ap[u] = true;
            }
        }
    }
    
}
int main(){
    
    return 0;
}
