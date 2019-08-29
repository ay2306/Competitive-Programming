/*
 ____________________________________________________________
|                                                            |
|                   Author: ay2306                           |
|____________________________________________________________|

*/
#include <bits/stdc++.h>
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
#define looprs(i,a,b,step) for(int i=a;i>=b;i-=step)
#define ull unsigned long long int
#define ll long long int
#define P pair
#define PLL pair<long long, long long>
#define PII pair<int, int>
#define PUU pair<unsigned long long int, unsigned long long int>
#define L list
#define V vector
#define D deque
#define ST set
#define MS multiset
#define M map
#define UM unordered_map
#define mp make_pair
#define pb push_back
#define pf push_front
#define MM multimap
#define F first
#define S second
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define MAXN 25
using namespace std;

int n;
V<V<int> > adj;
V<V<PII> > bst;
V<int> p;
V<int> dist;
V<int> Size;
V<int> bad;
V<int> value;
V<PII> res;

void dfs(int s, int par = -1, int d = 0){
    p[s] = par;
    dist[s] = d;
    for(auto i: adj[s]){
        if(i == par)continue;
        dfs(i,s,d+1);
    }
}

int getFarthest(int s){
    dfs(s);
    int res = s;
    for(int i = 0; i < n; ++i){
        if(bad[i])continue;
        if(dist[res] < dist[i]){
            res = i;
        }
    }
    return res;
}

int getBetter(int v, int u){
    auto a = mp(dist[v],value[v]);
    auto b = mp(dist[u],value[u]);
    if(a > b)return v;
    return u;
}

int getBest(int s, int par){
    int res = s;
    for(auto i: adj[s]){
        if(i == par || bad[i])continue;
        res = getBetter(res,getBest(i,s));
    }    
    return res;
}

PII cal(int s){
    dfs(s);
    V<int> ch;
    for(auto i: adj[s]){
        if(!bad[i]){
            ch.pb(i);
        }
    }
    if(ch.size() == 1){return mp(s,ch[0]);}
    vector<int> pref(ch.size());
    vector<int> suf(ch.size());
    vector<int> best(ch.size());
    for(int i = 0; i < ch.size(); ++i){
        int j = ch[i];
        best[i] = pref[i] = suf[i] = getBest(i,s);
    }
    for(int i = 0; i < ch.size(); ++i){
        pref[i] = getBetter(pref[i],pref[i-1]);
        suf[ch.size() - i -1] = getBetter();
        bst[i] = pref[i] = suf[i] = getBest(i,s);
    }

}

int main(){
    cin >> n;
    adj = V<V<int> > (n,V<int> ());
    bst = V<V<PII> > (n,V<PII> ());
    p = V<int> (n,0);
    Size = V<int> (n,0);
    dist = V<int> (n,0);
    bad = V<int> (n,0);
    value = V<int> (n,0);
    res = V<PII> (n);
    loop(i,1,n){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int root = -1;
    for(int i = 0; i < n; ++i){
        if(adj[i].size() > 2){
            root = i;
            dfs(i);
            break;
        }
    }
    for(int i = 0; i < adj.size(); ++i){
        if(adj[i].size() != 1)continue;
        int v = i;
        while(adj[v].size() < 3 && !bad[v]){
            bad[v] = true;
            v = p[v];
        }
        bst[v].pb(mp(dist[i]-dist[v],i));
    }
    for(int i = 0; i < n; ++i){
        if(bst[i].size() >= 2){
            sort(bst[i].rbegin(),bst[i].rend());
            value[i] = bst[i][0].first + bst[i][1].first;
            res[i] = mp(bst[i][0].second,bst[i][0].first);
        }
    }
    int u = getFarthest(root);
    int v = getFarthest(u);
    V<int> path;
    while(v!=u){
        path.push_back(v);
        v = p[v];
    }
    auto ans = cal(path[path.size()/2]);
}