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

ll con(__int128 a){
    ll op = a;
    return a;
}

__int128 f(ll y, ll k){
    __int128 a = 1;
    __int128 b = ((1LL << (k+1)) - 3);
    __int128 c = -2*y;
    __int128 d = sqrt(b*b-4*a*c);
    // cout << con(a) << " " << con(b) << " " << con(c) << " " << con(d) << '\n';
    if(d*d == b*b-4*a*c){
        if((-b+d) % 2 == 0 && ((-b+d)/2)%2 == 1){
            return (d-b)/2;
        }
    }
    return -1;
}

int main(){
    ll y;
    ll inp;
    cin >> inp;
    y = inp;
    ll k = 0;
    __int128 p = 1;
    set<ll> ans;
    while(k < 62){
        __int128 op = f(y,k);
        if(op > 0){
            ll abc = op;
            // cout << abc << "\n";
            ans.insert(op*(p<<k));
        }
        k++;
    }
    if(ans.size() == 0)cout << -1;
    else{
        for(auto i: ans)cout << i << " ";
    }
   return 0;
}