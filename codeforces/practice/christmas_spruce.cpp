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

int main(){
    int n;
    cin >> n;
    unordered_map<int,vector<int> > m;
    V<bool> isLeaf(n+1,false);
    V<int> leafCount(n+1,0);
    for(int i = 1; i < n; ++i){
      int a;
      cin >> a;
      if(m.find(a) == m.end()){
        m[a] = vector<int>();
      }
      m[a].pb(i+1);
    }
    for(int i = 1; i <= n; ++i){
      if(m.find(i) == m.end()){
        isLeaf[i] = true;
      }
    }
    for(int i = 1; i <= n; ++i){
      for(auto j: m[i]){
        if(isLeaf[j])leafCount[i]++;
      }
    }
    for(int i = 1; i <= n; ++i){
      if(m[i].size() != 0 && leafCount[i] < 3){
        cout << "No";
        return 0;
      }
    }
    cout << "Yes";
    return 0;
}
