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

V<int> get(string a){
  V<int> ans(a.size() + 1,0);
  for(int i = 0; i < a.size(); ++i){
    ans[i+1] = a[i]-'a';
  }
  return ans;
}

int main(){
  int k;
  cin >> k;
    string s,t;
    cin >> s >> t;
    auto a = get(s);
    auto b = get(t);
    for(int i = k; i > 0; --i){
      a[i]+=b[i];
      if(i > 0){
        a[i-1] += a[i]/26;
        a[i]%=26;
      }
    }
    for(int i = 0; i <= k; ++i){
      int rem = a[i]%2;
      a[i]/=2;
      if(i+1 <= k){
        a[i+1]+=rem*26;
      }
    }
    for(int i = 1; i <= k; ++i){
      cout << (char)(a[i]+'a');
    }
    return 0;
}
