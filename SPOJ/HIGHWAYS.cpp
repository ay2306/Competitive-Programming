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

vector<vector<PLL> > adj;
vector<bool> visited;
vector<ll> dis;
int n;
void dijkstra(int s){
    dis = vector<ll> (n,LLONG_MAX/2); 
    dis[s] = 0;
    priority_queue<PLL, V<PLL>, greater<PLL> > p;
    p.push(mp(dis[s],s));
    while(!p.empty()){
        PLL a = p.top();
        p.pop();
        ll x = a.second;
        ll w = a.first;
        if(visited[x])continue;
        visited[x] = true;
        for(auto i: adj[x]){
            int e = i.first;
            int w = i.second;
            if(dis[x] + w < dis[e]){
                dis[e] = dis[x]+w;
                p.push(mp(dis[e],e));
            }
        }
    }
}


void solve(){
    int m,Start,End;
    cin >> n >> m >> Start >> End;
    visited = vector<bool> (n,false); 
    adj = vector<vector<PLL> > (n,vector<PLL> ());
    while(m--){
        ll a,b,w;
        cin >> a >> b >> w;
        a--;
        b--;

        //asdasd
        adj[b].pb(mp(a,w));
        adj[a].pb(mp(b,w));
    }
    dijkstra(Start-1);
    if(dis[End-1] == LLONG_MAX/2){
        cout << "NONE\n";
    }else{
        cout << dis[End-1] << "\n";
    }
}

int main(){
    // FILE_READ
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}