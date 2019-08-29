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
#define MAXN 25
using namespace std;
V<string> arr;

void solve(){
  int n;
  cin >> n;
  arr = V<string> (n);
  storage = V<string> (n,"");
  V<bool> visited(n,false);
  V<V<PII> > match(n);
  loop(i,0,n){
    cin >> arr[i];
    reverse(arr[i].begin(),arr[i].end());
  }
  int mx = 0;
  loop(i,0,n){
    loop(j,i+1,n){
      int l = 0;
      loop(k,0,min(size(arr[i],arr[j{
         = k;
        if(arr[i][k] != arr[j][k])break;
      }
      match[i].pb(mp(l,j));
    }
    sort(match[i].begin(),match[i].end());
    mx = max(match[i].back().F,mx);
  }
  bool visited[m]
  loop(i,1,mx+1){

  }
}

int main(){
    FAST ios_base::sync_with_stdio(false);
    cin.tie();
    FILE_READ_IN
    int t = 1;
    cin >> t;
    loop(i,1,t+1){
      printf("Case #%d: ",i);
      solve();
    }
    return 0;
}
