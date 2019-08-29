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
V<PII> arr;
unordered_map<int,unordered_map<int,int>> m;
ll n,k;

bool check(int k){
  for(auto &i: arr){
    int a = i.F + k;
    int b = i.S + k;
    if(a > n)a-=n;
    if(b > n)b-=n;
    bool p = false;
    if(m.find(a) != m.end() && m[a].find(b) != m[a].end())p = true;
    if(m.find(b) != m.end() && m[b].find(a) != m[b].end())p = true;
    if(!p)return false;
  }
  return true;
}

int main(){
  cin >> n >> k;
  loop(i,0,k){
    int a,b;
    cin >> a >> b;
    arr.pb(mp(a,b));
    m[a][b]++;
    m[b][a]++;
  }
  for(int i = 1; i*i <= n; ++i){
    if(n%i != 0)continue;
    int d1 = n/i;
    int d2 = i;
    if(d1 != n && check(d1)){
      cout << "Yes\n";
      return 0;
    }
    if(d2 != n && check(d2)){
      cout << "Yes\n";
      return 0;
    }
  }
  cout << "No\n";
  return 0;
}

