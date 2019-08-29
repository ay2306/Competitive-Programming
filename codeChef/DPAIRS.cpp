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
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define MAXN 25
using namespace std;

void solve(){
    int n,m;
    cin >> n >> m;
    V<ll> a(n);
    V<ll> b(m);
    loop(i,0,n) cin >> a[i];
    loop(i,0,m) cin >> b[i];
    unordered_map<ll,int> o;
    V<PII> ans;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(int i = 0; i < m; ++i){
        ans.pb(mp(0,i));
        o[a[0] + b[i]]++;
    }
    for(int j = m-1; j >= 0; --j){
        if(ans.size() == n+m-1)break;
        for(int i = 0; i < n; ++i){
            if(ans.size() == n+m-1)break;
            ll s = a[i] + b[j];
            if(o[s] == 0){
                ans.pb(mp(i,j));
                o[s]++;
            }
        }
    }
    for(auto i: ans){
        cout << i.F << " " << i.S << "\n";
    }
}

int main(){
    int t = 1;
//    cin >> t;
    while(t--)solve();
    return 0;
}
