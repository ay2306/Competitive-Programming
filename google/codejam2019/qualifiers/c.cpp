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
V<int> primes;

void solve(){
    int n,l;
    cin >> n >> l;
    V<ll> arr(l+1);
    loop(i,0,l)cin >> arr[i];
    ll k = arr[0];
    ll p = arr[1];
    PLL f1,f2;
    for(auto i: primes){
        if(k % i == 0){
            f1 = mp(i,k/i);
            break;
        }
    }
    for(auto i: primes){
        if(p % i == 0){
            f2 = mp(i,p/i);
            break;
        }
    }
    ll b = 0;
    if(f1.F == f2.)
}

int main(){
    int arr[maxn] = {0};
    for(int i = 2; i < maxn; ++i){
        if(arr[i] == 0){
            for(int j = 2; i*j < maxn; ++j)arr[i*j]++;
        }
    }
    for(int i = 2; i < maxn; ++i){
        if(arr[i] == 0)primes.pb(i);
    }
    int t;
    cin >> t;
    loop(i,0,t){
        printf("Case #%d: ",i+1);
        solve();
    }
    return 0;
}