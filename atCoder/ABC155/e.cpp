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
//using namespace __gnu_pbds;
//template <typename T>
//using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll N = 1e5+1010;
const ll inf = 1e9;
const double pi = acos(-1);

int main(){
    string s;
    cin >> s;
    s = "0000"+s;
    int n = s.size();
    V<ll> a(n),b(n,0);
    V<int> st(n,0);
    loop(i,0,n)a[i]=s[i]-'0';
    int j = n-1;
    int dp[N][2];
    int lst;
    while(s[j] == '0')j--;
    lst = j;
    dp[j][0] = 9 - (s[j]-'0');
    dp[j][0] = (s[j]-'0');
    j--;
    while(j >= 0){
        if(s[j] == '0')
    }
    loop(i,1,n)a[i]+=a[i-1];
    ll ans = LLONG_MAX;
    loop(i,0,n){
        ll res = 0;
        if(i < n-1)res = b[i+1];
        ans = min(ans,a[i]+(i!=n-1)+res);
    }
    cout << ans;
return 0;
}
