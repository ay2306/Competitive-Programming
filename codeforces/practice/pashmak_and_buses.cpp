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
bool over = false;
ll power(ll a, ll n){
    if(n == 0)return 1;
    if(n == 1)return a;
    ll p = power(a,n/2);
    p*=p;
    if(p > MOD){
        over = true;
        p%=MOD;
    }
    if(n%2){
        p*=a;
        if(p > MOD){
            over = true;
            p%=MOD;
        }
    }
    return p;
}

ll n,d,k;

int main(){
    FAST
    cin >> n >> k >> d;
    ll pos = power(k,d);
    if(n > pos && !over){
        cout << "-1\n";
        return 0;
    }
    V<ll> arr(n+1);
    loop(i,1,n+1)arr[i] = i;
    for(int i = 0; i < d; ++i){
        for(int j = 1; j <= n; ++j){
            cout << arr[j]%k + 1 << " ";
            arr[j]/=k;
        }
        cout << endl;
    }
  return 0;
}
