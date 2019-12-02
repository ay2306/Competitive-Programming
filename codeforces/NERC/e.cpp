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
    FAST
    int n,m;
    cin >> n >> m;
    V<V<int>> arr(m,V<int>(n,0));
    loop(i,0,m){
        loop(j,0,n)cin >> arr[i][j];
    }
    V<int> ans(m+1);
    loop(c,0,n-1){
        V<PII> diff;
        V<int> tmp;
        loop(i,0,m){
            diff.pb(mp(arr[i][c] - arr[i][n-1],i));
        }
        sort(all(diff),greater<PII>());
        loop(i,1,diff.size()){
            diff[i].F+=diff[i-1].F;
        }
        if(diff[m-1].F >= 0){
            cout << 0;
            return 0;
        }   
        loop(i,0,diff.size()){
            if(diff[i].F < 0){
                int l = m-i;
                if(l < int(ans.size())){
                    loopr(j,m-1,i){
                        tmp.pb(diff[j].S);
                    }
                    ans = tmp;
                }
                break;
            }
        }
    }
    cout << ans.size() << "\n";
    for(auto i: ans)cout << i+1 << " ";
   return 0;
}