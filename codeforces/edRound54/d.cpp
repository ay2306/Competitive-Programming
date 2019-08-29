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
#define MAXN 25
using namespace std;
vector<vector<PLL> > adj;
vector<int> parent;
vector<bool> visited;
vector<P<ll,P<PLL,int> > > edges;
vector<ll> dis;
int n,k;
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
            int w = i.second;
            int e = i.first;
            if(dis[x] + w < dis[e]){
                dis[e] = dis[x]+w;
                p.push(mp(dis[e],e));
            }
        }
    }
}
// template <typename T>
bool cmp(P<ll,P<PLL,int> > a, P<ll,P<PLL,int> > b){
    if(a.second.first.first < b.second.first.first)return true;
    if(a.second.first.first > b.second.first.first)return true;
    if(a.second.first.second < b.second.first.second)return true;
    if(a.second.first.second > b.second.first.second)return false;
    return true;
}

int main(){
    int m;
    cin >> n;
    visited = vector<bool> (n,false); 
    adj = vector<vector<PLL> > (n,vector<PLL> ());
    cin >> m >> k;
    loop(i,0,m){
        ll a,b,w;
        cin >> a >> b >> w;
        a--;b--;
        if(a > b)swap(a,b);
        adj[a].pb(mp(b,w));
        adj[b].pb(mp(a,w));
        edges.pb(mp(w,mp(mp(a,b),i+1)));
    }
    int s;
    cin >> s;
    dijkstra(0);
    sort(edges.begin(),edges.end(),cmp);
    vector<int> ans;
    for(auto i: edges){

    }
    return 0;
}