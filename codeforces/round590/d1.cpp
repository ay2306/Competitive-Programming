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
#define ld long double
using namespace std;
// For ordered_set
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);
char a[1000100];
int tree[450000];
int n;

void build() {  // build the tree
   for(int i = 0; i < n; ++i){
      tree[n+i] = (1 << (a[i]-'0'));
   }
   for(int i = n- 1; i >= 0; --i){
      tree[i] = tree[i*2+1] | tree[2*i + 2];
   }
}

void update(int p) {  // set value at position p
   p+=n;
   tree[p] = a[p-n]-'0';
   while(p > 0){
      p >>= 1;
      tree[p] = tree[p*2] | tree[p*2 + 1];
   }
}

int query(int l, int r) {  // sum on interval [l, r)
   l+=n;
   r+=n;
   int ans = 0;
   while(l < r){
      // cout << l << " " << r << "\n";
      if(l & 1){
         ans|=(tree[l]);
         l++;
      }
      if(r & 1){
         r--;
         ans|=(tree[r]);
      }
      l>>=1;
      r>>=1;
   }
  return ans;
}

int active(int n){
   int ans = 0;
   while(n){
      ans+=(n&1);
      n>>=1;
   }
   return ans;
}

int main(){
   scanf("%s",a+1);
   int q;
   n = strlen(a);
   scanf("%d",&q);
   build();
   while(q--){
      int t;
      scanf("%d",&t);
      if(t == 1){
         int p;
         char c;
         scanf("%d %c",&p,&c);
         if(a[p] != c){
            a[p] = c;
            update(p);
         }
      }else{
         int l,r;
         scanf("%d %d",&l,&r);
         // l--;
         // r--;
         int k = query(l,r);
         printf("%d\n",active(k));
      }
   }
   return 0;
}