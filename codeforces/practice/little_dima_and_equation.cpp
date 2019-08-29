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

ll countDigitSum(ll a){
    ll d=0;
    while(a){
        d+=(a%10);
        a/=10;
    }
    return d;
}

int main(){
    ll a,b,c;
    V<ll> v;
    cin >> a >> b >> c;
    ll x;
    for(ll i = 1; i <= 81; ++i){
        ll t = 1;
        for(int j = 0; j < a; ++j){
            t*=i;
        }  
        t=b*t;
        t+=c;
        if(countDigitSum(t) == i && t < 1000000000)v.pb(t);
    }
    cout << v.size() << endl;
    for(int i = 0; i < v.size(); ++i){
        cout << v[i] << " ";
    }

    return 0;
}