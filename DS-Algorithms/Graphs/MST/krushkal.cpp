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
using namespace std;

class graph{
    int *id,nodes,edges;
    pair<long long, pair<int,int> > *p;
    int root(int);
    void UNION(int x, int y);
public: 
    graph();
    long long krushkal();
};

graph::graph(){
    long long w;
    int x,y;
    cin >> nodes >> edges;
    id = new int[nodes + 1];
    p = new pair<long long, pair<int,int> >[edges+1];
    for(int i = 0; i <= nodes; ++i)id[i] = i;
    for(int i = 0; i < edges; ++i){
        cin >> x >> y >> w;
        p[i] = make_pair(w,make_pair(x-1,y-1));
    }
    sort(p,p+edges);
    cout << krushkal();
}

int graph::root(int x){
    while(id[x] != x){
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void graph::UNION(int x, int y){
    int p = root(x);
    int q = root(y);
    id[p] = id[q];
}

long long graph::krushkal(){
    long long cost, minimumCost =0;
    int x, y;   
    for(int i = 0; i < edges; ++i){
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        if(root(x) != root(y)){
            minimumCost+=cost;
            UNION(x,y);
        }
    }
    return minimumCost;
}

int main(){
 graph g;   
}