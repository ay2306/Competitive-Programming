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

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        V<string> arr(n);
        loop(i,0,n){
            cin >> arr[i];
            loop(j,0,m){
                if(arr[i][j] <= 'Z' && arr[i][j] >= 'A'){
                    arr[i][j]+=32;
                }
            }
        }
        bool f = false;
        loop(i,0,n){
            loop(j,0,m){
                if(arr[i][j] == 's'){
                    if(i+4 < n)f = f || (arr[i+1][j] == 'p' && arr[i+2][j] == 'o' && arr[i+3][j] == 'o' && arr[i+4][j] == 'n');
                    if(j+4 < m)f = f || (arr[i][j+1] == 'p' && arr[i][j+2] == 'o' && arr[i][j+3] == 'o' && arr[i][j+4] == 'n');
                }
                if(f)break;
            }
            if(f)break;
        }
        if(f)cout << "There is a spoon!\n";
        else cout << "There is indeed no spoon!\n";
    }
   return 0;
}