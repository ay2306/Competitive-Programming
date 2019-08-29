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
  int n;
  cin >> n;
  V<int> a(n);
  loop(i,0,n)cin >> a[i];
  unordered_map<int,V<PII> >  m;
  loop(r,0,n){
    int sum = 0;
    loopr(l,r,0){
      sum+=a[l];
      m[sum].pb(mp(l,r));
    }
  }
  int result = 0;
  V<PII> best;
  for(auto i: m){
      const V<PII> &pp = i.S;
      int cur = 0;
      int r = -1;
      V<PII> now;
      for(const auto& j: pp){
        if(j.first > r){
          cur++;
          now.pb(j);
          r = j.second;
        }
      }
      if(cur > result){
        result = cur;
        best = now;
      }
  }
  cout << result << "\n";
  for(const auto& i: best){
    printf("%d %d\n",i.F+1,i.S+1);
  }
    return 0;
}
