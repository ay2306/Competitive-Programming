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
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);

void print(char i, int s){
   loop(j,0,s)cout << i;
}
int main(){
   string a;
   cin >> a;
   unordered_map<char,V<int>> m;
   int n = a.size();
   loop(i,0,n){
      m[a[i]].pb(i);
   }
   if(m['a'].size() >= n/2){
      print('a',a.size()/2);
      return 0;
   }
   if(m['b'].size() >= n/2){
      print('b',a.size()/2);
      return 0;
   }
   if(m['c'].size() >= n/2){
      print('c',a.size()/2);
      return 0;
   }
   string ans = "";
   for(int i = 0; i+1 < n; i++){
      if(m[a[i]].back() <= i && m[a[i+1]].back() <= i+1)continue;
      if(m[a[i]].back() > m[a[i+1]].back()){
         ans+=a[i];
         m[a[i]].pop_back();
         i++;
      }else{
         ans+=a[i+1];
         m[a[i+1]].pop_back();
         i++;
      }
   }
   string f = "";
   for(int i = 0; i < ans.size(); ++i)f+=ans[i];
   if(ans.size()*2 < n/2 && ans.size()*2 +1 >= n/2){
      if(*ans.rbegin() == 'a')f+='b';
      if(*ans.rbegin() == 'a')f+='c';
      if(*ans.rbegin() == 'a')f+='a';
   }
   for(int i = ans.size()-1 ; i >= 0; --i)f+=ans[i];
   if(f.size() >= n/2){
      cout << f;
   }else{
      cout << "IMPOSSIBLE";
   }
   return 0;
}