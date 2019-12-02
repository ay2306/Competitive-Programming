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
    int n,m;
    cin >> n >> m;
    V<V<int>> arr(n,V<int> (m));
    V<V<int>> ans(n,V<int> (m));
    loop(i,0,n){
        loop(j,0,m){
            cin >> arr[i][j];
        }
    }
    loop(i,0,n){
        loop(j,0,m){
            int v1 = 0;
            int v2 = 0;
            int v3 = 0;
            if(i-1 >= 0 && j-1 >= 0){
                v1 = ans[i-1][j-1];
            }
            if(i-1 >= 0){
                v2 = ans[i-1][j];
            }
            if(i-1 >= 0 && j+1 < m){
                v3 = ans[i-1][j+1];
            }
            ans[i][j] = max({arr[i][j],v1,v2,v3});
        }
    }
    loop(i,0,n){
        loop(j,0,m){
            cout << (ans[i][j] == arr[i][j]);
        }
        cout << "\n";
    }
}

int main(){
    FAST
    FILE_READ_IN
   int t = 0;
   cin >> t;
   while(t--){
       solve();
   }
   return 0;
}