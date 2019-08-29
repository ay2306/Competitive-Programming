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
#define MAXN 1001000
using namespace std;
int n;
vector<vector<int> > adj;
vector<bool> visited;
vector<int> color;
bool pos;
void dfs(int a, int c){
    visited[a] = true;
    color[a] = c;
    for(auto i: adj[a]){
        if(!visited[i])dfs(i,(c^1));
        else if(visited[i] && color[a]==color[i])pos = false;
    }
}

void solve(){
    pos = true;
    adj = vector<vector<int> > (n,vector<int> ());
    visited = vector<bool> (n,false);
    color = vector<int> (n,-1);
    while(1){
        int a,b;
        cin >> a >> b;
        if(a == 0 || b == 0){
            break;
        }
        a--;
        b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(int i = 0; i < n; ++i){
        if(!visited[i])dfs(i,1);
    }
    if(pos)cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    // FILE_READ
    while(1){
        cin >> n;
        // cout << n << "\n";
        if(n == 0)break;
        solve();
    }
    return 0;
}