#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
const int K = 11;
int n,a,cur;

vector<int> p,g[1000];

void dfs(int s, int par = 0, int d = 0){
    if(!d)p.emplace_back(s);
    for(auto &i: g[s])if(i!=par)dfs(i,s,1-d);
    if(d)p.emplace_back(s);
}

int main(){
    cin >> n;
    for(int i = 1; i < n; ++i){
        int a,b;
        cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    dfs(1);
    for(auto &i: p)cout << i << " ";
    return 0;
}