// /*
//  ____________________________________________________________
// |                                                            |
// |                   Author: ay2306                           |
// |____________________________________________________________|

// */
// #include <bits/stdc++.h>
// #define MOD 1000000007
// #define test int t; cin>>t; while(t--)
// #define init(arr,val) memset(arr,val,sizeof(arr))
// #define loop(i,a,b) for(int i=a;i<b;i++)
// #define loopr(i,a,b) for(int i=a;i>=b;i--)
// #define loops(i,a,b,step) for(int i=a;i<b;i+=step)
// #define looprs(i,a,b,step) for(int i=a;i>=b;i-=step)
// #define ull unsigned long long int
// #define ll long long int
// #define P pair
// #define PLL pair<long long, long long>
// #define PIIL pair<long long int,pair<int, int> >
// #define PUU pair<unsigned long long int, unsigned long long int>
// #define L list
// #define V vector
// #define D deque
// #define ST set
// #define MS multiset
// #define M map
// #define UM unordered_map
// #define mp make_pair
// #define pb push_back
// #define pf push_front
// #define MM multimap
// #define F first
// #define S second
// #define IT iterator
// #define RIT reverse_iterator
// #define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
// #define FILE_READ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
// #define MAXN 25
// using namespace std;
// V<V<int> > adj;
// V<bool> visited;
// V<int> Rank;
// V<int> parent;
// int n,m;

// int findParent(int x){
//     while(x != parent[x]){
//         parent[x] = parent[parent[x]];
//         x = parent[x];
//     }
//     return x;
// }
// void Union(int x, int y){
//     int px = findParent(x);
//     int py = findParent(y);
//     if(px == py)return;
//     if(Rank[px] > Rank[py]){
//         parent[py] = px;
//         return;
//     }
//     if(Rank[px] < Rank[py]){
//         parent[px] = py;
//         return;
//     }
//     if(Rank[px] == Rank[py]){
//         parent[py] = px;
//         Rank[px]++;
//         return;
//     }
// }
// void solve(){
//     // cin >> n >> m;
//     adj = V<V<int> > (n,V<int> ());
//     visited = V<bool> (n,false);
//     parent = V<int> (n,0);
//     Rank = V<int> (n,0);
//     loop(i,0,n)parent[i] = i;
//     priority_queue<PIIL,V<PIIL>, greater<PIIL> > p;
//     ll k = 0;
//     while(m--){
//         int a,b;
//         ll w;
//         cin >> a >> b >> w;
//         // a--;
//         // b--;
//         k+=w;
//         p.push(mp(w,mp(a,b)));
//     }
//     ll ans = 0;
//     while(p.size()){
//         PIIL a = p.top();
//         // printf("(%lld,(%d,%d))\n",a.first,a.second.first,a.second.second);
//         p.pop();
//         if(findParent(a.second.second) != findParent(a.second.first)){
//             Union(a.second.second,a.second.first);
//             ans+=a.first;
//         }
//     }
//     cout << k-ans << "\n";
// }

// int main(){
//     // FILE_READ
//     int t = 1;
//     // cin >> t;
//     while(1){
//         cin >> n >> m;
//         if(n == 0 && m == 0)break;
//         solve();
//     }
//     return 0;
// }
