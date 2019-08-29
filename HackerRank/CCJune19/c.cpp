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
int n;
int main(){
    // FILE_READ_IN
    // FILE_READ_OUT
    cin >> n;
    V<int> arr(n);
    loop(i,0,n)cin >> arr[i];
    int m;
    cin >> m;
    V<int> b(m);
    loop(i,0,m)cin >> b[i];
    V<int> txt;
    V<int> pat;
    loop(i,1,n)txt.pb(arr[i]-arr[i-1]);
    loop(i,1,m)pat.pb(b[i]-b[i-1]);
    if(m == 1){
        cout << n << "\n";
        return 0;
    }
    V<int> lps(m-1,0);
    int j = 0;
    int i = 1;
    while(i < pat.size()){
        if(pat[i] == pat[j]){
            lps[i] = j+1;
            j++;
            i++;
        }else{
            if(j == 0){
                lps[i] = 0;
                i++;
            }else{
                j = lps[j-1];
            }
        }
    }
    int ct = 0;
    i = 0;
    j = 0;
    V<PII> ans;
    while(i < txt.size()){
        if(pat[j] == txt[i]){
            j++;
            i++;
            if(j == pat.size()){
                ans.pb(mp(i-pat.size(),i));
                j = lps[j-1];
            }
        }else{
            if(j != 0)j=lps[j-1];
            else i++;
        }
    }
    PII last_included = mp(-1,-1);
    sort(all(ans));
    for(auto &i: ans){
        if(i.F <= last_included.S)continue;
        last_included = mp(i.F,i.S);
        ct++;
    }
    cout << ct << "\n";
   return 0;
}