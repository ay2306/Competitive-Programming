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
// using namespace __gnu_pbds;
// template <typename T>
// using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);


int main(){
   FAST
   int n,q;
   cin >> n ;
   V<ll> arr(n);
   loop(i,0,n)cin >> arr[i];
   V<ll> ch(n,-1);
   priority_queue<PLL,V<PLL>> po;
   cin >> q;
   loop(i,0,q){
      int t;
      cin >> t;
      if(t == 2){
         ll p;
         cin >> p;
         po.push(mp(i,p));
      }
      else{
         ll p,x;
         cin >> p >> x;
         arr[p-1] = x;
         ch[p-1] = i;
      }
   }
   if(po.size() == 0){
      loop(i,0,n)cout << arr[i] << " ";
      return 0;
   }
   priority_queue<PLL,V<PLL>> p;
   loop(i,0,n){
      p.push(mp(ch[i],i));
   }
   ll next_po = 0;
   while(po.size()){
      ll time = po.top().first;
      while(p.size() && p.top().first > time){
         arr[p.top().second] = max(arr[p.top().second],next_po);
         p.pop();
      }
      next_po = max(po.top().second,next_po);
      po.pop();
   }
   while(p.size()){
      arr[p.top().second] = max(arr[p.top().second],next_po);
      p.pop();
   }
   loop(i,0,n)cout << arr[i] << " ";
   return 0;
}