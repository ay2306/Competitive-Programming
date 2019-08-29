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

set<ll> oo;

void solve(){
    int k;
    cin >> k;
    V<ll> o,e;
    loop(i,0,k){
        ll a;
        cin >> a;
        if(a%2)o.pb(a);
        else e.pb(a);
    }
    if(k%2 == 0){
        cout << "0" << "\n";
    }
    else if(e.size() > 0){
        cout << "1\n";
    }else{
        ll mn = -1;
        ll j = 1;
        for(auto i: o){
            ll p = 0;
            ll n = i;
            while(n){
                if(n%2 == 0){
                    if(mn == -1)mn = (j << p);
                    else mn = min(mn,(j << p));
                    break;
                }
                p++;
                n/=2;
            }
        }
        cout << mn << "\n";
    }
    return; 
}

int main(){
    FAST
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}