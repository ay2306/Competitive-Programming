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

void solve(){
    int n,k;
    ll g;
    cin >> n >> k >> g;
    g--;
    g = ((g%n)*(k%n))%n;
    V<P<int,string> > v;
    V<P<int,string> > ans;
    for(int i = 0; i < n; ++i){
        string a;
        cin >> a;
        v.pb(mp(i,a));
    }
    for(int i = 0; i < k; ++i)ans.pb(v[(i+g)%n]);
    sort(ans.begin(),ans.end());
    for(int i = 0; i < k; ++i){
        cout << ans[i].second << " ";
    }
    cout << endl;
}

int main(){
    freopen("tourist.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin >> t;
    for(int i = 1; i <= t; ++i){
        cout << "Case #" << i << ": ";
        solve();
    }   
    return 0;
}