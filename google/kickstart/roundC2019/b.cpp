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


void solve(){
    static int t = 1;
    int r,c,k;
    cin >> r >> c >> k;
    V<V<PII>> arr(r,V<PII> (c,mp(0,0)));
    int tm = 0;
    loop(i,0,r){
        loop(j,0,c){cin >> arr[i][j].F;
        if(j == 0)arr[i][j].S = 1;
        else if(arr[i][j].F == arr[i][j-1].F) arr[i][j].S = arr[i][j-1].S +1;
        else arr[i][j].S = 1;
        }
    }
    // loop(i,0,r){
    //     loop(j,0,c){
    //         printf("(%d, %d) ",arr[i][j].F,arr[i][j].S);
    //     }
    //     printf("\n");
    // }
    int ans = 0;
    V<set<int> > col(1010);
    V<set<int> > row(1010);
    ans = max(1,ans);
    loop(i,0,r){
        loop(j,0,c){
            int mn =  arr[i][j].S;
            for(int k = i; k < r; ++k){
                mn = min(arr[k][j].S,mn);
                ans = max(ans,mn*(k-i+1));
                // printf(" i = %d, j = %d, k = %d, mn = %d, ans = %d\n",i,j,k,mn,ans);
            }
        }
    }
    printf("Case #%d: %d\n",t++,ans);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}