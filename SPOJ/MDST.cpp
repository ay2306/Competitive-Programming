#include<bits/stdc++.h>
using namespace std;
int t,n,a,b,c,d,m;

void solve(){
    scanf("%d",&n);
    vector<vector<int>> g(n+1);
    for(int i = 1; i <= n; ++i){
        scanf("%d%d",&m,&m);
        while(m--){
            scanf("%d",&a);
            g[i].emplace_back(a);
        }
    }
    
}

int main(){
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}