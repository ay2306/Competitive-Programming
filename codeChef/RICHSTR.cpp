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
// using namespace __gnu_pbds;
// template <typename T>
// using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);

void solve(){
    string a;
    int l,q;
    cin >> l >> q;
    cin >> a;
    V<int> two(a.size(),0);
    V<int> three(a.size(),0);
    for(int i = 0; i < a.size(); ++i){
        if(i > 0){
            two[i] = two[i-1]+(a[i] == a[i-1]);
        }
        if(i > 1){
            three[i] = three[i-1]+(a[i] == a[i-2]);
        }
    }
    // for(int i = 0; i < a.size(); ++i){
    //     cout << two[i] << "";
    // }
    // cout << endl;
    // for(int i = 0; i < a.size(); ++i){
    //     cout << three[i] << "";
    // }
    // cout << endl;
    while(q--){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        if(b-a+1 < 3){
            cout << "NO\n";
        }else{
            int res = two[b]-two[a] + three[b] - three[a+1];
            // cout << res << "\n";
            if(res > 0)cout << "YES\n";
            else cout << "NO\n";
        }
    }
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