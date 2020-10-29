#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+10;
vector<pair<int,int>> g[N];
int w[N], t[N], n, a, b, tar, sub[N];

void dfs(int s = 1, int edge = -1){
    if(g[s].size() == 1 && ~edge)sub[edge]=1;
    for(auto& [v,edgeIndex]: g[s]){
        if(edgeIndex == edge)continue;
        dfs(v,edgeIndex);
        if(~edge)sub[edge]+=sub[edgeIndex];
    }
}

int diff(int i){
    return (w[i] - w[i]/2)*sub[i];
}

vector<int> get(int type){
    set<pair<int,int>> s;
    int sum = 0;
    for(int i = 1; i < n; ++i){
        if(t[i] != type)continue;
        s.emplace(diff(i),i);
        sum += w[i] * sub[i];
    }
    vector<int> res(1,sum);
    while(sum){
        int index = s.rbegin()->second;
        s.erase(prev(s.end()));
        sum -= diff(index);
        res.emplace_back(sum);
        w[index]>>=1;
        s.emplace(diff(index),index);
    }
    return res;
}

int32_t main(){
    int test;
    cin >> test;
    while(test--){
        cin >> n >> tar;
        fill(sub,sub+n+1,0);
        for(int i = 1; i <= n; ++i)g[i].clear();
        for(int i = 1; i < n; ++i){
            cin >> a >> b >> w[i] >> t[i];
            g[a].emplace_back(b,i);
            g[b].emplace_back(a,i);
        }
        dfs(1);
        auto one = get(1), two = get(2);
        int j = one.size() - 1;
        int i = -1, ans = INT_MAX;
        // for(auto i: one)cout << i << " ";
        // cout << endl;
        // for(auto i: two)cout << i << " ";
        // cout << endl;
        while(++i < (int)two.size()){
            while(j && two[i] + one[j-1] <= tar)j--;
            if(two[i] + one[j] <= tar)ans = min(ans,i+i+j);
        }
        cout << ans << "\n";
    }
    return 0;
}