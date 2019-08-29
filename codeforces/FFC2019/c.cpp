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
using namespace std;

const ll maxn = 1e5;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    V<V<int> > a;
    V<V<int> > b;
    V<int> a1;
    loop(i,1,n/2+1)a1.pb(i);
    a.pb(a1);
    a1.clear();
    for(int i = n/2+1; i <= n; ++i)a1.pb(i);
    b.pb(a1);
    int ans = 0;
    loop(ooo,0,9){
      int as = 0;
      for(auto &i: a)as+=i.size();
      int bs = 0;
      for(auto &i: b)bs+=i.size();
      if(as == 0 || bs == 0)break;
      cout << as << " " << bs << " ";
      for(auto &i: a){
        for(auto &j: i){
          cout << j << " ";
        }
      }
      for(auto &i: b){
        for(auto &j: i){
          cout << j << " ";
        }
      }
      cout << endl;
      int res;
      cin >> res;
      if(res == -1)exit(0);
      ans = max(ans,res);
      V<V<int> > ta;
      V<V<int> > tb;
      //First half of a and First half of b
      for(auto &i: a){
        V<int> t;
        for(int j = 0; j < i.size()/2+1; ++j){
          t.pb(i[j]);
        }
        ta.pb(t);
      }
      for(auto &i: b){
        V<int> t;
        for(int j = 0; j < i.size()/2+1; ++j){
          t.pb(i[j]);
        }
        ta.pb(t);
      }
      for(auto &i: a){
        V<int> t;
        for(int j = i.size()/2+1; j < i.size(); ++j){
          t.pb(i[j]);
        }
        tb.pb(t);
      }
      for(auto &i: b){
        V<int> t;
        for(int j = i.size()/2+1; j < i.size(); ++j){
          t.pb(i[j]);
        }
        tb.pb(t);
      }
      a = ta;
      b = tb;
    }
    cout << "-1 " << ans << endl;
  }
  return 0;
}
