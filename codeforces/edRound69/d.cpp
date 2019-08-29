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
const ll maxn = 3e5 + 10;
const ll inf = 1e9;
const double pi = acos(-1);
ll arr[maxn];
int main(){
    FAST
    ll n,m,k;
    cin >> n >> m >> k;
    V<ll> arr(n);
    loop(i,0,n)cin >> arr[i];
    int i = 0;
    int j = 0;
    ll ans = 0;
    ll mxh = 0;
    for(int i1 = 0; i1 < n; ++i1){
        mxh += arr[i1];
        if(mxh <= 0){
            while(i <= j){
                ans = max(ans,mxh-long(k*(ceil(double(j-i+1)/m))));
                if(arr[i] < arr[j]){
                    mxh-=arr[i];
                    i++;
                }else{
                    mxh-=arr[j];
                    j--;
                }
            }
            mxh = 0;
            i = i1+1;
            j = i1+1;
        }else{
            j++;
        }
    }
    while(i <= j && mxh > 0){
        ans = max(ans,mxh-long(k*(ceil(double(j-i+1)/m))));
        if(arr[i] < arr[j]){
            mxh-=arr[i];
            i++;
        }else{
            mxh-=arr[j];
            j--;
        }
    }
    cout << ans;
   return 0;
}