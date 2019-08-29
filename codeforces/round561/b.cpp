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
int main(){
  int n;
  cin >> n;
  int k = -1;
  for(int i = 5; i < n; ++i){
    if(n%i == 0){
      if(n/i >= 5){
        k = i;
        break;
      }
    }
  }
  if(k == -1){
    cout << k;
    return 0;
  }
  V<V<char>> dp(k,V<char>(n/k,'b'));
  dp[0][0] = 'a';
  dp[0][1] = 'e';
  dp[0][2] = 'i';
  dp[0][3] = 'o';
  dp[0][4] = 'u';
  dp[1][0] = 'u';
  dp[1][1] = 'a';
  dp[1][2] = 'e';
  dp[1][3] = 'i';
  dp[1][4] = 'o';
  dp[2][0] = 'o';
  dp[2][1] = 'u';
  dp[2][2] = 'a';
  dp[2][3] = 'e';
  dp[2][4] = 'i';
  dp[3][0] = 'i';
  dp[3][1] = 'o';
  dp[3][2] = 'u';
  dp[3][3] = 'a';
  dp[3][4] = 'e';
  dp[4][0] = 'e';
  dp[4][1] = 'i';
  dp[4][2] = 'o';
  dp[4][3] = 'u';
  dp[4][4] = 'a';
  string ans = "";
  string p = "aeiou";
  for(int i = 5; i < k; ++i){
    for(int j = 0; j < n/k; ++j){
      dp[i][j] = p[j%5];
    }
  }
  for(int j = 5; j < n/k; ++j){
    for(int i = 0; i < 5; ++i){
      dp[i][j] = p[i];
    }
  }
  for(int i = 0; i < k; ++i){
    for(int j = 0; j < n/k; ++j)ans+=dp[i][j];
  }
  cout << ans;
  return 0;
}
