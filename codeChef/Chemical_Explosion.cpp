#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define F first
#define S second
#define MP make_pair
#define LL long long
#define ULL unsigned long long
#define LB lower_bound
#define MOD1 1000000007
#define MOD2 1000000009
#define int LL
#define pii pair<int,int>
#define all(a) a.begin(), a.end()
const int maxn = 1e5 + 1;
int n;
vector<int> g[maxn];

struct diaHeight{
    int d;
    int h;
    diaHeight(int d, int h) : d(d), h(h){}   
};

diaHeight diameter(int root,int parent){
    if(g[root].size() == 1 && parent != -1){
        diaHeight ans(1,1);
        return ans;
    }
// //mxh = max height, smxh = second max height, mxd = max diameter
    int ansd, ansh, mxd = 0, mxh = 0, smxh = 0;

    for(auto node : g[root]){
        if(node == parent) continue;
        auto curr = diameter(node,root); 
        auto currh = curr.h, currd = curr.d;
        mxd = max({mxd,currd,mxh+currh+1});
        mxh = max(currh,mxh);
    } 
    ansh = mxh+1;
    ansd = mxd;
    return diaHeight(ansd,ansh);

}

void solve()
{
    scanf("%lld",&n);
    for(int i = 1; i <= n-1; i++){
        int u,v;
        scanf("%lld%lld",&u,&v);
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    int dia = diameter(1,-1).d;
    // cout << dia << "\n";
    cout << (dia)/2 << "\n";   
}

signed main()
{
    // static const int _ = []() {
    //     ios::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);
    //     return 0;
    // }();
    int t = 1;
    cin >> t;

    while (t--){
        solve();
    }
    return 0;
}