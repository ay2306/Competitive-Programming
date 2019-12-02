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
PII current = {0,0};
int b = 0;
V<string> ans;
bool comp(PII a, PII b){
    return (abs(a.F) < abs(b.F) || (abs(a.F)==abs(b.F) && abs(a.S) < abs(b.S)));
}
void go(PII a){
    if(a.F != 0){
        if(a.F > 0)ans.pb("1 " + to_string(abs(a.F)) + " R");
        if(a.F < 0)ans.pb("1 " + to_string(abs(a.F)) + " L");
    }
    if(a.S != 0){
        if(a.S > 0)ans.pb("1 " + to_string(abs(a.S)) + " U");
        if(a.S < 0)ans.pb("1 " + to_string(abs(a.S)) + " D");
    }
    current = a;
}
void ret(){
    if(current.F != 0){
        if(-current.F > 0)ans.pb("1 " + to_string(abs(current.F)) + " R");
        if(-current.F < 0)ans.pb("1 " + to_string(abs(current.F)) + " L");
    }
    if(current.S != 0){
        if(-current.S > 0)ans.pb("1 " + to_string(abs(current.S)) + " U");
        if(-current.S < 0)ans.pb("1 " + to_string(abs(current.S)) + " D");
    }
    current = {0,0};
}
int main(){
    FAST
    int n;
    cin >> n;
    V<PII> arr(n);
    loop(i,0,n)cin >> arr[i].F >> arr[i].S;
    sort(all(arr),comp);
    loop(i,0,n){
        PII &a = arr[i];
        go(a);
        ans.pb("2");
        ret();
        ans.pb("3");
    }
    cout << ans.size() << "\n";
    loop(i,0,ans.size())cout << ans[i] << "\n";
   return 0;
}