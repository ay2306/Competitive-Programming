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
#define FILE_READ_OUT freopen("my.txt","w",stdout);
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
    int n;
    unordered_map<int,int> m;
    cin >> n;
    V<int> arr(n);
    loop(i,0,n){cin >> arr[i];m[arr[i]]++;}
    int mn = n+1;
    for(auto i: m)mn=min(mn,i.S);
    set<int> factors;
    for(int i = 1; i*i <= mn; ++i){
        if(mn % i == 0){
            factors.insert(i);
            if(i*i != mn)factors.insert(mn/i);
        }
    }
    mn++;
    for(int i = 1; i*i <= mn; ++i){
        if(mn % i == 0){
            factors.insert(i);
            if(i*i != mn)factors.insert(mn/i);
        }
    }
    for(auto itr = factors.rbegin(); itr != factors.rend(); ++itr){
        int val = *itr;
        bool pos = true;
        int ans = 0;
        for(auto i: m){
            int k = i.S;
            if(i.S % val == 0){
                ans+=(i.S/val);
            }else if(i.S %val == (val-1)){
                ans+=((i.S+1)/val);
            }else{
                pos = false;
                break;
            }
        }
        if(pos){
            cout << ans << "\n";
            return;
        }
    }
}

int main(){
    FILE_READ_IN
    FILE_READ_OUT
    FAST
   int t = 0;
   cin >> t;
   while(t--){
       solve();
   }
   return 0;
}