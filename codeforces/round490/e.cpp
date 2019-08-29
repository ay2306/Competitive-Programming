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
L<int> adj[5001];
L<int> good;
L<int> bad;
L<int> cnt;
int n,m;
int *visited;
void dfsUtil(int i, int visited[]){
    visited[i] = 1;
    for(int i = 0; i < adj[s].size(); ++i){
        if(!visited[adj[s][i]])dfsUtil(adj[s][i], visited);
    }
}

void dfs(int s){
    visited[s] = 1;
    for(int i = 0; i < adj[s].size(); ++i){
        if(!visited[adj[s][i]])dfsUtil(adj[s][i], visited);
    }
}
int main(){
    visited = (int*)calloc(n+1,sizeof(int));
    int s;
    cin >> n >> m >> s;
    for(int i = 0; i < n; ++i){
        int a,b;
        cin >> a >> b;
        adj[a].pb(b);
    }
    dfs(s);
    for(int i = 1; i <= n; ++i){
        if(visited[i])good.pb(i);
        else bad.pb(i);
    }
    for(int i = 0; i < bad.size(); ++i){
        memset(visited,0,(n+1)*sizeof(int));
        dfs(s);
        int c = 0;
        for(int i = 1; i <= n; ++i){
            if(visited[i])c++;
        }  
        cnt.pb(c); 
    }
    return 0;
}