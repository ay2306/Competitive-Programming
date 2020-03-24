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
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);

struct node{
    unordered_map<bool,node*> child;
    int cnt;
    node(){
        cnt = 0;
    }
};
node *root = new node();
void add(ll val){
    node *cur = root;
    for(int _bit = 34; _bit >= 0; _bit--){
        bool nxt = ((1LL << _bit) & (val)) != 0;
        if(cur->child.find(nxt) == cur->child.end())cur->child[nxt]=new node();
        cur = cur->child[nxt];
        cur->cnt++;
    }
}
void remove(ll val){
    node *cur = root;
    for(int _bit = 34; _bit >= 0; _bit--){
        bool nxt = ((1LL << _bit) & (val)) != 0;
        cur = cur->child[nxt];
        cur->cnt--;
    }
}
ll mn(ll x){
    ll ans = 0;
    node *cur = root;
    for(int _bit = 34; _bit >= 0; _bit--){
        bool nxt = ((1LL << _bit) & (x)) != 0;
        if(cur->child.find(nxt) != cur->child.end() && cur->child[nxt]->cnt > 0){
            cur = cur->child[nxt];
        }else{
            cur = cur->child[!nxt];
            ans+=(1LL << _bit);
        }
    }
    return ans;
}
int main(){
    int n; ll c;
    scanf("%d",&n);
    V<ll> a(n);
    for(ll &i: a)scanf("%lld",&i);
    loop(i,0,n){
        scanf("%lld",&c);
        add(c);
    }
    loop(i,0,n){
        c = mn(a[i]);
        printf("%lld ",c);
        // printf("(%lld, %lld) ",c,c^a[i]);
        remove(c^a[i]);
    }
   return 0;
}