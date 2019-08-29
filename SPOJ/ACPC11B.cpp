/*
 ____________________________________________________________
|                                                            |
|                   Author: ay2306                           |
|____________________________________________________________|

*/
#include <bits/stdc++.h>
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
#define FILE_READ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define MAXN 25
using namespace std;

void solve(){
    int n,m;
    cin >> n;
    V<ll> a(n+1);
    for(int i = 0; i < n; ++i)cin >> a[i];
    a[n] = LONG_LONG_MAX/3;
    cin >> m;
    V<ll> b(m+1);
    for(int i = 0; i < m; ++i)cin >> b[i];
    b[m] = LONG_LONG_MAX/3;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int i = 0;
    int j = 0;
    // for(int i = 0; i < n; ++i)cout << a[i] << " ";
    // cout << endl;
    // for(int i = 0; i < m; ++i)cout << b[i] << " ";
    // cout << endl;
    ll ans = LONG_LONG_MAX;
    while(i < n || j < m){
        // cout << a[i] << " " << b[j] << endl;
        ans = min(abs(a[i]-b[j]),ans);
        if(a[i] > b[j])j++;
        else if(a[i] < b[j])i++;
        else{
            i++;
            j++;
        }
    }
    cout << ans << endl;
}

int main(){
    // FILE_READ
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}