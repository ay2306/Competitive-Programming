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
#define P pair
#define ll long long int
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
  FAST
  int n;
  cin >> n;
  V<int> arr(n);
  loop(i,0,n)cin >> arr[i];
  unordered_map<int,int> m;
  int mx = *max_element(all(arr));
  loop(i,0,n){
    m[arr[i]]++;
  }
  int ansl = -1;
  int ansr = -1;
  int ans = 0;
  int tl = -1;
  int tr = -1;
  int ta = 0;
  loop(i,1,mx+1){
    if(m[i] == 0){
      tl = -1;
      tr = -1;
      ta = 0;
      continue;
    }
    if(tl == -1)tl = i;
    if(tr == -1)tr = i;
    else tr++;
    ta += m[i];
    if(ta >= ans){
      ans = ta;
      ansl = tl;
      ansr = tr;
    }
    if(m[i] == 1){
      tl = tr;
      ta = m[i];
    }
    // printf("i = %d, tl = %d, tr = %d, ta = %d, freq = %d, ansl = %d, ansr = %d, ans = %d\n",i,tl,tr,ta,m[i],ansl,ansr,ans);
  }
  V<int> a,b;
  loop(i,ansl,ansr+1){
    a.pb(i);
    m[i]--;
  }
  loop(i,ansl,ansr+1){
    loop(j,0,m[i])b.pb(i);
  }
  sort(all(b),greater<int>());
  cout << a.size() + b.size() << "\n";
  for(auto &i: a)cout << i << " ";
  for(auto &i: b)cout << i << " ";
  return 0;
}
