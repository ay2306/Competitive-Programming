#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<pair<int,int>> *adj;
    bool bfs(int source, int sink, int parent[]);
public:
    Graph(int V);
    void addEdge(int v, int w);
    int fordFulkerson(int source, int sink);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<pair<int,int>>[V];
}
void Graph::addEdge(int v, int w, int weight){
    adj[v].push_back(make_pair(w,weight));
}

bool Graph::bfs(int source, int sink, int parent[]){
    bool *visited = new bool[V];
    for(int i = 0; i < V; ++i)visited[i]=false;
    queue<int> Queue;
    Queue.push(source);
    visited[source] = true;
    parent[source] = -1;
    while(!Queue.empty()){
        int q_front = Queue.front();
        Queue.pop();
        for(list<pair<int,int>>::iterator itr = adj[q_front].begin(); itr != adj[q_front].end(); ++itr){
            if(!visited[itr->first]){
                Queue.push(itr->first);
                visited[itr->first] = false;
                parent[itr->first] = q_front;
            }
        }
    }   
    return (visited[sink]);
}

int Graph::fordFulkerson(int source, int sink){
    int *parent = new int[V];
    int max_flow = 0;
    while(bfs(source, sink, parent)){
        int path_flow = INT_MAX;
        for(int v = sink; v!=source; v = parent[v]){
            int u = parent[v];
            path_flow = ()
        }
    }
}