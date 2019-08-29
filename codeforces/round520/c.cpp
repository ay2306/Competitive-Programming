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

ll power(ll n){
    if(n == 0)return 1;
    if(n == 1)return 2;
    ll k = power(n/2);
    k = (k%MOD * k%MOD)%MOD;
    if(n%2)k = (k%MOD * 2%MOD)%MOD;
    return k;
}

int main(){
    FAST
    int n,q;
    cin >> n >> q;
    string a;
    cin >> a;
    V<int> one(n+1,0);
    V<int> zero(n+1,0);
    for(int i = 0; i < n; ++i){
        one[i+1] = one[i] + ((a[i]=='1')?1:0);
        zero[i+1] = zero[i] + ((a[i]=='0')?1:0);
    }
    while(q--){
        int l,r;
        cin >> l >> r;
        ll o = one[r]-one[l-1];
        ll z = zero[r]-zero[l-1];
        // cout << z << " " << o << "\n";
        ll k = (power(o)-1+MOD)%MOD;
        ll p = (power(z)-1+MOD)%MOD;
        ll ans = (k%MOD + (k%MOD*p%MOD)%MOD)%MOD;
        cout << ans << "\n";
    }
    return 0;
}