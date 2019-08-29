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
#define all(a) a.begin(),a.end()
#define PDD pair<double,double>
using namespace std;

const ll maxn = 1e5;
const double inf = 1e9;
int main(){
  int n;
  cin >> n;
  V<PDD> arr(n);
  loop(i,0,n)cin >> arr[i].F >> arr[i].S;
  map<PDD,int> m;
  map<double,int> m1;
  ll ans = 0;
  loop(i,0,n){
    loop(j,i+1,n){
      double slope,c;
      if(arr[j].F == arr[i].F){c = arr[j].F;slope=inf;}
      else{
        slope = (arr[j].S - arr[i].S)/(arr[j].F-arr[i].F);

        c = arr[i].S - slope*arr[i].F;

      }
      PDD a = mp(slope,c);
      if(m.find(a) == m.end())m[a]++;
    }
  }
  for(auto i: m)
  {
    // printf("y = %f (x) + %f\n",i.F.F,i.F.S);
    m1[i.F.F]++;
  }
  // for(auto i: m1){
  //   printf("slope = %f, count = %d\n",i.F,i.S);
  // }
  for(auto i: m){
    ans+=(m.size());
    ans-=m1[i.F.F];
  }
  cout << ans/2;
  return 0;
}
