class Graph{
int V,E;
vector<vector<int> > adj;
public:
    Graph(int V, int E){
        this->V = V;
        this->E = E;
        adj = vector<vector<int> > (V+1, vector<int> ());
    }
    Graph(int V){
        this->V = V;
        adj = vector<vector<int> > (V+1, vector<int> ());
    }
    void addDirectedEdge(int,int);    
    void addEdge(int,int);
    void BFS(int s);
    void DFS(int s);
};
void Graph::addDirectedEdge(int a, int b){
    adj[a].pb(b);
}
void Graph::addEdge(int a, int b){
    adj[a].pb(b);
    adj[b].pb(a);
}
void BFS(int s){
    vector<int> visited(this->V+1,0);
    visited[s] = 1;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        for(auto i: adj[q.front()]){
            if(!visited[i])q.push(i);
            visited[i] = 1;
        }
    }
}

void DFS(int s){
    visited<int> visited(this->V+1,0);
    visited[s] = 1;
    stack<int> q;
    q.push(s);
    while(!q.empty()){
        s = q.top();
        if(!visited[s]){
            cout << s << " ";
            visited[s] = 1;
        }
        for(auto i: adj[s]){
            if(!visited[i]){
                stack.push(i);
            }
        }
    }
}