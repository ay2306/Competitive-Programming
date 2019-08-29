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
    freopen("input.txt","r",stdin);
    int n,m;
    cin >> n >> m;
    V<V<int> > a(n);
    V<V<int> > sum;
    V<int> v(m+1,0);
    sum.pb(v);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            int b;
            cin >> b;
            a[i].pb(b);
        }
        sum.pb(v);
    }
    for(int y = 1; y <= n; ++y){
        for(int x = 1; x <= m; ++x){
            sum[y][x] = max(sum[y-1][x],sum[y][x-1]) + a[x-1][y-1];
            
        }
    }
    cout << sum[n][m] << endl;

    return 0;
}