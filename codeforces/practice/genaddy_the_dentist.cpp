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
    int n;
    cin >> n;
    V<P<PLL,PLL>> arr(n);
    loop(i,0,n)cin >> arr[i].F.F >> arr[i].S.F >> arr[i].S.S,arr[i].F.S = i;
    reverse(all(arr));
    V<int> ans;
    while(arr.size()){
        // printf("pain = %lld, fear = %lld, conf = %lld, ind = %lld\n",arr.back().F.F,arr.back().S.F,arr.back().S.S,arr.back().F.S);
        if(arr.back().S.S >= 0){
            ans.pb(arr.back().F.S);
            ll agg = 0;
            int c = 0;
            ll to_del;
            loopr(i,arr.size()-2,0){
                if(arr[i].S.S >= 0){
                    to_del = max(arr.back().F.F,0LL) + agg;
                    arr[i].S.S-=to_del;
                    arr.back().F.F--;
                    if(arr[i].S.S < 0)agg+=arr[i].S.F;
                }
            }
        }
        arr.pop_back();
    }
    cout << ans.size() << "\n";
    for(auto i: ans)cout << i+1 << " ";
   return 0;
}