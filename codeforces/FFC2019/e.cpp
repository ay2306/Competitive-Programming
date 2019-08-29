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

V<int> tree;
V<int> lazy;
V<PII> arr;
int n,q;

void update(int l, int r, int node = 0, int start= 0, int end = n-1){
  if(start > r || end < l)return;
  // printf("l = %d, r = %d, node = %d, start = %d  end = %d\n",l,r,node,start,end);
  if(lazy[node] != 0){
    tree[node] += lazy[node];
    if(start != end){
      lazy[2*node+1] += lazy[node];
      lazy[2*node+2] += lazy[node];
    }
    lazy[node] = 0;
  }
  if(l <= start && end <= r){
    tree[node]++;
    if(start != end){
      lazy[2*node+1]++;
      lazy[2*node+2]++;
    }
    return;
  }
  update(l,r,2*node+1,start,(start+end)/2);
  update(l,r,2*node+2,(start+end)/2+1,end);
}

int query(int l, int r, int node = 0, int start = 0, int end = n-1){
  if(lazy[node] != 0){
    tree[node] += lazy[node];
    if(start != end){
      lazy[2*node+1] += lazy[node];
      lazy[2*node+2] += lazy[node];
    }
    lazy[node] = 0;
  }
  if(start > r || end < l)return 0;
  if(l <= start && end <= l){
    return tree[node];
  }
  int p1 = query(l,r,2*node+1,start,(start+end)/2);
  int p2 = query(l,r,2*node+2,(start+end)/2+1,end);
  return max(p1,p2);
}

int main(){
  cin >> n >> q;
  arr = V<PII> (n);
  tree = V<int> (4*n,0);
  lazy = V<int> (4*n,0);
  loop(i,0,n){cin >> arr[i].F; arr[i].S = i;}
  sort(arr.begin(),arr.end());
  while(q--){
    char a;
    cin >> a;
    int p;
    cin >> p;
    if(a == '>'){
      PII c = mp(p,n+1);
      int ind = upper_bound(arr.begin(),arr.end(),c) - arr.begin();
      cout << ind << "\n";
      if(ind == n)continue;
      update(ind,n-1);
    }else{
      PII c = mp(p,-1);
      int ind = lower_bound(arr.begin(),arr.end(),c) - arr.begin();
      cout << ind-1 << "\n";
      if(ind == 0)continue;
      update(0,ind-1);
    }
  }
  loop(i,0,n){
    int k = query(i,i);
    if(k%2 == 1)arr[i].F*=-1;
  }
  V<int> ans(n);
  loop(i,0,n){
    ans[arr[i].S] = arr[i].F;
  }
  loop(i,0,n){
    cout << ans[i] << " ";
  }
  
  return 0;
}
