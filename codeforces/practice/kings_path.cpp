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
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);
int x1,Y1,x2,y2;
map<PII,int> dis;
int main(){
   cin >> x1 >> Y1 >> x2 >> y2;
   int n;
   cin >> n;
   while(n--){
        int R;
        cin >> R;
        int l,r;
        cin  >> l >> r;
        loop(i,l,r+1)dis[{R,i}]=inf;
   }
   if(dis.find(mp(x1,Y1)) == dis.end() || dis.find(mp(x2,y2)) == dis.end()){
       cout << "-1";
       return 0;
   }
   dis[mp(x1,Y1)] = 0;
   multiset<P<int,PII>> q;
   q.insert(mp(0,mp(x1,Y1)));
   int dx[] = {0,0,-1,1,1,1,-1,-1};
   int dy[] = {1,-1,0,0,-1,1,-1,1};
   set<PII> vis;
   while(q.size()){
       auto u = *q.begin();
       q.erase(q.begin());
       if(vis.find(u.S) != vis.end()){
           continue;
       }
       vis.insert(u.S);
       loop(i,0,8){
            int x = u.S.F + dx[i];
            int y = u.S.S + dy[i];
            if(dis.find(mp(x,y)) == dis.end())continue;
            if(vis.find(mp(x,y)) == vis.end() && dis[mp(x,y)] > dis[u.S] + 1){
                dis[mp(x,y)] = dis[u.S]+1;
                q.insert(mp(dis[mp(x,y)],mp(x,y)));
            }
        }
   }
   if(dis[mp(x2,y2)] == inf)dis[mp(x2,y2)] = -1;
   cout << dis[mp(x2,y2)];
   return 0;
}