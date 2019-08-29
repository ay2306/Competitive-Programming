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
using namespace std;

const ll maxn = 1e5;
const ll mod = 998244353;
int main(){
    int n,m;
    cin >> n >> m;
    string a1,b1;
    cin >> a1 >> b1;
    V<int> a,b;
    loop(i,0,n)a.pb(a1[i]-'0');
    loop(i,0,m)b.pb(b1[i]-'0');
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    while(a.size() < b.size())a.pb(0);
    while(a.size() > b.size())b.pb(0);
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    n = a.size();
    V<ll> arr(n,0);
    ll j = 1;
    for(int i = n-1; i >= 0; --i){
        arr[i] = (a[i]*j)%mod;
        j*=2;
        j%=mod;
    }
    for(int i = n-2; i >= 0; --i){
        arr[i] += arr[i+1];
        arr[i] %= mod;
    }
    ll ans = 0;
    for(int i = 0; i < n; ++i){
        ans+=(b[i]*arr[i]);
        ans%=mod;
    }
    cout << ans;
  return 0;
}
