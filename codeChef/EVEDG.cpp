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
const ll N = 1e5+10;
const ll inf = 1e9;
const double pi = acos(-1);
int ct[N];
int ans[N];
int any[N];
void solve(){
    int n,m;
    cin >> n >> m;
    loop(i,0,n){
        ct[i] = 0;
        ans[i] = 1;
    }
    loop(i,0,m){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        ct[a]++;
        ct[b]++;
        any[a] = b;
        any[b] = a;
    }
    int k = 1;
    if(m % 2 == 1){
        bool found = false;
        k++;
        loop(i,0,n){
            if(ct[i] & 1){
                ans[i] = 2;
                found = true;
                break;
            }
        }
        if(!found){
            k++;
            loop(i,0,n){
                if(ct[i]){
                    ans[i] = 2;
                    ans[any[i]] = 3;
                    break;
                }
            }
        }
    }
    cout << k << "\n";
    loop(i,0,n)cout << ans[i] << " ";
    cout << "\n";
}

int main(){
    FAST
   int t = 0;
   cin >> t;
   while(t--){
       solve();
   }
   return 0;
}