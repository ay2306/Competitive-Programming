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

int main(){
  FAST
  int n;
  cin >> n;
  V<int> a(n);
  multiset<int> b;
  loop(i,0,n){
    cin >> a[i];
  }
  loop(i,0,n){
    int k;
    cin >> k;
    b.insert(k);
  }
  V<int> c;
  loop(i,0,n){
    int x = a[i];
    x = n-a[i];
    // auto it = lower_bound(b.begin(),b.end(),x);
    auto it = b.lower_bound(x);
    if(it == b.end()){
      c.pb((a[i]+*b.begin())%n);
      b.erase(b.begin());
    }
    else if(*it == x){
      c.pb(0);
      b.erase(it);
    }else{
      int c1 = (a[i]+*b.begin())%n;
      int c2 = (a[i]+*it)%n;
      if(c1 <= c2){
        c.pb(c1);
        b.erase(b.begin());
      }else{
        c.pb(c2);
        b.erase(it);
      }
    }
  }
  for(auto i:c)cout << i << " ";
  return 0;
}
