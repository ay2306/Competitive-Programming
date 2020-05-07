#include<bits/stdc++.h>
using namespace std;
int ans = (int)1e9+1,n,m,a,b,c,k;
vector<pair<int,int>> g[(int)1e5+1];
set<int> s;
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 1; i <= m; ++i){
        scanf("%d%d%d",&a,&b,&c);
        g[a].emplace_back(b,c);
        g[b].emplace_back(a,c);
    }
    for(int i = 0; i < k; ++i){
        scanf("%d",&a);
        s.emplace(a);
    }
    for(const int &i: s){
        for(auto& [u,d]: g[i]){
            if(s.count(u))continue;
            ans = min(ans,d);
        }
    }
    if(ans == (int)1e9+1)ans = -1;
    return printf("%d\n",ans),0;
}