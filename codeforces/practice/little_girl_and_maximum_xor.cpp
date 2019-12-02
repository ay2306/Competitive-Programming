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
 
int main(){
    ull l,r;
    cin >> l >> r;
    ull a = 0;
    ull b = 0;
    ull ans = 0;
    int N = 63;
    while(N >= 0){
         if((a | (1LL << N)) <= r && (b | ((1LL << N)-1)) >= l){
            a|=(1LL << N);
            ans|=(1LL << N);
        }else if((b | (1LL << N)) <= r  && (a | ((1LL << N)-1)) >= l){
            b|=(1LL << N);
            ans|=(1LL << N);
        }else{
            if((b | ((1LL << N)-1)) < l){
                b = (b | ((1LL << N)-1)) ;
            }
            if((a | ((1LL << N)-1)) < l){
                a = (a | ((1LL << N)-1)) ;
            }
        }
        N--;
    }
    if(a < b)swap(a,b);
    while(a <= l && N > 0){
        N = 62;
        ll val = (a | (1LL << N));
        if(val <= r){
            a = val;
        }
        N--;
        if(a >= l)break;
    }
    while(b <= l && N > 0){
        N = 62;
        ll val = (b | (1LL << N));
        if(val <= r){
            b = val;
        }
        N--;
        if(a >= l)break;
    }
    if(a > r || a < l || b > r || b < l)cout << a << " " << b;
    else cout << (a^b) ;
   return 0;
}