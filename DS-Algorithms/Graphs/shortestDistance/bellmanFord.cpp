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
    int v;
    int e;
    int edge_no;
    V<int> *vec;
    int *dis;
    int ref;
public:
    graph(int v, int e){
        FAST;
        this->v = v;
        this->e = e;
        this->edge_no = 0;
        this->vec = new V<int>[e+2];
        this->dis = new int[e+2];
    }
    void bellmanFord(int source){
        ref = source;
        for(int i = 0; i < e+2; ++i){
            // vec[i].clear();
            dis[i] = INT_MAX;
        }
        dis[source] = 0;
        for(int i = 0; i < v-1; ++i){
            int j = 0;
            while(!vec[j].empty()){
                if(dis[vec[j][0]] + vec[j][2] < dis[vec[j][1]] ){
                    dis[vec[j][1]] = dis[vec[j][0]] + vec[j][2];
                }
                ++j;
            }
        }
    }
    void enterEdge(int from, int next, int weight){
        vec[this->edge_no].push_back(from);
        vec[this->edge_no].push_back(next);
        vec[this->edge_no].push_back(weight);
        this->edge_no++;
    }
    void setDistanceFrom(int a){
        bellmanFord(a);
    }
    int getDistanceTo(int a){
        return dis[a];
    }
    void displayDis(){
        for(int i = 0; i < v; ++i){
            if(i == ref)continue;
            cout << dis[i] << " ";
        }
    }
};

int main(){
    int n,m;
    cin >> n >> m;
    graph g(n,m);
    for(int i = 0; i < m; ++i){
        int a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        g.enterEdge(a,b,c);
    }
    g.setDistanceFrom(0);
    g.displayDis();
    return 0;
}