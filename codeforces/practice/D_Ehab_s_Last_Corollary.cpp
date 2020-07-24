// Um_nik's approach
// We just consider first k nodes
// Either there is a cycle, in which case we print it
// Other these nodes are tree and we just print odd height or even height

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a,b,n,m,k,par[N],lev[N];
vector<int> g[N];

void dfs(int s){
    lev[s] = lev[par[s]] + 1;
    for(int i: g[s]){
        if(i == par[s])continue;
        if(lev[i] == 0){
            par[i] = s;
            dfs(i);
        }else{
            int endingPoint = i;
            int cur = s;
            while(1){
                vector<int> ans;
                while(true){
                    ans.emplace_back(cur);
                    if(cur == endingPoint)break;
                    cur = par[cur];
                }
                cout << "2 " << ans.size() << "\n";
                for(int i: ans)cout << i << " ";
                exit(0);
            }
        }
    }
}


int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < m; ++i){
        cin >> a >> b;
        if(a > k || b > k)continue;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    for(int i = 1; i <= k; ++i)if(!lev[i])dfs(i);
    vector<int> ans[2];
    for(int i = 1; i <= k; ++i)ans[lev[i]&1].emplace_back(i);
    if(ans[0].size() < ans[1].size())swap(ans[1],ans[0]);
    ans[0].resize((k+1)/2);
    cout << "1\n";
    for(int i: ans[0])cout << i << " ";
    return 0;
}