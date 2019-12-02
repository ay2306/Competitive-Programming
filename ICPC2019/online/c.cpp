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
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);

struct node{
    int index;
    unordered_map<int,node*> children;
};
class bitTrie{
    size_t sz;
    int highest_bit;
    node *parent;
    public:
    bitTrie(int __highest_bit = 63){
        sz = 0;
        highest_bit = __highest_bit;
        parent = new node();
    }
    void add(ll value,int index){
        sz++;
        node *current = parent;
        for(int _bit = highest_bit; _bit >= 0; --_bit){
            int _active = ((value >> _bit)&1);
            if(_active == 1){
                if(current->children.find(1) == current->children.end()){
                    current->children[1] = new node();
                }
                current = current->children[1];
            }else if(_active == 0){
                if(current->children.find(0) == current->children.end()){
                    current->children[0] = new node();
                }
                current = current->children[0];
            }
            current->index = index;
        }
    }
    pair<ll,int> getMinXor(ll x) const {
        ll ans = 0;
        ll temp = 1;
        int finalIndex;
        node *current = parent;
        for(int _bit = highest_bit; _bit >= 0; --_bit){
            int _active = ((x >> _bit)&1);
            if(_active == 0){
                if(current->children.find(0) != current->children.end()){
                    current = current->children[0];
                }else{
                    ans |= (temp << _bit);
                    current = current->children[1];
                }
            }else if(_active == 1){
                if(current->children.find(1) != current->children.end()){
                    current = current->children[1];
                }else{
                    ans |= (temp << _bit);
                    current = current->children[0];
                }
            }
            finalIndex = current->index;
        }
        return mp(ans,finalIndex);
    }
};

bool check(ll n, ll a){
   while(n){
      if(n % 2 == 1 && a % 2 == 0)return false;
      n/=2;
      a/=2;
   }
   return true;
}

void solve(){
   bitTrie b;
   int n,k;
   cin >> n >> k;
   string a;
   cin >> a;
   V<P<ll,int>> arr;
   loop(j,0,k){
      ll bit = 0;
      string g;
      cin >> g;
      for(auto i: g){
         bit |= (1 << (i-'a'));
      }
      // b.add(bit,j+1);
      arr.pb(mp(bit,j+1));
   }
   sort(all(arr));
   ll bit = 0;
   ll ans = 1;
   int last = 0;
   int ink = 0;
   int i = 0;
   for(; i < n; ++i){
      // cout << a[i] << " " << a[i]-'0' << "\n";
      bit |= (1 << (a[i]-'a'));
      // auto mn = b.getMinXor(bit);
      ll ind = lower_bound(all(arr),mp(bit,-1)) - arr.begin();
      while(ind < arr.size()){
         if(check(bit,arr[ind].F))break;
         ind++;
      }
      // cout << ind << " ";
      if(ind == arr.size()){
         bit = 0;
         bit |= (1 << (a[i]-'a'));
         ind = lower_bound(all(arr),mp(bit,-1)) - arr.begin();
         while(ind < arr.size()){
            if(check(bit,arr[ind].F))break;
            ind++;
         }
         // cout << ind << "\n";
         while(ink < i){
            ink++;
            cout << last << " ";
         }
         last = arr[ind].S;
      }
      // printf("index = %d bit = %lld, mn = (%lld, %d)\n",i,bit,mn.F,mn.S);
      last = arr[ind].S;
   }
   while(ink < i){
      ink++;
      cout << last << " ";
   }
   // cout << ans <<  "\n";
   cout <<  "\n";
}

int main(){
   int t = 0;
   cin >> t;
   while(t--){
       solve();
   }
   return 0;
}