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
#define S set
#define MS multiset
#define M map
#define mp make_pair
#define pb push_back
#define MM multimap
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();

using namespace std;

int main(){
    FAST
    int n,m;
    cin >> n >> m;
    ull *v = new ull[n];
    V<V<ull> > e(n);
    for(int i = 0; i < n; ++i)cin >> v[i];
    for(int i = 0; i < m; ++i){
        ull a,b;
        cin >> a >> b;
        a--;
        b--;
        e[a].pb(b);
        e[b].pb(a);
    }
    ull ans = 0;
    for(int i = 0; i < n; ++i){
        ull mx = 0;
        for(int j = 1; j < n; ++j){
            if(v[j] > v[mx])mx=j;
        }
        v[mx]=0;
        for(int j = 0; j < e[mx].size(); ++j){
            ans+=v[e[mx][j]];
        }
    }
    cout << ans;
    return 0;
}