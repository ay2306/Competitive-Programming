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
V<string> arr(70);
void solve(){
    int n,m;
    cin >> n >> m;
    int p = 0;
    loop(i,0,n)cin >> arr[i];
    for(int i = 0; i < n; ++i)for(auto j: arr[i])p+=(j == 'A');
    if(p == 0){
        cout <<  "MORTAL\n";
        return;
    }
    bool k = true;
    //  * CHECK FOR 0
    for(int i = 0; i < n && k; ++i)for(int j = 0; j < m && k; ++j)if(arr[i][j] != 'A')k=false;
    if(k){
        cout << 0 << "\n";
        return;
    }else k = true;
    // * Check for 1
    loop(i,0,n){
        if(arr[i][0] != 'A'){
            k = false;
            break;
        }
    }
    if(k){
        cout << 1 << "\n";
        return;
    }else k = true;
    loop(i,0,m){
        if(arr[0][i] != 'A'){
            k = false;
            break;
        }
    }
    if(k){
        cout << 1 << "\n";
        return;
    }else k = true;
    loop(i,0,n){
        if(arr[i][m-1] != 'A'){
            k = false;
            break;
        }
    }
    if(k){
        cout << 1 << "\n";
        return;
    }else k = true;
    loop(i,0,m){
        if(arr[n-1][i] != 'A'){
            k = false;
            break;
        }
    }
    if(k){
        cout << 1 << "\n";
        return;
    }else k = true;
    // * Check for 2
    loop(i,0,n){
        k = true;
        for(int j = 0; j < m && k; ++j){
            if(arr[i][j] != 'A')k = false;
        }
        if(k){
            cout << 2 << "\n";
            return;
        }
    }
    loop(j,0,m){
        k = true;
        for(int i = 0; i < n && k; ++i){
            if(arr[i][j] != 'A')k = false;
        }
        if(k){
            cout << 2 << "\n";
            return;
        }
    }
    if(arr[0][0] == 'A' || arr[n-1][0] == 'A' || arr[0][m-1] == 'A' || arr[n-1][m-1] == 'A'){
        cout << 2 << "\n";
        return;
    }
    // *  CHECK FOR 3
    loop(i,0,n){if(arr[i][0] == 'A'){
        cout << 3 << "\n";
        return;
    }}
    loop(i,0,n){if(arr[i][m-1] == 'A'){
        cout << 3 << "\n";
        return;
    }}
    loop(i,0,m){if(arr[0][i] == 'A'){
        cout << 3 << "\n";
        return;
    }}
    loop(i,0,m){if(arr[n-1][i] == 'A'){
        cout << 3 << "\n";
        return;
    }}
    cout << "4\n";
}

int main(){
    FAST
    int t;
    cin >> t;
    while(t--)solve();
   return 0;
}