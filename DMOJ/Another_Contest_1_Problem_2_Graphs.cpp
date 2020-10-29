#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,n,m,q,lst = -1;
    scanf("%d%d%d",&n,&m,&q);
    vector<vector<int>> g(n+1);
    vector<pair<pair<int,int>,int>> arr;
    vector<int> dis(n+1),ans(q),sourced(n+1);
    for(int i = 1; i < n; ++i){
        scanf("%d%d",&a,&b);
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    for(int i = 0; i < q; ++i){
        scanf("%d%d",&a,&b);
        if(a > b)swap(a,b);
        arr.emplace_back(make_pair(a,b),i);
    }
    sort(arr.begin(),arr.end());
    function<void(int)> bfs = [&](int source){
        dis[source] = 0;
        queue<int> q;
        q.emplace(source);
        sourced[source] = source;
        while(q.size()){
            int u = q.front();
            q.pop();
            for(int i : g[u]){
                if(sourced[i] != source){
                    dis[i] = dis[u] + 1;
                    q.emplace(i);
                    sourced[i] = source;
                }
            }
        }
    };
    for(auto &i: arr){
        if(lst != i.first.first){
            lst = i.first.first;
            bfs(lst);
        }
        if(sourced[i.first.second] != lst)ans[i.second] = -1;
        else ans[i.second] = dis[i.first.second];
    }
    for(int i: ans)printf("%d\n",i);
    return 0;
}