#include<bits/stdc++.h>
#define pb emplace_back
#define ll long long int
using namespace std;
const int N = 1e5+1000;
vector<ll> g[N],vec[N];
int col[N];
int n;
ll cnt[N],maxx[N],sum[N],sub[N],c[N];

void dfs(int v, int p){
    sub[v] = 1;
    for(auto i: g[v]){
        if(i != p){
            dfs(i,v);
            sub[v]+=sub[i];
        }
    }
}

void gooni(int v, int p, bool keep){
    int mx = -1;
    int bigchild = -1;
    vector<ll> smalls;
    set<ll> ss;
    for(auto i: g[v]){
        if(i != p){
            if(sub[i] > mx)mx=sub[i],bigchild=i;
        }
    }
    for(auto i: g[v]){
        if(i != p && i != bigchild)gooni(i,v,false);
    }
    if(bigchild != -1){
        gooni(bigchild,v,true);
        swap(vec[v],vec[bigchild]);
    }
    for(auto i: g[v]){
        if(i == p || i == bigchild)continue;
        for(auto x: vec[i]){
            vec[v].pb(x);
            smalls.pb(x);
            ss.insert(x);
        }
    }
    ss.insert(c[v]);
    vec[v].pb(c[v]);
    smalls.pb(c[v]);
    ll max1 = 0;
    for(auto x: smalls){
        cnt[x]++;
        max1 = max(max1,cnt[x]);
    }
    if(max1 < maxx[bigchild]){
        sum[v] = sum[bigchild];
        maxx[v] = maxx[bigchild];
    }else if(max1 == maxx[bigchild]){
        sum[v] = sum[bigchild];
        for(auto x: ss){
            if(cnt[x] == max1){
                sum[v] += x;
            }
        }
        maxx[v] = max1;
    }else{
        for(auto x: ss){
            if(cnt[x] == max1){
                sum[v] += x;
            }
        }
        maxx[v] = max1;
    }
    if(!keep){
        for(auto x: vec[v]){
            cnt[x]--;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; ++i)cin >> c[i];
    for(int i = 1; i < n; ++i){
        int a,b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(1,0);
    gooni(1,0,1);
    for(int i = 1; i <= n; ++i)cout << sum[i] << " ";
    return 0;
}