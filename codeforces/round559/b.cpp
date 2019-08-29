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
  int n;
  cin >> n;
  V<PLL> arr(n);
  loop(i,0,n){
    cin >> arr[i].F;
    arr[i].S = i;
  }
  sort(all(arr));
  V<ll> mn(n);
  V<ll> mx(n);
  ll m1 = -1;
  ll m2 = n;
  for(int i = n-1; i >= 0; --i){
    mn[i] = m2;
    mx[i] = m1;
    m1 = max(m1,arr[i].S);
    m2 = min(m2,arr[i].S);
  }
  ll ans = 1e9;
  for(int i = 0; i < n; ++i){
    // printf("val = %lld, left = %lld, right = %lld, i = %d\n",arr[i].F,mn[i]+1,mx[i]+1,i+1);
    if(mx[i] != -1 && mx[i] > arr[i].S){
      ll diff = mx[i]-arr[i].S;
      diff = arr[i].F/diff;
      ans = min(diff,ans);
    }
    if(mn[i] != n && mn[i] < arr[i].S){
      ll diff = arr[i].S-mn[i];
      diff = arr[i].F/diff;
      ans = min(ans,diff);
    }
  }
  cout << ans;
  return 0;
}
