#include <bits/stdc++.h>
//For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define all(a) a.begin(),a.end()
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);
V<ll> primes;
void simpleSieve(ll limit, vector<ll> &prime)
{
    // Create a boolean array "mark[0..n-1]" and initialize
    // all entries of it as true. A value in mark[p] will
    // finally be false if 'p' is Not a prime, else true.
    bool mark[limit+1];
    memset(mark, true, sizeof(mark));

    for (ll p=2; p*p<limit; p++)
    {
        // If p is not changed, then it is a prime
        if (mark[p] == true)
        {
            // Update all multiples of p
            for (ll i=p*2; i<limit; i+=p)
                mark[i] = false;
        }
    }

    // Prll all prime numbers and store them in prime
    for (ll p=2; p<limit; p++)
    {
        if (mark[p] == true)
        {
            prime.push_back(p);
            primes.pb(p);
        }
    }
}

// Prlls all prime numbers smaller than 'n'
void segmentedSieve(ll n)
{
    // Compute all primes smaller than or equal
    // to square root of n using simple sieve
    ll limit = floor(sqrt(n))+1;
    vector<ll> prime;
    simpleSieve(limit, prime);

    // Divide the range [0..n-1] in different segments
    // We have chosen segment size as sqrt(n).
    ll low = limit;
    ll high = 2*limit;

    // While all segments of range [0..n-1] are not processed,
    // process one segment at a time
    while (low < n)
    {
        if (high >= n)
           high = n;

        // To mark primes in current range. A value in mark[i]
        // will finally be false if 'i-low' is Not a prime,
        // else true.
        bool mark[limit+1];
        memset(mark, true, sizeof(mark));

        // Use the found primes by simpleSieve() to find
        // primes in current range
        for (ll i = 0; i < prime.size(); i++)
        {
            // Find the minimum number in [low..high] that is
            // a multiple of prime[i] (divisible by prime[i])
            // For example, if low is 31 and prime[i] is 3,
            // we start with 33.
            ll loLim = floor(low/prime[i]) * prime[i];
            if (loLim < low)
                loLim += prime[i];

            /* Mark multiples of prime[i] in [low..high]:
                We are marking j - low for j, i.e. each number
                in range [low, high] is mapped to [0, high-low]
                so if range is [50, 100] marking 50 corresponds
                to marking 0, marking 51 corresponds to 1 and
                so on. In this way we need to allocate space only
                for range */
            for (ll j=loLim; j<high; j+=prime[i])
                mark[j-low] = false;
        }

        // Numbers which are not marked as false are prime
        for (ll i = low; i<high; i++)
            if (mark[i - low] == true)
                {primes.pb(i);}

        // Update low and high for next segment
        low = low + limit;
        high = high + limit;
    }
}

// Driver program to test above function

void solve(ll test_case){
    ll l,r;
    cin >> l >> r;
    ll till_r = upper_bound(all(primes),r) - primes.begin();
    ll till_lo = upper_bound(all(primes),(l-1)) - primes.begin();
    ll ans = till_r-till_lo;
    if(l <= 8 && 8 <= r)ans++;
    if(l <= 4 && 4 <= r)ans++;
    ans+=(max(r-2,0*1LL)/4 - max(l-3,0*1LL)/4);
    printf("Case #%lld: %lld\n",test_case,ans);
}

int main(){
    ll N = 1000000100;
    segmentedSieve(N);
    ll t = 1;
    // printf("HERE\n");
    sort(all(primes));
    // printf("HERE\n");
   cin >> t;
   loop(i,1,t+1){
       solve(i);
   }
   return 0;
}