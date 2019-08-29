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

int n,m;

void solve(){
    V<V<int>> arr(n,V<int>(m,0));
    loop(i,0,n){
        loop(j,0,m)cin >> arr[i][j];
    }
    V<V<int>> dp(n,V<int>(m,0));
    loop(i,0,n){
        dp[i][0] = (arr[i][0] == 0);
        loop(j,1,m){
            if(arr[i][j] == 1)dp[i][j] = 0;
            else dp[i][j] = dp[i][j-1] + 1;
        }
    }
    V<V<int>> height(n,V<int>(m,0));
    loop(i,0,m){
        height[0][i] = (arr[0][i] == 0);
        loop(j,1,n){
            if(arr[j][i] == 1)height[j][i] = 0;
            else height[j][i] = height[j-1][i] + 1;
        }
    }
    int ans = 0;
    V<V<PII>> saved_answer(n,V<PII> (m,mp(0,0)));
    loop(i,0,n){
        loop(j,0,m){
            if(arr[i][j])continue;
            int w = dp[i][j];
            ans = max(ans,w);
            int h = height[i][j];
            if(i == 0){
                saved_answer[i][j] = mp(dp[i][j],1);
            }else{
                if(min(dp[i][j],saved_answer[i-1][j].first)*(saved_answer[i-1][j].second+1) >= w){
                    saved_answer[i][j] = mp(min(dp[i][j],saved_answer[i-1][j].first),saved_answer[i-1][j].second+1);
                    ans = max(min(dp[i][j],saved_answer[i-1][j].first)*(saved_answer[i-1][j].second+1),ans);
                }else{
                    saved_answer[i][j] = mp(dp[i][j],1);
                }
            }
        }
    }
    cout << ans << "\n";
}

int main(){
    FILE_READ_IN
    FILE_READ_OUT
    while(1){
        cin >> n >> m;
        if(n == 0 && m == 0)break;
        solve();
    }
   return 0;
}