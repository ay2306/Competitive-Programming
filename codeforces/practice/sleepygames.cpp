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
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
using namespace std;

const ll maxn = 2e5 + 50;
V<int> adj[maxn];
int visited[maxn][2];
int win = 0;
int draw = 0;
int s;
V<int> path;
void dfs(int u = s, int p = 1){
    if(visited[u][p] == 1){
        draw = 1;
        return;
    }
    if(visited[u][p] == 2)return;
    path.pb(u+1);
    visited[u][p] = 1;
    if(adj[u].size() == 0 && p == 0){
        win = 1;
        return;
    }
    for(auto i: adj[u]){
        dfs(i,p^1);
        if(win == 1)return;
    }
    visited[u][p] = 2;
    path.pop_back();
}

int main(){
    int n,m;
    cin >> n >> m;
    for(int  i = 0; i < n; ++i){
        int a;
        cin >> a;
        while(a--){
            int k;
            cin >> k;
            k--;
            adj[i].pb(k);
        }
    }
    cin >> s;
    s--;
    dfs();
    if(win){
        cout << "Win\n";
        for(auto i: path)cout << i << " ";
        return 0;
    }else if(draw){
        cout << "Draw\n";
    }else{
        cout << "Lose\n";
    }
    return 0;
}