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

void solve(){
    int n,m;
    cin >> n >> m;
    V<PII> mx(26,mp(-1,-1));
    V<PII> mn(26,mp(inf,inf));
    V<string> arr(n);
    unordered_map<char,int> f;
    int mxi = -1;
    loop(i,0,n)cin >> arr[i];
    loop(i,0,n){
        loop(j,0,m){
            if(arr[i][j] == '.')continue;
            mn[arr[i][j] - 'a'] = min(mn[arr[i][j]-'a'],mp(i,j));
            mx[arr[i][j] - 'a'] = max(mx[arr[i][j]-'a'],mp(i,j));
            f[arr[i][j]]++;
            mxi = max(mxi,arr[i][j]-'a');
        }
    }
    unordered_map<int,P<PII,PII>> ans;
    V<int> unans;
    loop(i,0,mxi+1){
        if(f[i+'a'] == 0){
            unans.pb(i);
            continue;
        }
        auto a = mn[i];
        auto b = mx[i];
        int cnt = 0;
        if(a.F != b.F && a.S != b.S){
            cout << "NO\n";
            return;
        }
        if(a.F == b.F){
            for(int j = a.S; j <= b.S; ++j){
                if(arr[a.F][j] == '.' || arr[a.F][j]-'a' < i){
                    cout << "NO\n";
                    return;
                }else if(arr[a.F][j] == i+'a')cnt++;
            }
        }else{
            for(int j = a.F; j <= b.F; ++j){
                if(arr[j][a.S] == '.' || arr[j][a.S]-'a' < i){
                    cout << "NO\n";
                    return;
                }else if(arr[j][a.S] == i+'a')cnt++;
            }
        }
        if(cnt != f[i+'a']){
            cout << "NO\n";
            return;
        }
        ans[i] = mp(a,b);
    }
    for(auto &i: unans){
        ans[i] = ans[mxi];
    }
    cout << "YES\n" << mxi+1 << "\n";
    loop(i,0,mxi+1){
        printf("%d %d %d %d\n",ans[i].F.F+1,ans[i].F.S+1,ans[i].S.F+1,ans[i].S.S+1);
    }
}

int main(){
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}