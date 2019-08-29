#include <bits/stdc++.h>
#define ull unsigned long long int
#define ll long long int
#define P pair
#define PLL pair<long long, long long>
#define PII pair<int, int>
#define PUU pair<unsigned long long int, unsigned long long int>
#define L list
#define V vector
#define S set
#define MS multiset
#define M map
#define mp make_pair
#define pb push_back
#define MM multimap
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();

using namespace std;

class graph{
    int v;
    V<int> *adj;
    vector<int> topologicalSortVector;
    int indexing;
public:
    graph(int v, int indexing){
        this->v = v;
        this->adj = new V<int>[v];
        this->indexing = indexing;
    }
    void addEdge(int a, int b){
        if(indexing == 1){
            a--;
            b--;
        }
        adj[a].push_back(b);
    }
    void topSort(){
        stack<int> s;
        int* visited = (int*)calloc(v,sizeof(int));
        for(int i = 0; i < v; ++i){
            if(!visited[i]){
                visited[i] = 1;
                s = topSortUtil(i,visited,s);
            }
        }
        while(s.size()){
            cout << s.top() + indexing << " " ;
            s.pop();
        }
    }
    stack<int> topSortUtil(int i,int *visited, stack<int> s){
        for(int j = 0; j < adj[i].size(); ++j){
            if(!visited[adj[i][j]]){
                visited[adj[i][j]] = 1;
                s = topSortUtil(adj[i][j],visited,s);
            }
        }
        s.push(i);
        return s;
    }
    void topSortDisplay(){
        topSort();
        cout << endl;
    }
};

int main(){
    int n,m;
    cin >> n >> m;
    graph g(n,1);
    for(int i =0 ; i < m; ++i){
        int a,b;
        cin >> a >> b;
        g.addEdge(a,b);
    }
    g.topSortDisplay();
    return 0;
}