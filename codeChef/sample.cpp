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

ll power(ll a, ll n){
    if(n == 0)return 1;
    if(n == 1)return a%MOD;
    ll p = power(a,n/2);
    p*=p;
    p%=MOD;
    if(n%2)p*=a;
    p%=MOD;
    return p;
}

void solve(){
    int n,q;
    cin >> n >> q;
    vector<ll> fact(n+10,1);
    vector<ll> factInv(n+10,1);
    loop(i,2,n+1){
        fact[i] = (fact[i-1]*i)%MOD;
        factInv[i] = (factInv[i-1]*power(i,MOD-2))%MOD;
    }
    vector<unordered_map<int,int>> pref;
    vector<int> arr(n);
    loop(i,0,n){
        cin >> arr[i];
    }
    pref[0][arr[0]]++;
    loop(i,1,n){
        pref[i] = pref[i-1];
        pref[i][arr[i]]++;
    }
    ll ans = 0;
    while(q--){
        ll l1,l2,r1,r2;
        ll l = ((ans%n * l1%n) + l2)%n;
        ll r = ((ans%n * r1%n) + r2)%n;
        if(l > r)swap(l,r);
        ans = fact[l-r+1];
        if(l == 0){
            for(auto &i: pref[r]){
                ans = (ans*factInv[i.S])%MOD;
            }
        }else{
            for(auto &i: pref[r]){
                ans = (ans*factInv[i.S - pref[l-1][i.F]])%MOD;
            }
        }
        cout << ans << "\n";
    }
}

int main(){
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}