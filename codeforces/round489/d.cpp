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
#define FILE_READ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
using namespace std;
const int MAXN = 1e5 + 7;
ll a[MAXN],go[MAXN];
int main(){
  int n,k;
  cin >> n >> k;
  loop(i,0,n)cin >> a[i];
  go[n-1] = n;
  for(int i = n-2; i >= 0; --i){
    if(a[i+1] != 1)go[i] = i+1;
    else go[i] = go[i];
  }
  ll ans = 0;
  for(ll l = 0; l < n; ++l){
    int r = l;
    ans+=(k==1);
    ll f = a[l];
    ll s = a[l];
    while(go[r] != n && a[go[r]] <= (LLONG_MAX/f)){
      f*=a[go[r]];
      s+=go[r]-r-1 +a[go[r]];
      r = go[r];
      
    }
  }
  return 0;
}