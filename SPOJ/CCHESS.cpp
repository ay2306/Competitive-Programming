#include <bits/stdc++.h>
//For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define all(a) a.begin(),a.end()
#define ld long double
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);
int x[] = {1,1,-1,-1,2,2,-2,-2};
int y[] = {-2,2,-2,2,1,-1,1,-1};
ll dis[8][8][8][8];
void dijkstra(PII s){
    // printf("Source = %d %d\n",s.F,s.S);
    map<PLL,ll> k;
    map<PII,int> vis;
    k[s] = 0;
    priority_queue<P<ll,PLL>,V<P<ll,PLL>>,greater<P<ll,PLL>>> q;
    q.push(mp(0,s));
    while(q.size()){
        auto u = q.top().S;
        auto d = q.top().F;
        q.pop();
        if(vis.find(u) != vis.end())continue;
        vis[u] = 1;
        for(int i = 0; i < 8; ++i){
            ll x1 = u.F + x[i];
            ll y1 = u.S + y[i];
            if(x1 < 0 || x1 > 7 || y1 < 0 || y1 > 7)continue;
            if(vis.find(mp(x1,y1)) != vis.end())continue;
            if(k.find(mp(x1,y1)) == k.end()){
                k[mp(x1,y1)] = d + x1*u.F + y1*u.S;
            }
            k[mp(x1,y1)] = min(k[mp(x1,y1)],d + x1*u.F + y1*u.S);
            q.push(mp(k[mp(x1,y1)],mp(x1,y1)));
            // printf("From (%lld ,%lld) -> (%lld, %lld), cost = %lld\n",u.F,u.S,x1,y1,k[mp(x1,y1)]);
        }
    }
    for(auto &i: k){
        dis[s.F][s.S][i.F.F][i.F.S] = i.S;
    }
}

int main(){
    // FILE_READ_OUT
    // FILE_READ_IN
    memset(dis,-1,sizeof(dis));
    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            // cout << i << " " << j << "\n";
            dijkstra(mp(i,j));
        }
    }
    int a,b,c,d;
    cin >> a;
    // int t = 1;
    while(1){
        cin >> b >> c >> d;
        cout << dis[a][b][c][d] << '\n';
        if(cin >> a){

        }else{
            break;
        }
    }
   return 0;
}