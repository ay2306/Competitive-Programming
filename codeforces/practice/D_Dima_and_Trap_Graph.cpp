#include<bits/stdc++.h>
#define PII pair<int,int>
using namespace std;
const int N = 1010;
vector<pair<int,PII>> g[N];
priority_queue<pair<PII,PII>> q;
map<int,int> visL[N], visR[N];
int n,m,a,b,l,r,ans;
void bfs(){
    q.emplace(PII(1e7,1),PII(0,1e7));
    while(q.size()){
        auto node = q.top();
        q.pop();
        int u = node.first.second;
        int size = node.first.first;
        int L = node.second.first;
        int R = node.second.second;
        if(visL[u][L] || visR[u][R] || size < ans)continue;
        visL[u][L] = 1, visR[u][R] = 1;
        if(u == n){
            ans = max(ans,size);
            continue;
        }
        for(auto &i: g[u]){
            int v = i.first;
            int l = i.second.first;
            int r = i.second.second;
            l = max(l,L);
            r = min(r,R);
            if(r >= l)q.emplace(PII(r-l+1,v),PII(l,r));
        }
    }
}

int main(){
    cin >> n >> m;
    while(m--){
        cin >> a >> b >> l >> r;
        g[a].emplace_back(b,PII(l,r));
        g[b].emplace_back(a,PII(l,r));
    }
    bfs();
    if(ans)cout << ans;
    else cout << "Nice work, Dima!";
    return 0;
}