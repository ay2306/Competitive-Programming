//https://codeforces.com/contest/27/problem/B
#include<bits/stdc++.h>
using namespace std;
const int N = 100;
int in[N],n,a,b,pos[N],t;
vector<int> g[N];
set<pair<int,int>> inc;
int main(){
    scanf("%d",&n);
    for(int i = 1; i < n*(n-1)/2; ++i){
        scanf("%d%d",&a,&b);
        g[a].emplace_back(b);
        in[b]++;
        inc.insert({a,b});
    }
    queue<int> q;
    for(int i = 1; i <= n; ++i)if(in[i] == 1)q.push(i),pos[i] = ++t;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int &i: g[u]){
            in[i]--;
            if(in[i] == 1){
                pos[i] = ++t;
                q.push(i);
            }
        }
    }
    for(int i = 1; i <= n; ++i)
        for(int j = i+1; j <= n; ++j)
            if(!inc.count({i,j}) && !inc.count({j,i}))
                if (pos[i] < pos[j])printf("%d %d",i,j);
                else printf("%d %d",j,i);
    return 0;
}