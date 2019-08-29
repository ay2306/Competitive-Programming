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

int n,m;
V<ll> a;
V<ll> b;

ll f(ll c){
    ll ans = 0;
    for(auto i: a){
        if(i < c)ans+=(c-i);
    }
    for(auto i: b){
        if(i > c)ans+=(i-c);
    }
    return ans;
}

int main(){
    cin >> n >> m;
    a = V<ll> (n);
    b = V<ll> (m);
    loop(i,0,n)cin >> a[i];
    loop(i,0,m)cin >> b[i];
    ll low = 0;
    ll high = 2e9;
    ll ans = LLONG_MAX;
    while(high - low >= 3){
        ll m1 = low + (high-low)/3;
        ll m2 = high - (high-low)/3;
        ll s1 = f(m1);
        ll s2 = f(m2);
        if(s1 < s2){
            high = m2;
            ans = min(ans,s1);
        }else{
            low = m1;
            ans = min(ans,s2);
        }
    }
    ans = min(ans,f(low+1));
    ans = min(ans,f(low+2));
    cout << ans;
    return 0;
}