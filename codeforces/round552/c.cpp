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

const ll maxn = 1e5;
int arr[7];

ll d(ll k,ll a, ll b, ll c){
  ll i = k;
  ll ans = 0;
  do{
    if(arr[i] == 1 && a){
      a--;
      ans++;
    }

    else if(arr[i] == 2 && b){
      b--;
      ans++;
    }

    else if(arr[i] == 3 && c){
      c--;
      ans++;
    }
    else {
      return ans;
    }
    i++;
    i%=7;
  }while(i != k);
}

int main(){
  ll a,b,c;
  cin >> a >> b >> c;
  arr[0] = 1;
  arr[1] = 2;
  arr[2] = 3;
  arr[3] = 1;
  arr[4] = 3;
  arr[5] = 2;
  arr[6] = 1;
  ll ans = min(a/3,min(b/2,c/2));
  a-=(ans*3);
  b-=(ans*2);
  c-=(ans*2);
  ans*=7;
  ll mx = 0;
  for(int i = 0; i < 7;++i){
    mx = max(d(i,a,b,c),mx);
  }
  cout << ans+mx;
  return 0;
}
