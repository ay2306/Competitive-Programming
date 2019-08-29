/*
 ____________________________________________________________
|                                                            |
|                   Author: ay2306                           |
|____________________________________________________________|

*/
#include <bits/stdc++.h>
// #define MOD 1000000007
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
ll MOD;
ll gcdExtended(ll a, ll b, ll *x, ll *y){
    if(a == 0){
        *x = 0;
        *y = 1;
        return b;
    }
    ll x1,y1;
    ll gcd = gcdExtended(b%a,a,&x1,&y1);
    *x = (y1 - (b/a)*x1)%MOD;
    *y = (x1)%MOD;

    return gcd;
}

ll modpower(ll a, ll n){
    if(n == 1)return a%MOD;
    if(n == 0)return 1;
    if(n%2 == 0){
        ll b = modpower(a,(n)/2);
        return (b%MOD * b%MOD)%MOD;
    }
    ll b = modpower(a,(n-1)/2);
    b = (b%MOD * b%MOD)%MOD;
    return (a%MOD * b%MOD)%MOD;
}

void solve(){
    ll a,b,n;
    cin >> a >> b >> n;
    // cout << a+b << endl;
    ll diff = a-b;
    ll  x,y;
    MOD = diff;
    if(diff == 0){
        MOD = 1000000007;
    }
    a = (modpower(a,n)+modpower(b,n))%MOD;
    if(diff!=0 && a == 0){
        cout << diff%1000000007 << "\n";
        return ;
    }
    b = diff;
    ll ans =__gcd(a,b);
    cout << ans%1000000007 << endl;
}


int main(){
    int t=1;
    cin >> t;
    while(t--)solve();
    return 0;
}