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
#define MAXN 25
using namespace std;

void solve(){
    int n;
    cin >> n;
    V<ll> arr(n);
    V<int> op(n-1);
    cin >> arr[0];
    loop(i,1,n){
      char c;
      cin >> c;
      if(c == '-')op[i-1] = -1;
      else op[i-1] = 1;
      cin >> arr[i];
    }
    V<V<ll> > max_cost(n+1,V<ll>(n+1,LLONG_MIN));
    V<V<ll> > min_cost(n+1,V<ll>(n+1,LLONG_MAX));
    loop(i,0,n)max_cost[i][i] = arr[i];
    loop(i,0,n)min_cost[i][i] = arr[i];
    for(int size = 2; size <= n; ++size){
      for(int i = 0; i <= n - size; ++i){
        int j = i + size - 1;
        for(int k = i; k < j && k < n-1; ++k){
          ll mx = 0;
          ll mn = 0;
          if(op[k] == -1){
            mx = max_cost[i][k] - min_cost[k+1][j];
            mn = min_cost[i][k] - max_cost[k+1][j];
          }else{
            mx = max_cost[i][k] + max_cost[k+1][j];
            mn = min_cost[i][k] + min_cost[k+1][j];
          }
          min_cost[i][j] = min(min_cost[i][j],mn);
          max_cost[i][j] = max(max_cost[i][j],mx);
        }
      }
    }
    // loop(i,0,n+1){
    //   loop(j,0,n+1){
    //     if(min_cost[i][j] == LLONG_MAX)cout << "inf\t";
    //     else cout << min_cost[i][j] << "\t";
    //   }
    //   cout << endl;
    // }
    // cout << endl;
    // loop(i,0,n+1){
    //   loop(j,0,n+1){
    //     if(max_cost[i][j] == LLONG_MIN)cout << "inf\t";
    //     else cout << max_cost[i][j] << "\t";
    //   }
    //   cout << endl;
    // }
    cout << max_cost[0][n-1] << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}
