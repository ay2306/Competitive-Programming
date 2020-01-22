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
    int l;
    unordered_map<int,node*> child;
    node(int a):l(a){}
};
node *top;

void insert(ll val){
    node *temp = top;
    for(int i = 40; i >= 0; --i){
        int b = ((val >> i)&1);
        if(temp->child.find(b) == temp->child.end()){
            temp->child[b] = new node(0);
        }
        temp = temp->child[b];
        temp->l++;
    }
}

void del(ll val){
    node *temp = top;
    for(int i = 40; i >= 0; --i){
        int b = ((val >> i)&1);
        temp = temp->child[b];
        temp->l--;
    }
}

ll max_xor(ll x){
    node *temp = top;
    ll ans = 0;
    for(int i = 40; i >= 0; --i){
        int b = ((x >> i)&1);
        if(temp->child.find(1^b) != temp->child.end() && temp->child[1^b]->l > 0){
            ans|=(1LL << i);
            temp = temp->child[1^b];
        }else{
            if(temp->child.find(b) == temp->child.end())temp->child[b] = new node(0);
            temp = temp->child[b];
        }
    }
    return max(ans,x);
}

int main(){
    int q;
    cin >> q;
    top = new node(0);
    while(q--){
        char a;
        ll x;
        cin  >> a >> x;
        if(a == '-')del(x);
        if(a == '+')insert(x);
        if(a == '?')cout << max_xor(x) << "\n";
    }
   return 0;
}