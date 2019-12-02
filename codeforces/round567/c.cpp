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
    int n,m;
    cin >> n >> m;
    V<string> arr(n);
    loop(i,0,n){
        cin >> arr[i];
    }
    V<V<int>> down(n,V<int> (m,0));
    V<V<int>> up(n,V<int> (m,0));
    V<V<int>> valid(n,V<int> (m,0));
    loop(i,0,n){
        loop(j,0,m){
            if(i == 0){
                up[i][j] = 1;
            }else{
                if(arr[i][j] == arr[i-1][j]){
                    up[i][j] = up[i-1][j]+1;
                }else{
                    up[i][j] = 1;
                }
            }
        }
    }
    loopr(i,n-1,0){
        loop(j,0,m){
            if(i == n-1){
                down[i][j] = 1;
            }else{
                if(arr[i][j] == arr[i+1][j]){
                    down[i][j] = down[i+1][j] + 1;
                }else{
                    down[i][j] = 1;
                }
            }
        }
    }
    struct last{
        char up,down,mid;
        int length;
        int row;
        int col;
    };
    last a;
    a.up = ' ';
    a.down = ' ';
    a.mid = ' ';
    a.length = 0;
    a.row = -1;
    a.col = -2;
    ll cont = 0;
    ll ans = 0;
    loop(i,1,n-1){
        loop(j,0,m){
            if(up[i][j] != 1){
                continue;
            }
            if(down[i][j] + i >= n){
                continue;
            }
            int upc = up[i-1][j];
            int dpc = down[down[i][j]+i][j];
            if(upc >= down[i][j] && dpc >= down[i][j]){
                valid[i][j] = 1;
                if(a.up == arr[i-1][j] && a.mid == arr[i][j] && a.down == arr[down[i][j]+i][j] && a.length == down[i][j] && i == a.row && j-1 == a.col){
                    cont++;
                    a.col = j;
                }else{
                    cont = 1;
                    a.up = arr[i-1][j] ;
                    a.mid = arr[i][j];
                    a.down = arr[down[i][j]+i][j];
                    a.length = down[i][j];
                    a.row = i;
                    a.col = j;
                }
                ans += cont;
            }
        }
    }
    cout << ans;
   return 0;
}