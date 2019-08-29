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

const ll maxn = 3e5 + 15;
const ll inf = 1e9;
V<int> adj[maxn];
int dp[maxn];
int deg[maxn];
int state[maxn];
int totalLeaves;

void dfs(int s = 1){
  for(auto i: adj[s])dfs(i);
  if(deg[s] == 0){
    dp[s] = 1;
  }
  else{
    if(state[s] == 0){
      dp[s] = 0;
      for(int i: adj[s]){
        dp[s]+=dp[i];
      }
    }else{
      dp[s] = dp[*adj[s].begin()];
      for(int i: adj[s]){
        dp[s] = min(dp[s],dp[i]);
      }
    }
  }
}


int main(){
  int n;
  cin >> n;
  loop(i,1,n+1){
    cin >> state[i];
  }
  loop(i,2,n+1){
    int x;
    cin >> x;
    deg[x]++;
    adj[x].pb(i);
  }
  loop(i,1,n+1){
    if(deg[i] == 0)totalLeaves++;
  }
  dfs();
  cout << totalLeaves - dp[1] + 1;
}
