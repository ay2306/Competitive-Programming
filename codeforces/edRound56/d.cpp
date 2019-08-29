/*
 ____________________________________________________________
|                                                            |
|                   Author: ay2306                           |
|____________________________________________________________|

*/
#include <bits/stdc++.h>
#define MOD 998244353
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
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define MAXN 25
using namespace std;

V<V<int> > adj;
V<bool> visited;
V<int> color;

ll modPower(ll a){
    if(a == 0)return 0;
    if(a == 1)return 2;
    ll p = modPower(a/2);
    p = ((p%MOD)*(p%MOD))%MOD;
    if(a%2){
        p = ((p%MOD)*(2%MOD))%MOD;    
    }
    return p;
}

pair<int,int> bipartite(int s){
    queue<int> q;
    q.push(s);
    visited[s] = true;
    PII ans = mp(0,0);
    color[s] = 0;
    ans.second = 1;
    while(q.size()){
        int a = q.front();
        q.pop();
        for(auto i: adj[a]){
            // printf("Edges = %d and %d and color = %d %d\n",i,a,color[i],color[a]);
            if(!visited[i]){
                color[i] = (1^color[a]);
                if(color[a])ans.first++;
                else ans.second++;
                visited[i] = true;
                q.push(i);
            }else if(color[i] == color[a])return mp(-1,-1);
        }
    }
    return ans;
}


void solve(){
    int n,m;
    ll ans = 1;
    cin >> n >> m;
    adj = V<V<int> > (n,V<int> ());
    visited = V<bool> (n,false);
    color = V<int> (n,-1);
    for(int i = 0; i < m; ++i){
        int a,b;
        cin >> a >> b;
        adj[a-1].pb(b-1);
        adj[b-1].pb(a-1);
    }
    for(int i = 0; i < n; ++i){
        if(!visited[i]){
            auto a = bipartite(i);
            // printf("ANS = %d %d\n",a.first, a.second);
            if(a.first == -1){
                cout << "0\n";
                return;
            }
            ans = ((ans%MOD)*((modPower(a.first)+modPower(a.second))%MOD))%MOD;
        }
    }
    cout << ans << "\n";
    return ;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}