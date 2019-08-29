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
    void add(ll value){
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
        }
    }
    ll getMaxXor(ll x) const {
        if(sz == 0)return x;
        ll ans = 0;
        ll temp = 1;
        node *current = parent;
        for(int _bit = highest_bit; _bit >= 0; --_bit){
            int _active = ((x >> _bit)&1);
            if(_active == 1){
                if(current->children.find(0) != current->children.end()){
                    ans |= (temp << _bit);
                    current = current->children[0];
                }else{
                    current = current->children[1];
                }
            }else if(_active == 0){
                if(current->children.find(1) != current->children.end()){
                    ans |= (temp << _bit);
                    current = current->children[1];
                }else{
                    current = current->children[0];
                }
            }
        }
        return ans;
    }
};

int main(){
    FAST
    bitTrie obj;
    int n;
    cin >> n;
    V<ll> arr(n);
    loop(i,0,n)cin >> arr[i];
    V<ll> prefXor(n);
    prefXor[0] = arr[0];
    loop(i,1,n)prefXor[i] = arr[i]^prefXor[i-1];
    ll ans = 0;
    ll suffXor = 0;
    for(int i = n-1; i >= 0; --i){
        ll k = obj.getMaxXor(prefXor[i]);
        ans = max(ans,max(prefXor[i],k));
        suffXor ^= arr[i];
        ans = max(ans,suffXor);
        obj.add(suffXor);
    }
    ans = max(suffXor,ans);
    cout << ans;
   return 0;
}