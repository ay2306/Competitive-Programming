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
// #define MAXN 5001000
using namespace std;
const int MAXN = 5e5 + 500;
vector<int> primes;
vector<ll> prefixSumArray;
int getRank(int n, int k){
    if(n == 1 || n == 2)return 0;
    if(n >= primes[primes.size()-1])return primes.size()-1;
    int low = 0;
    int high = primes.size()-1;
    while(low <= high){
        int mid = (low + high)/2;
        if(primes[mid] == n)return mid;
        if(mid != 0 && primes[mid] > n && primes[mid-1] < n){
            if(k == 0)return mid-1;
            else return mid;
        }
        if(mid != primes.size()-1 && primes[mid] < n && primes[mid+1] > n){
            if(k == 0)return mid;
            else return mid+1;
        }
        if(primes[mid] > n)high = mid-1;
        else low = mid+1;
    }
}

void solve(){
    int a,b;
    cin >> a >> b;
    a = getRank(a,1);
    b = getRank(b,0);
    if(a == 0)cout << prefixSumArray[b];
    else cout << prefixSumArray[b]-prefixSumArray[a-1];
    cout << "\n";
}

int main(){
    int arr[MAXN+10];
    cout << "hello\n";
    // for(int i = 2; i < MAXN; ++i)if(arr[i] == 0)for(int j = 2; i * j < MAXN; ++j)arr[i*j]++;
    // for(int i = 2; i < MAXN; ++i)if(arr[i] == 0)primes.pb(i);
    // prefixSumArray.pb(2);
    // for(int i = 1; i < primes.size(); ++i){
    //     prefixSumArray.pb(prefixSumArray[i-1]+primes[i]);
    // }
    // int t = 1;
    // cin >> t;
    // while(t--)solve();
    return 0;
}