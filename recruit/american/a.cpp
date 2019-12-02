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
#define ull unsigned long l<ong int
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

void solve(){
    int n;
    cin >> n;
    V<int> arr(n);
    multiset<int> s;
    unordered_map<int,int> m;
    int ans = inf;
    loop(i,0,n){cin >> arr[i];s.insert(arr[i]);m[arr[i]]++; if(m[arr[i]] > 1)ans = 0;}
    loop(i,0,n){
        if(ans == 0)break;
        //check for 2*arr[i];
        int val = arr[i];
        auto it = s.find(val);
        if(it == s.begin()){
                ans = min(ans,abs(*(next(it)) - val));
        }else if(it == s.end()){
            ans = min(ans,abs(val - *prev(it)));
        }else{
            ans = min(ans,abs(*(next(it)) - val));
            ans = min(ans,abs(val - *prev(it)));
        }
        s.erase(val);
        if(val%2 == 1){
            val = 2*arr[i];
            s.insert(val);
            if(m[val] > 0){
                ans = 0;
            }else{
                it = s.find(val);
                if(it == s.begin()){
                    ans = min(ans,abs(*(next(it)) - val));
                }else if(it == s.end()){
                    ans = min(ans,abs(val - *prev(it)));
                }else{
                    ans = min(ans,abs(*(next(it)) - val));
                    ans = min(ans,abs(val - *prev(it)));
                }
            }
            s.erase(val);
        }else{
            val = arr[i]/2;
            do{
                s.insert(val);
                if(m[val] > 0){
                ans = 0;
                }else{
                    it = s.find(val);
                    if(it == s.begin()){
                        ans = min(ans,abs(*(next(it)) - val));
                    }else if(it == s.end()){
                        ans = min(ans,abs(val - *prev(it)));
                    }else{
                        ans = min(ans,abs(*(next(it)) - val));
                        ans = min(ans,abs(val - *prev(it)));
                    }
                }
                s.erase(val);
                if(val%2 == 1)break;
                val/=2;
            }while(val%2 == 0 && ans > 0);
        }
        s.insert(arr[i]);
    }
    cout << ans << "\n";
}

int main(){
    FAST
   int t;
   cin >> t;
   while(t--){
       solve();
   }
   return 0;
}