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
struct pt{
   ll x,y,z,id;
   pt(ll a=1, ll b=1, ll c=1, ll id1 = 1): x(a),y(b),z(c),id(id1){}
   bool operator< (const pt &rhs){
      return (x < rhs.x || (x == rhs.x && (y < rhs.y || (y == rhs.y && z < rhs.z))));
   }
};
unordered_map<int,int> gone;

void solve_by_z(V<pt> &arr){
   sort(all(arr));
   int i = 0;
   while(i+1 < arr.size()){
      printf("%lld %lld\n",arr[i].id,arr[i+1].id);
      gone[arr[i].id]++;
      gone[arr[i+1].id]++;
      i+=2;
   }
}

void solve_by_y(V<pt> &arr){
   unordered_map<int,V<pt>> m;
   for(auto i: arr){
      m[i.y].pb(i);
   }
   for(auto &i: m){
      if(i.second.size() > 1)solve_by_z(i.second);
   }
   V<pt> nr;
   for(auto &i: m){
      if(i.second.size() % 2 )nr.pb(i.second.back());
   }
   sort(all(nr));
   int i = 0;
   while(i+1 < nr.size()){
      printf("%lld %lld\n",nr[i].id,nr[i+1].id);
      gone[nr[i].id]++;
      gone[nr[i+1].id]++;
      i+=2;
   }
}

int main(){
   int n;
   cin >> n;
   V<pt> arr;
   unordered_map<int,V<pt>> m;
   loop(i,0,n){
      ll a,b,c;
      cin >> a >> b >> c;
      m[a].pb(pt(a,b,c,i+1));
      arr.pb(pt(a,b,c,i+1));
   }
   for(auto &i: m){
      if(i.second.size() > 1)solve_by_y(i.second);
   }

   V<pt> nr;
   sort(all(nr));
   for(auto i: arr){
      if(gone[i.id] == 0){
         nr.pb(i);
      }
   }

   sort(all(nr));
   int i = 0;
   while(i+1 < nr.size()){
      printf("%lld %lld\n",nr[i].id,nr[i+1].id);
      gone[nr[i].id]++;
      gone[nr[i+1].id]++;
      i+=2;
   }
   return 0;
}