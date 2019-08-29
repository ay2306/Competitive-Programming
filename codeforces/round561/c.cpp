/*
 ____________________________________________________________
|                                                            |
|                   Author: ay2306                           |
|____________________________________________________________|

*/
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
#define ord_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
const ll maxn = 1e5;

V<ll> s;
ll small(ll val){
  if(s[0] > val)return -1;
  if(*s.rbegin() <=val)return s.size()-1;
  int low = 0;
  int high = s.size()-1;
  while(low <= high){
    int mid = (low+high)/2;
    if(s[mid] == val){
      if(mid != s.size()-1 && s[mid+1] == val){
        low = mid+1;
      }else{
        return mid;
      }
    }
    if(mid != 0 && s[mid] > val && s[mid-1] <= val)return mid-1;
    if(mid != s.size()-1 && s[mid] <= val && s[mid+1] > val)return mid;
    if(s[mid] < val){
      low = mid+1;
    }else{
      high = mid-1;
    }
  }
}


int main(){
  int n;
  cin >> n;
  ord_set k;
  set<ll> op;
  loop(i,0,n){
    ll a;
    cin >> a;
    s.pb(a);
    k.insert(a);
    op.insert(a);
  }
  ll ans = 0;
  sort(all(s));
  for(int i = 0; i < n; ++i){
    if(s[i] == 0)continue;
    ll low;
    ll high;
    if(s[i] < -1){
      ll left = -1*abs(s[i]/2 + s[i]%2);
      if(s[i] == -2){
        left = -1;
      }
      ll ind = small(left);
      if(ind != -1 && ind > i){
        ans += (ind-i);
        left = abs(left);
      }
      low = left;
    }
    else{
      low = s[i]+1;
    }
    high = abs(s[i])*2;
    ll low_ind = small(low);
    if(s[i] == -1){
      low = 1;
      high = 2;
    }
    ll high_ind;
    if(op.upper_bound(high) == op.end()){
      high_ind = n-1;
    }else{
      high_ind = k.order_of_key(*op.upper_bound(high)) - 1;
    }
    if(high_ind > i){
      ans+=(high_ind - i);
      if(low_ind > i)ans-=(low_ind - i - 1);
    }
    // printf("low_ind = %lld and high_ind = %lld\n",low_ind,high_ind);
  }
  cout << ans;
  return 0;
}
