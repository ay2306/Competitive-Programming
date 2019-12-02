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
    int n;
    cin >> n;
    V<int> arr(n);
    loop(i,0,n)cin >> arr[i];
    sort(all(arr));
    if(arr[0] != 0){
        cout << -1;
        return 0;
    }
    ll s = accumulate(all(arr),0LL);
    if(s%3 == 1){
        bool done = false;
        loop(i,0,n){
            if(arr[i] % 3 == 1){
                done = true;
                arr[i]=-1;
                break;
            }
        }
        if(!done){
            int cnt = 0;
            loop(i,0,n){
                if(arr[i] % 3 == 2){
                    cnt++;
                    arr[i]=-1;
                    if(cnt == 2)break;
                }
            }
        }
    }
    else if(s % 3 == 2){
        bool done = false;
        loop(i,0,n){
            if(arr[i] % 3 == 2){
                done = true;
                arr[i]=-1;
                break;
            }
        }
        if(!done){
            int cnt = 0;
            loop(i,0,n){
                if(arr[i] % 3 == 1){
                    cnt++;
                    arr[i]=-1;
                    if(cnt == 2)break;
                }
            }
        }
    }
    bool nz = false;
    loopr(i,n-1,0){
        if(arr[i] != -1){
            if(arr[i] != 0)nz = true;
            if(arr[i] == 0 && !nz){
                cout << "0";
                return 0;
            }
            cout << arr[i];
        }
    }
   return 0;
}