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

int n,m;
void solve(){
  V<int> rem(19);
  for(int i = 2; i <= 18; ++i){
    for(int j = 0; j < 18; ++j)printf("%d ",i);
    cout << endl;
    V<int> arr(18);
    loop(i,0,18)cin >> arr[i];
    int s = accumulate(arr.begin(),arr.end(),0);
    rem[i] = (s%i);
  }
  loop(i,1,m+1){
      bool pos = true;
      loop(j,2,19){
        if(m%j != rem[j]){
          pos = false;
          break;
        }
    }
    if(pos){
      cout << m << endl;
      int res;
      cin >> res;
      if(res == 1)return;
      else exit(0);
    }
  }
}


int main(){
    int t = 1;
    cin >> t >> n >> m;
    while(t--)solve();
    return 0;
}
