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
int n;
V<PLL> c;
V<ll> k;
V<PLL> pos;
int main(){
   cin >> n;
   loop(i,0,n){
      ll e,f;
      cin >> e >> f;
      pos.emplace_back(e,f);
   }
   loop(i,0,n){
      ll e;
      cin >> e;
      c.emplace_back(e,i);
   }
   loop(i,0,n){
      ll e;
      cin >> e;
      k.emplace_back(e);
   }
   sort(all(c),greater<PLL> ());
   ll cst = 0;
   V<PLL> ed;
   set<int> s;
   loop(i,0,n)cst+=c[i].F,s.insert(c[i].S);
   loop(i,0,n){
      ll mn = LLONG_MAX;
      int o;
      loop(j,i+1,n){
         if((abs(pos[c[i].S].F-pos[c[j].S].F)+abs(pos[c[i].S].S-pos[c[j].S].S))*(k[c[i].S]+k[c[j].S]) < mn){
            mn = (abs(pos[c[i].S].F-pos[c[j].S].F)+abs(pos[c[i].S].S-pos[c[j].S].S))*(k[c[i].S]+k[c[j].S]);
            o = j;
         }
      }
      if(mn < c[i].F){
         s.erase(c[i].S);
         cst-=c[i].F;
         cst+=mn;
         ed.emplace_back(c[i].S,c[o].S);
      }
   }
   cout << cst << "\n";
   cout << s.size() << "\n";
   for(auto &i: s)cout << i+1 << " ";
   cout << "\n";
   cout << ed.size() << "\n";
   for(auto &i: ed)cout << i.F+1 << " " << i.S+1 << "\n";
   return 0;
}