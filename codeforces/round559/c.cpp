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
using namespace std;

const ll maxn = 1e5;

int main(){
  ll n,m;
  cin >> n >> m;
  V<ll> a(n);
  V<ll> b(m);
  loop(i,0,n)cin >> a[i];
  loop(i,0,m)cin >> b[i];
  ll ans = accumulate(all(a),0*1LL);
  ans*=m;
  sort(all(a));
  sort(all(b));
  if(*max_element(all(a)) > *min_element(all(b))){
    cout << "-1";
    return 0;
  }
  loop(i,1,m){
    ans+=(b[i]-a[n-1]);
  }
  if(a[n-1] != b[0])ans+=(b[0]-a[n-2]);
  else ans+=(b[0]-a[n-1]);
  cout << ans;
  return 0;
}
