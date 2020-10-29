#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5+10;
const int inf = 1e9;
vector<int> g[N];
int n,sz[N],h[N],ans[N],start[N],en[N],timer,euler_tree[N],arr[N];
int w[N],bag[1<<22],z=22,cur;

int32_t main(){
    cin >> n;
    fill(bag,bag+(1<<22),-inf);
    for(int i = 2; i <= n; ++i){
        int s; char c;
        cin >> s >> c;
        g[s].emplace_back(i);
        w[i] = (1 << (c - 'a'));
    }
    function<void(int)> dfs1 = [&](int s){
        start[s] = timer++;
        sz[s] = 1;
        arr[start[s]] = s;
        for(auto &v: g[s]){
            h[v] = h[s] + 1;
            w[v] ^= w[s];
            dfs1(v);
            sz[s] += sz[v];
            if(sz[v] > sz[g[s][0]])swap(g[s][0],v);
        }
        en[s] = timer;
    };
    function<void(int,int)> dfs = [&](int s, int mainChain){
        for(auto &i: g[s]){
            if(i == g[s][0])continue;
            dfs(i,false);
            ans[s] = max(ans[s],ans[i]);
        }
        if(g[s].size()){
            dfs(g[s][0],true);
            ans[s] = max(ans[s],ans[g[s][0]]);
        }
        for(auto &i: g[s]){
            if(i == g[s][0])continue;
            for(int p = start[i]; p < en[i]; ++p){
                int u = arr[p];
                cur = max(cur, h[u]+bag[w[u]]-2*h[s]);
                for(int j = 0; j < z; ++j)
                    cur = max(cur, h[u]+bag[(w[u]^(1 << j))]-2*h[s]);
            }
            for(int p = start[i]; p < en[i]; ++p)
                bag[w[arr[p]]] = max(bag[w[arr[p]]],h[arr[p]]);
        }
        cur = max(cur, bag[w[s]]-h[s]);
        for(int j = 0; j < z; ++j)
            cur = max(cur, bag[(w[s]^(1 << j))]-h[s]);
        bag[w[s]] = max(bag[w[s]],h[s]);
        ans[s] = max(ans[s],cur);
        if(!mainChain){
            for(int p = start[s]; p < en[s]; ++p)bag[w[arr[p]]] = -inf;
        }
        cur = 0;
    };
    dfs1(1);
    dfs(1,true);
    for(int i = 1; i <= n; ++i)cout << ans[i] << " ";
    return 0;
}