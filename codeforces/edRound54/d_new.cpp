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
vector<int> st;
vector<int> pr;
int n;
void dijkstra(int s){
    dis = vector<ll> (n,LLONG_MAX/2); 
    dis[s] = 0;
    pr[s] = 0;
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
                st[e] = st[x]+1;
                pr[e] = x;
            }
        }
    }
}


int main(){
    FAST
    int m,k;
    cin >> n;
    pr = vector<int> (n,0);
    st = vector<int> (n,0);
    visited = vector<bool> (n,false); 
    adj = vector<vector<PLL> > (n,vector<PLL> ());
    cin >> m >> k;
    map<PII,int> ed;
    loop(i,0,m){
        ll a,b,w;
        cin >> a >> b >> w;
        a--;
        b--;
        adj[a].pb(mp(b,w));
        adj[b].pb(mp(a,w));
        ed[mp(a,b)] = i+1;
    }
    dijkstra(0);
    map<PII,int> o;
    vector<PII> arr[n];
    for(int i = 0; i < n; ++i){
        arr[st[i]].pb(mp(i,pr[i]));
    }
    int c = 0;
    for(int i = 1; i < n; ++i){
        if(c == k)break;
        for(auto j: arr[i]){
            if(c == k)break;
            c++;
            o[j]++;
        }
    }
    V<int> ans;
    for(auto i: ed){
        int a = i.first.first;
        int b = i.first.second;
        if(o.find(mp(a,b)) != o.end() || o.find(mp(b,a)) != o.end()){
            ans.pb(i.second);
        }
    }
    sort(ans.begin(),ans.end());
    cout << ans.size() << "\n";
    for(auto i: ans){
        cout << i << " ";
    }
    return 0;
}