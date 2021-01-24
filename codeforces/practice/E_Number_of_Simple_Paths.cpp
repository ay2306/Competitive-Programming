#include<bits/stdc++.h>
#define int long long
using namespace std;
// DEBUGGER
// *
vector<string> vec_splitter(string s) {
	s += ',';
	vector<string> res;
	while(!s.empty()) {
		res.push_back(s.substr(0, s.find(',')));
		s = s.substr(s.find(',') + 1);
	}
	return res;
}
void debug_out(
vector<string> __attribute__ ((unused)) args,
__attribute__ ((unused)) int idx, 
__attribute__ ((unused)) int LINE_NUM) { cerr << endl; } 
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
	if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
	stringstream ss; ss << H;
	cerr << args[idx] << " = " << ss.str();
	debug_out(args, idx + 1, LINE_NUM, T...);
}
#ifdef LOCAL
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define debug(...) 42
#endif
// *
// DEBUGGER

const int N = 2e5+10;
vector<int> g[N];
int f,c_end,c_start,sub[N],cyc[N],vis[N],par[N];
void dfs(int s, int p = -1){
    sub[s] = 1;
    par[s] = p;
    vis[s] = 1;
    for(int &i: g[s]){
        if(i == p)continue;
        if(vis[i]){
            if(!f){
                c_start = s;
                c_end = i;
                f = 1;
            }
            continue;
        }
        dfs(i,s);
        sub[s] += sub[i];
    }
}

void solve(){
    f = 0;
    int n;
    scanf("%lld",&n);
    iota(cyc,cyc+1+n,0);
    fill(vis,vis+n+1,0);
    for(int i = 1; i <= n; ++i)g[i].clear();
    {
        for(int i = 0; i < n; ++i){
            int a,b;
            scanf("%lld%lld",&a,&b);
            g[a].emplace_back(b);
            g[b].emplace_back(a);
        }    
    }
    dfs(1);
    fill(vis,vis+n+1,0);
    f = 0;
    dfs(c_start);
    int cur = c_start;
    int sz = 0;
    vector<int> adj;
    while(~cur){
        // cout << cur << " ";
        sz++;
        cyc[cur] = c_end;
        cur = par[cur];
    }
    // cout << "\n";
    for(int i = 1; i <= n; ++i){
        if(cyc[i] != c_end)continue;
        int ss = 0;
        for(int j: g[i]){
            if(cyc[j] == c_end)continue;
            ss += sub[j];
        }
        adj.emplace_back(ss);
    }
    // for(int i = 1; i <= n; ++i)cout << par[i] << " ";
    // cout << "\n";
    int ans = n*(n-1)/2;
    debug(sz,ans);
    ans += (sz * (sz - 1) / 2);
    debug(sz,ans);
    ans += (n - sz) * (sz - 1);
    debug(sz,ans);
    int prv = 0;
    for(int i: adj){
        ans += prv * i;
        prv += i;
    }
    cout << ans << "\n";
}

int32_t main(){
    int t;
    scanf("%lld",&t);
    while(t--){
        solve();
    }
    return 0;
}