#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define C continue;
#define R return

#define I insert
#define D double

#define ull unsigned long long int
#define ll long long int
#define ui unsigned int
#define ld long double


#define V vector
#define vi vector<int>
#define vc vector<char>
#define vs vector<string>
#define vb vector<bool>
#define vd vector<D>
#define vll vector<ll>
#define vull vector<ull>
#define vld vector<ld>

#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
#define vvc vector<vector<char>>
#define vvll vector<vector<ll>>
#define vvd vector<vector<D>>
#define vvld vector<vector<ld>>

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define P pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pull pair<ull, ull>
#define pld pair<ld, ld>

#define vpld vector<pld>
#define vpii vector<pii>
#define vpll vector<pll>

#define vvpii vector<vector<pii>>
#define vvpll vector<vector<pll>>

#define PQ(type) priority_queue<type>
#define PQD(type) priority_queue<type, vector<type>, greater<type>>

#define mii map<int, int>
#define mll map<ll, ll>
#define mci map<char, int>
#define msi map<string, int>
#define mis map<int, string>

#define umii unordered_map<int, int>
#define umll unordered_map<ll, ll>
#define umci unordered_map<char, int>
#define umsi unordered_map<string, int>
#define umis unordered_map<int, string>

#define dist(a, b, p, q) sqrt((p - a) * (p - a) + (q - b) * (q - b))

#define pp(n) printf("%.10Lf", n);
#define outspf(n, p) cout << fixed << setprecision(p) << n;
#define line cout << "\n";

#define mod1 1000000007
#define mod2 998244353
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define init(x, val) memset(x, val, sizeof(x))
#define mem(x, val) memset(x, val, sizeof(x))
#define loop(i, a, b) for (ll i = a; i <= b; i++)
#define loopr(i, a, b) for (ll i = a; i >= b; i--)
#define loops(i, a, b, step) for (ll i = a; i < b; i += step)
#define looprs(i, a, b, step) for (ll i = a; i >= b; i -= step)
#define P pair
#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define pf push_front
#define MM multimap
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie();                        \
    cout.tie();
#define read freopen("input.txt", "r", stdin);
#define write freopen("output.txt", "w", stdout);
#define f(i, n) for (ll i = 0; i < n; i++)
#define ff(i, n) for (ll i = 1; i <= n; i++)
#define fr(i, n) for (ll i = n - 1; i >= 0; i--)
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define bgn(x) ((x).begin())
#define sz(x) ((x).size())
#define in1(x, n) f(i, n) cin >> x[i];
#define in2(x, n, m) f(i, n) f(j, m) cin >> x[i][j];
#define out1(x, n)               \
    f(i, n) cout << x[i] << " "; \
    cout << "\n";
#define out2(x, n, m)                   \
    f(i, n)                             \
    {                                   \
        f(j, m) cout << x[i][j] << " "; \
        cout << "\n";                   \
    }
#define fir(x, y) f(ll i = min(x, y); i <= max(x, y); i++)
#define firr(x, y) f(ll i = max(x, y); i <= min(x, y); i++)
#define imin INT_MIN
#define imax INT_MAX
#define lmax LLONG_MAX
#define lmin LLONG_MIN
#define dmin DBL_MIN
#define dmax DBL_MAX

#define mxe(a) *(max_element(a.begin(), a.end()))
#define mne(a) *(min_element(a.begin(), a.end()))
#define prdbl(val, precise) cout << fixed << setprecision(precise) << val << "\n";
#define dbg1(x) cout << " > " << #x << " = " << x << "\n";
#define dbg2(x, y) cout << " < " << #x << " = " << x << ", " << #y << " = " << y << endl;
#define count_1(n) __builtin_popcountll(n)
#define sqr(x) ((x) * (x))
#define inrange(i, a, b) ((i >= min(a, b)) && (i <= max(a, b)))
#define lb lower_bound
#define ub upper_bound
#define rev reverse

void yes()
{
    cout << "YES";
    //cout << "\n";
}
void no()
{
    cout << "NO";
    //cout << "\n";
}
ll pmod(ll a, ll mod = mod1) { return ((a) % mod + mod) % mod; }
ll cel(ll x1, ll y1) //not for negative x1
{
    if ((x1) <= 0)
    {
        return (x1) / (y1);
    }
    return (((x1) / (y1)) + (((x1) % (y1)) != 0));
}
bool isprime(ll n)
{
    for (ll i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return ((a / gcd(a, b)) * b);
}

long long bp(long long a, long long b)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

long long bpm(long long a, long long b, long long m = mod1)
{
    if (a >= m)
        a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res *= a;
        if (res >= m)
            res %= m;
        a *= a;
        if (a >= m)
            a %= m;
        b >>= 1;
    }
    if (res >= m)
        res %= m;
    return res;
}

string vow = "aeiou";

const int dr4[] = {-1, 0, 1, 0};
const int dc4[] = {0, 1, 0, -1};

const int drk[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dck[] = {0, 1, 0, -1, -1, 1, -1, 1};

const int drh[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dch[] = {1, -1, 2, -2, 2, -2, 1, -1};

const ll maxn = 2e5 + 5;
const ll inf = 1e9;
const long double PI = acos(-1);

vll dpb,dpc;
vvll Cost;
int n,k;
void compute(int l=0,int r=n-1,int optl=0,int optr=n-1)
{
    if(r<l) return;
    
    int mid=l+r>>1;
    pll best={lmax>>2,-1LL};
    for(int i=optl;i<=min(optr,mid);i++)
    {
        if(i+1<=min(mid,optr))
        {
            best=min(best,{dpb[i]+Cost[i+1][mid],i});
        }
    }
    dpc[mid]=best.F;
    if(l!=r)
      {
        compute(l,mid-1,optl,best.S);
        compute(mid+1,r,best.S,optr);    
      }
          
    
    
}


void solve(int tc)  
{
cin>>n>>k;

  vvll g(n,vll(n));
  dpb=vll(n,0);
  dpc=vll(n,0);
  for(int i=0;i<n;i++)
  {
      for(int j=0;j<n;j++)
      cin>>g[i][j];
  }

  Cost=vvll(n,vll(n,0));
  vvll pref(n,vll(n,0));
  for(int i=0;i<n;i++)
  {
      pref[i][0]=g[i][0];
      for(int j=1;j<=i;j++)
      pref[i][j]=pref[i][j-1]+g[i][j];
  }
  for(int i=0;i<n;i++)
  {
      for(int j=i+1;j<n;j++)
      {
          Cost[i][j]=Cost[i][j-1]+pref[j][j]-(i>=1?pref[j][i-1]:0);
      }
  }
  

  for(int i=0;i<n;i++)
  {dpb[i]=Cost[0][i];dpc[i]=dpb[i];}
  for(int i=1;i<k;i++)
  {
      compute();
      for(int j=0;j<n;j++)
      dpb[j]=dpc[j];
  }
  cout<<dpc[n-1];
 
}

int main()
{
    //read

    //write
    fast;
    int t = 1;
   // cin >> t;
    loop(i, 1, t)
    {

        solve(i);
        line
    }

    return 0;
}