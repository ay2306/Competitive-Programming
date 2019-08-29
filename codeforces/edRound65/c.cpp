/*
 ____________________________________________________________
|                                                            |
|                   Author: ay2306                           |
|____________________________________________________________|

*/
#include <bits/stdc++.h>
//For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define ord_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
const ll maxn = 1e5;
V<int> parent;
V<int> Rank;
int fp(int x){
  while(x != parent[x]){
    parent[x] = parent[parent[x]];
    x = parent[x];
  }
  return x;
}

void un(int a,int b){
  a = fp(a);
  b = fp(b);
  if(Rank[a] < Rank[b]){
    parent[a] = b;
  }else{
    parent[b] = a;
    if(Rank[a] == Rank[b])Rank[a]++;
  }
}

int main(){
  FAST
  int n,m;
  cin >> n >> m;
  parent = V<int> (n,0);
  Rank = V<int> (n,0);
  loop(i,0,n)parent[i] = i;
  loop(aa,0,m){
    int k = 0;
    cin >> k;
    if(k == 1){
      int a;
      cin >> a;
    }
    if(k > 1){
      int a;
      cin >> a;
      a--;
      loop(i,1,k){
        int b;
        cin >> b;
        b--;
        un(a,b);
      }
    }
  }
  unordered_map<int,int> k;
  loop(i,0,n){
    k[fp(i)]++;
  }
  loop(i,0,n){
    cout << k[fp(i)] << " ";
  }
  return 0;
}
