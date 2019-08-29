#include<iostream>
#include<list>
#include<limits.h>
using namespace std;

class graph{
    int vertices;
    list<int> *edges;
public:
    graph(int vertices);
    void addEdge(int source, int destination);
    bool BFS(int start, int dest, int pred[], int dist[]);
    void printList(list<int> li);
    void  shortestPath(int start, int destination);
    void DFS(int start);
    void DFSstep(int node, bool *visited,int level);
    // void BFSstep(int node, bool *visited, int level)
    void krushkal();
};

graph::graph(int vertices){
    this->vertices = vertices;
    edges = new list<int>[vertices+1];
}

void graph::addEdge(int source, int destination){
    edges[source].push_back(destination);
    edges[destination].push_back(source);
}

bool graph::BFS(int start, int dest, int pred[], int dist[]){
    bool *visited = new bool[vertices+1];
    for(int i = 1; i <= vertices; ++i){
        visited[i] = false;
        dist[i] = INT_MAX;
        pred[i] = -1;
    }
    list<int> q;
    q.push_back(start);
    visited[start] = true;
    dist[start] = 0;
    // cout << start << "  ";
    while(!q.empty()){
        int s = q.front();
        // cout << s << "  ";
        // printList(q);
        q.pop_front();
        for(list<int>::iterator i = edges[s].begin(); i != edges[s].end(); ++i){
            if(!visited[*i]){
                visited[*i] = true;
                dist[*i] = dist[s] + 1;
                pred[*i] = s;
                q.push_back(*i);
                if(*i == dest)return true;
            }
        }
    }
    // BFSstep(start,visited,0);
    return false;
}

void graph::DFS(int start){
    bool *visited = new bool[vertices+1];
    for(int i = 0; i <= vertices; ++i){
        visited[i] = false;
    }
    int level = 0;
    visited[start] = true;
    cout << start << " ";
    for(list<int>::iterator itr = edges[start].begin(); itr != edges[start].end(); ++itr){
        DFSstep(*itr, visited, level+1);
    }
}

void graph::DFSstep(int node, bool *visited, int level){
    visited[node] = true;
    cout << node << " ";
    for(list<int>::iterator itr = edges[node].begin(); itr != edges[node].end(); ++itr){
        if(!visited[*itr]){
            DFSstep(*itr, visited, level+1);
        }
    }
}
void graph::shortestPath(int start, int destination){
    int *pred = new int[vertices + 1];
    int *dist = new int[vertices + 1];
    if(!BFS(start,destination,pred,dist)){
        cout << "PATH NOT CONNECTED";
        return;
    }
    int crawl = destination;
    list<int> path;
    path.push_front(crawl);
    while(pred[crawl] != -1){
        path.push_front(pred[crawl]);
        crawl = pred[crawl];
    }
    for(list<int>::iterator itr  = path.begin(); itr != path.end(); ++itr){
        cout << *itr << "\t";
    }
    cout << "\nLength of shortest Path = " << (path.size()-1) << endl;

}

void graph::printList(list<int> li){
    cout << "LIST: ";
    for(list<int>::iterator itr = li.begin(); itr != li.end(); ++itr){
        cout << *itr << "\t";
    }
    cout << endl;
}

void graph::krushkal(){
    int *id = new int[vertices+1];
    for(int i = 1; i < n; ++i)id[i]=i;
    int root(int x){
        while(id[x] != x){
            id[x] = id[id[x]]
            x = id[x];
        }
        return x;
    }
    void UNION(int x, int y){
        int p = root(x);
        int q = root(y);
        id[p] = id[y];
    }

    
}


int main(){
    graph g(7);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(4,2);
    g.addEdge(5,2);
    g.addEdge(6,3);
    g.addEdge(7,3);
    // g.shortestPath(7,4);
    return 0;
}

// 1 2 3 4 5 6 7 8 9
// 9 8 7 6 5
