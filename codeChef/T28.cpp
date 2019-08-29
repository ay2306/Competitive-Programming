#include <bits/stdc++.h>
#define MOD 1000000009
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
#define FILE_READ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
using namespace std;

ll power(ll x, ll y, ll m);
 
void modInverse(ll a, ll m)
{
    cout << power(a, m-2, m) << endl;
}
 
ll power(ll x, ll y, ll m)
{
    if (y == 0)
        return 1;
    ll p = power(x, y/2, m) % m;
    p = (p * p) % m;
 
    return (y%2 == 0)? p : (x * p) % m;
}
 


int main(){
    int n,q;
    cin >> n >> q;
    M<ll,ll> m;
    for(int i = 0; i < n; ++i){
        ll a,b,c,d;
        cin >> a >> b;
        c = a;
        d = b;
        a = (a%MOD * b%MOD)%MOD;
        a = (a%MOD * 4%MOD)%MOD;
        a = (a%MOD + (2*max(c,d))%MOD)%MOD;
        ll D = sqrt((1+(4*a)%MOD)%MOD);
        ll K1 = (D-1)/2;
        ll K2 = (-1*(D+1))/2;
        m[K1]++;
        m[K2]++;
    } 
    while(q--){
        ll a;
        cin >> a;
        if(m[a] == 0){
            cout << "-1\n";
        }else{
            // cout << m[a] << endl;
            cout << power(m[a],MOD-2,MOD) << endl;
            // modInverse(m[a],MOD);
        }
    }
    return 0;
}