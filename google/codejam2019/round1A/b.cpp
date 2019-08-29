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

bool check(PII a, PII b){
  if(a.F == b.F)return false;
  if(a.S == b.S)return false;
  if(a.F - a.S == b.F-b.S)return false;
  if(a.F + a.S == b.F+b.S)return false;
  return true;
}
stack<PII> s;
V<V<PII> > adj;
V<V<bool> > visited;
int r,c;

bool run(int i, int j){
  // printf("\n(%d, %d)",i,j);
  if(s.size() == r*c){
    return true;
  }
  if(visited[i][j])return false;
  if(s.size() == 0 || check(s.top(),mp(i,j))){
    s.push(mp(i,j));
    if(s.size() == r*c)return true;
    // printf("PUSHED");
    visited[i][j] = true;
    bool pos = false;
    loop(i1,1,r+1){
      loop(j1,1,c+1){
        if(visited[i1][j1] || !check(mp(i1,j1),s.top()))continue;
        pos = (pos || run(i1,j1));
        if(pos){
          return true;
        }
      }
    }
    if(!pos){
      visited[i][j] = false;
      s.pop();
      // printf("POPED %d %d\n",i,j);
      return false;
    }
  }else{
    return false;
  }
}

void solve(){
  scanf("%d%d",&r,&c);
  stack<PII> q;
  visited = V<V<bool> > (r+1,V<bool>(c+1,false));
  loop(i,1,r+1){
    loop(j,1,c+1){
      // printf("RUNNING %d %d\n",i,j);
      if(run(i,j))break;
    }
  }
  if(s.size() == r*c){
    printf("POSSIBLE\n");
    while(s.size()){
      printf("%d %d\n",s.top().F,s.top().S);
      s.pop();
    }
  }else{
    printf("IMPOSSIBLE\n");
    while(s.size())s.pop();
    return;
  }
}

int main(){
  // FILE_READ_OUT
    int t = 1;
    cin >> t;
    loop(i,0,t){
      printf("Case #%d: ",i+1);
      solve();
    }
    return 0;
}
