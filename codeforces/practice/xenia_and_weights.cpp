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

V<int> ans;
set<int> s;
int n;
string a;
bool tryThisMethod(int var){
    ans[0] = var;
    int c1 = ans[0];
    int c2 = 0;
    loop(i,1,n){
        if(i & 1){
            int req = c1 - c2 + 1;
            auto it = s.lower_bound(req);
            if(it != s.end() && *it == ans[i-1])it++;
            if(it == s.end()){
                // cout << "CASE: " << var << "  method = " <<  i << "\n";
                // loop(j,0,i){
                //     cout << ans[j] << " ";
                // }
                // cout << "\n";
                return false;
            }else{
                ans[i] = *it;
                c2+=*it;
            }
        }else{
            int req = c2 - c1 + 1;
            auto it = s.lower_bound(req);
            if(ans[i-1] != var && c1+var > c2){
                ans[i] = var;
                c1+=var;
                continue;
            }
            if(it != s.end() && *it == ans[i-1])it++;
            if(it == s.end()){
                // cout << "CASE: " << var << "  method = " <<  i << "\n";
                // loop(j,0,i){
                //     cout << ans[j] << " ";
                // }
                // cout << "\n";
                return false;
            }else{
                ans[i] = *it;
                c1+=*it;
            }
        }
    }
    return true;
}

int main(){
    FAST
    cin >> a >> n;
    loop(i,0,10){
        if(a[i] == '1')s.insert(i+1);
    }
    if(s.size() == 0){
        cout << "NO\n";
        return 0;
    }
    ans = V<int> (n);
    for(int i: s){
        if(tryThisMethod(i)){
            cout << "YES\n";
            loop(i,0,n)cout << ans[i] << " ";
            return 0;
        }
    }
    cout << "NO\n";
   return 0;
}