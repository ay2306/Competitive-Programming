class Graph{
int V,E;
vector<vector<int> > adj;
public:
    Graph(int V, int E){
        this->V = V;
        this->E = E;
        adj = vector<vector<int> > (V, vector<int> ());
    }
    Graph(int V){
        this->V = V;
        adj = vector<vector<int> > (V, vector<int> ());
    }
    void addDirectedEdge(int,int);    
    void addEdge(int,int);
};
void Graph::addDirectedEdge(int a, int b){
    adj[a].pb(b);
}
void Graph::addEdge(int a, int b){
    adj[a].pb(b);
    adj[b].pb(a);
}