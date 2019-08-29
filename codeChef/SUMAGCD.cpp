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
#define all(container) container.begin(),container.end()
#define MAXN 25
using namespace std;

void solve(){
    int n;
    cin >> n;
    V<ll> arr(n);
    loop(i,0,n)cin >> arr[i];
    sort(all(arr),greater<ll>());
    V<ll> factors;
    for(int i = 1; i*i <= arr[0]; ++i){
        if(arr[0]%i == 0){
            factors.pb(i);
            if(i*i != arr[0])factors.pb(arr[0]/i);
        }
    }
    ll ans = 0;
    for(auto g: factors){
        ll g1 = 0;
        for(int i = 0; i < n; ++i){
            if(arr[i]%g != 0){
                g1 = __gcd(g1,arr[i]);
            }
        }
        if(g1 == 0){
            ans = max(ans,g+arr[0]);
        }else{
            ans = max(ans,g+g1);
        }
    }
    cout << ans << "\n";
}

int main(){
    FAST
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}