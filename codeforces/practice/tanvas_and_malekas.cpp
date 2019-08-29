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

int main(){
  int n,m;
  cin >> n >> m;
  string a(n,'*');
  string b;
  cin >> b;
  V<int> pp(m);
  loop(i,0,n)cin >> pp[i];
  loop(i,0,n)pp[i]--;
  sort(all(pp));
  int last_filled = -1;
  for(int i = 0; i < pp.size(); ++i){
      if(last_filled < pp[i]){
          for(int j = 0; j < b.size(); ++j){a[j+pp[i]] = b[j];last_filled = j + pp[i];}
      }else{
          int next = last_filled + 1;
          int j = next - pp[i];
          for(; j < b.size(); ++j){a[j+pp[i]] = b[j];last_filled = j + pp[i];}
      }
  }
  ll ans = 1;
  loop(i,0,n){
      if(a[i] == '*')ans+=
  }
  return 0;
}
