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
#define FILE_READ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define MAXN 25
using namespace std;
const ll maxn = 2e7;
int prime[maxn],countdiv[maxn];

void sieve(){
    for(ll i = 2; i * i < maxn; ++i){
        if(!prime[i]){
            for(ll j = i*i; j < maxn; j+=i){
                prime[j] = i;
            }
        }
    }
    for(ll i = 2; i < maxn; ++i){
        if(!prime[i])prime[i]=i;
    }
}

int largestGCDSequence(ll arr[], int n){
    int ans = 0;
    for(int i = 0; i < n; ++i){
        ll element = arr[i];
        while(element > 1){
            ll div = prime[element];
            ++countdiv[div];
            ans = max(ans,countdiv[div]);
            while(element%div == 0){
                element/=div;
            }
        }
    }
    return ans;
}
int main(){
    FAST
    sieve();
    int n;
    cin >> n;
    ll m_gcd = 0;
    ll mx = 0;
    unordered_map<ll,int> m;
    ll *arr = new ll[n];
    loop(i,0,n){
        cin >> arr[i];
        m[arr[i]]++;
        m_gcd = __gcd(arr[i],m_gcd);
    }
    loop(i,0,n){
       arr[i]/=m_gcd;
    }
    // cout << k << endl;
    // cout << mx   << endl;
    int ans = largestGCDSequence(arr,n);
    if(ans != 0)cout << n-ans;
    else cout << -1;
    return 0;
}