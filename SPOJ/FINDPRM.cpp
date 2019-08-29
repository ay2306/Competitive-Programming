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
#define maxn 10000100
using namespace std;

int arr[maxn];
int primes[maxn];

// ll binaryL(ll n){
//     ll low = 0;
//     ll high = primes.size()-1;
//     if(n > *primes.rbegin())return high;
//     while(low <= high){
//         ll mid = (low+high)/2;
//         if(primes[mid] == n)return mid;
//         if(mid != primes.size()-1 && primes[mid] < n && primes[mid+1] > n)return mid;
//         if(mid != 0 && primes[mid-1] < n && primes[mid] > n)return mid-1;
//         if(primes[mid] > n)high=mid-1;
//         else low = mid+1;
//     }
// }
// ll binaryR(ll n){
//     ll low = 0;
//     ll high = primes.size()-1;
//     if(n > *primes.rbegin())return high;
//     while(low <= high){
//         ll mid = (low+high)/2;
//         if(primes[mid] == n)return mid;
//         if(mid != primes.size()-1 && primes[mid] < n && primes[mid+1] > n)return mid+1;
//         if(mid != 0 && primes[mid-1] < n && primes[mid] > n)return mid;
//         if(primes[mid] > n)high=mid-1;
//         else low = mid+1;
//     }
// }

void solve(){
    ll n;
    // cin >> n;
    scanf("%lld",&n);
    ll l = n/2 + 1;
    // cout << binaryL(n) << " " << binaryR(l) << endl;
    // cout << binaryL(n)-binaryR(l) + 1 << "\n";
    // cout << primes[n]-primes[l]+1 << "\n";
    printf("%lld\n",primes[n]-primes[n/2]);
}

int main(){
    FAST
    for(ll i = 2; i < maxn; ++i){
        if(arr[i] == 0){
            for(ll j = i; i*j < maxn; ++j){
                arr[i*j]++;
            }
        }
    }
    for(ll i = 2; i < maxn; ++i){
        if(arr[i] == 0){
            primes[i] = primes[i-1]+1;
        }else{
            primes[i] = primes[i-1];
        }
    }
    int t = 1;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}