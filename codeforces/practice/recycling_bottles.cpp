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
#define sq(a) ((a)*(a))
#define PDD P<ld,ld>
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);
ld dist(PDD a, PDD b){
    return sqrt(sq(a.F-b.F)+sq(a.S-b.S));
}
int main(){
    PDD a,b,t;
    cin >> a.F >> a.S >> b.F >> b.S >> t.F >> t.S;
    int n;
    cin >> n;
    V<ld> td(n);
    V<PDD> A(n);
    V<PDD> B(n);
    ld sum = 0;
    loop(i,0,n){
        PDD k;
        cin >> k.F >> k.S;
        td[i] = dist(t,k);
        sum+=td[i];
        A[i] = {-td[i] + dist(k,a),i};
        B[i] = {-td[i] + dist(k,b),i};
    }
    sum*=2;
    sort(all(A));
    sort(all(B));
    ld ans = sum + A[0].F;
    ans = min(ans,sum+B[0].F);
    if(n > 1){
        if(A[0].S != B[0].S)ans = min(ans,sum+A[0].F+B[0].F);
        else{
            ans = min({ans,sum+A[0].F+B[1].F,sum+A[1].F+B[0].F});
        }
    }
    printf("%.10Lf\n",ans);
   return 0;
}