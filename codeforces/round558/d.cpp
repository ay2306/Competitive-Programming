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
const ll inf = 1e9;
string a,b,c;
V<V<V<ll>>> dp;

int k,n,m;

void init()

int main(){
  cin >> a >> b >> c;
  k = a.size();
  n = b.size();
  m = c.size();
  dp = V<V<V<ll>>> (a.size()+1,V<V<ll>> (b.size()+1,V<ll> (c.size()+1,-inf)));
  a = " " + a;
  b = " " + b;
  c = " " + c;
  dp[0][0][0] = 0;
  loop(i,0,k){
    loop(ks,0,n+1){
      loop(kt,0,m+1){
        for(char c = 'a' ; c <= 'z' ; ++c){
            if(a[i+1] == '*' )
        }
      }
    }
  }
  return 0;
}
