#include<bits/stdc++.h>
using namespace std;

const int N = 2020;
int n,cyc[N],cur,in_stack[N],dis[N],low[N],w;
vector<int> g[N];
stack<int> st;

void popper(int stop){
    cur++;
    while(true){
        int u = st.top();
        st.pop();
        cyc[u] = cur;
        in_stack[u] = false;
        if(u == stop)return;
    }
}

void dfs(int s = 1){
    static int cnt = 0;
    dis[s] = low[s] = ++cnt;
    in_stack[s] = true;
    st.emplace(s);
    for(int i: g[s]){
        if(dis[i] == 0)dfs(i);
        if(in_stack[i]){
            low[s] = min(low[s],low[i]);
        }
    }
    if(dis[s] == low[s])popper(s);
}

int main(){
    scanf("%d",&n);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            scanf("%d",&w);
            if(w)g[i].emplace_back(j);
        }
    }
    dfs();
    set<int> res;
    for(int i = 1; i <= n; ++i)res.emplace(cyc[i]);
    if(res.size() != 1)printf("NO\n");
    else printf("YES\n");
    return 0;
}