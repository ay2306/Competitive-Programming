#include <bits/stdc++.h>
#define init(arr,val) memset(arr,val,sizeof(arr))
#define FILE_READ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
using namespace std;

vector<vector<int> > adj;

void addEdge(int a, int b){
    adj[a].push_back(b);
}

void dfs(int a, bool *vis){
    // cout << a << " ";
    vis[a] = true;
    for(auto i: adj[a]){
        if(!vis[i])dfs(i,vis);
    }
}

int main(){
    FILE_READ
    int n,s;
    cin >> n >> s;
    adj = vector<vector<int> > (n+10,vector<int> ());
    for(int i = 0; i < s; ++i){
        int a,b;
        cin >> a >> b;
        addEdge(a,b);
    }
    int q;
    cin >> q;
    while(q--){
        int a,b,c;
        cin >> a >> b >> c;
        bool *fvis = new bool[n+10];
        bool *vis = new bool[n+10];
        init(fvis,false);
        init(vis,false);
        vis[b] = true;
        dfs(a,fvis);
        // cout << "\n";
        dfs(a,vis);
        // cout << "\n";
        if(fvis[c] && vis[c])cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}