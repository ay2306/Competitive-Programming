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

struct edge{
   int a;
   int b;
   ll c;
   edge(int _a, int _b, ll _c):a(_a),b(_b),c(_c){}
   bool operator< (const edge &rhs)const{
      return c < rhs.c;
   }
   bool operator> (const edge &rhs)const{
      return c > rhs.c;
   }
   bool operator== (const edge &rhs)const{
      return c == rhs.c;
   }
};

int n;
V<ll> k,c;
V<PLL> pos;
V<int> p;
V<edge> e;
int fp(int x){if(x != p[x])p[x]=fp(p[x]); return p[x];}
void un(int a, int b){p[fp(a)]=fp(b);}
int main(){
   cin >> n;
   k.resize(n+1);
   c.resize(n+1);
   pos.resize(n+1);
   p.resize(n+1);
   loop(i,0,n+1)p[i]=i;
   loop(i,1,n+1)cin >> pos[i].F >> pos[i].S;
   loop(i,1,n+1)cin>>c[i];
   loop(i,1,n+1)cin>>k[i];
   //add edges
   loop(i,1,n+1)e.emplace_back(edge(i,0,c[i]));
   loop(i,1,n+1){
      loop(j,i+1,n+1){
         ll cst = (k[i]+k[j])*(abs(pos[i].F-pos[j].F)+abs(pos[i].S-pos[j].S));
         e.emplace_back(edge(i,j,cst));
      }
   }
   ll ans = 0;
   V<int> self;
   multiset<edge> mst;
   multiset<edge> abc;
   sort(all(e));
   for(auto &i: e){
      // printf("(%d (%d), %d (%d))\n",i.a,fp(i.a),i.b,fp(i.b));
      if(fp(i.a) != fp(i.b)){
         un(i.a,i.b);
         mst.insert(i);
         ans+=i.c;
      }
   }
   for(auto &i: mst)if(i.b == 0)self.emplace_back(i.a);else abc.insert(i);
   cout << ans << "\n";
   cout <<  self.size() << "\n";
   for(auto &i: self)cout << i << " ";
   cout << "\n";
   cout <<  abc.size() << "\n";
   for(auto &i: abc)cout << i.a << " " << i.b << "\n";
   cout << "\n";
   
   return 0;
}