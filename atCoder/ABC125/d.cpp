// /*
//  ____________________________________________________________
// |                                                            |
// |                   Author: ay2306                           |
// |____________________________________________________________|

// */
// #include <bits/stdc++.h>
// //For ordered_set
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #define MOD 1000000007
// #define test int t; cin>>t; while(t--)
// #define init(arr,val) memset(arr,val,sizeof(arr))
// #define loop(i,a,b) for(int i=a;i<b;i++)
// #define loopr(i,a,b) for(int i=a;i>=b;i--)
// #define loops(i,a,b,step) for(int i=a;i<b;i+=step)
// #define looprs(i,a,b,step) for(int i=a;i>=b;i-=step)
// #define ull unsigned long long int
// #define ll long long int
// #define P pair
// #define PLL pair<long long, long long>
// #define PII pair<int, int>
// #define PUU pair<unsigned long long int, unsigned long long int>
// #define L list
// #define V vector
// #define D deque
// #define ST set
// #define MS multiset
// #define M map
// #define UM unordered_map
// #define mp make_pair
// #define pb push_back
// #define pf push_front
// #define MM multimap
// #define F first
// #define S second
// #define IT iterator
// #define RIT reverse_iterator
// #define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
// #define FILE_READ_IN freopen("input.txt","r",stdin);
// #define FILE_READ_OUT freopen("output.txt","w",stdout);
// #define all(a) a.begin(),a.end()
// #define ord_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
// using namespace std;
// // For ordered_set
// using namespace __gnu_pbds;
// const ll maxn = 1e5;
// const ll inf = LLONG_MAX/2;
// int main(){
//     int n;
//     cin >> n;
//     V<ll> arr(n);
//     loop(i,0,n)cin >> arr[i];
//     int neg = 0;
//     loop(i,0,n){
//         if(arr[i] < 0)neg++;
//         arr[i] = abs(arr[i]);
//     }
//     if(neg%2 == 1)cout << accumulate(all(arr),0*1LL) - 2*(*min_element(all(arr)));
//     if(neg%2 == 0)cout << accumulate(all(arr),0*1LL);
//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("O2")
#define pb push_back
#define debug(x)  cout<<'>'<<#x<<" : "<<x<<endl;
#define mp make_pair
#define ff first
#define ss second
#define allunique(v) 	v.erase(unique(v.begin(),v.end()),v.end());
#define MOD 1000000007
#define MOD9 1000000009
#define th(n) cout<<n<<endl
#define gc getchar_unlocked
#define ms(s, n) memset(s, n, sizeof(s))
#define prec(n) fixed<<setprecision(n)
#define eps 0.000001
#define bolt ios::sync_with_stdio(0)
#define forr(i,n) for(ll i=0;i<n;i++)
#define eof (scanf("%d" ,&n))!=EOF
#define PI acos(-1.0)
#define inf INT_MAX
#define all(v) v.begin(),v.end()
#define endl "\n"
typedef long long ll;
typedef double db;
typedef long long ll;
typedef pair< ll, ll > pll;
typedef vector< ll > vll;
typedef map< ll, ll > mll;
typedef set< ll > sll;
#define n_l '\n'
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]: "; cout << to_string(__VA_ARGS__) << endl
template <typename T, size_t N> int SIZE(const T (&t)[N]){ return N; } template<typename T> int SIZE(const T &t){ return t.size(); } string to_string(string s, int x1=0, int x2=1e9){ return '"' + ((x1 < s.size()) ? s.substr(x1, x2-x1+1) : "") + '"'; } string to_string(const char* s) { return to_string((string) s); } string to_string(bool b) { return (b ? "true" : "false"); } string to_string(char c){ return string({c}); } template<size_t N> string to_string(bitset<N> &b, int x1=0, int x2=1e9){ string t = ""; for(int __iii__ = min(x1,SIZE(b)),  __jjj__ = min(x2, SIZE(b)-1); __iii__ <= __jjj__; ++__iii__){ t += b[__iii__] + '0'; } return '"' + t + '"'; } template <typename A, typename... C> string to_string(A (&v), int x1=0, int x2=1e9, C... coords); int l_v_l_v_l = 0, t_a_b_s = 0; template <typename A, typename B> string to_string(pair<A, B> &p) { l_v_l_v_l++; string res = "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; l_v_l_v_l--; return res; } template <typename A, typename... C> string to_string(A (&v), int x1, int x2, C... coords) { int rnk = rank<A>::value; string tab(t_a_b_s, ' '); string res = ""; bool first = true; if(l_v_l_v_l == 0) res += n_l; res += tab + "["; x1 = min(x1, SIZE(v)), x2 = min(x2, SIZE(v)); auto l = begin(v); advance(l, x1); auto r = l; advance(r, (x2-x1) + (x2 < SIZE(v))); for (auto e = l; e != r; e = next(e)) { if (!first) { res += ", "; } first = false; l_v_l_v_l++; if(e != l){ if(rnk > 1) { res += n_l; t_a_b_s = l_v_l_v_l; }; } else{ t_a_b_s = 0; } res += to_string(*e, coords...); l_v_l_v_l--; } res += "]"; if(l_v_l_v_l == 0) res += n_l; return res; } void dbgs(){;} template<typename Heads, typename... Tails> void dbgs(Heads H, Tails... T){ cout << to_string(H) << " | "; dbgs(T...); }
#define dbgm(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgs(__VA_ARGS__); cout << endl;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//printf("%I64d", n)
	int t;
	cin>>t;
	while(t--)
	{
		ll n,k,b,cnt,curr;
		cin>>n>>k>>b;
		vector<ll> s;
		forr(i,n){
			cin>>curr;
			s.push_back(curr);
		}
        sort(all(s));
		curr = *s.begin();
		cnt = 1;
		auto it  = lower_bound(s.begin(),s.end(),(curr*k + b));
		while(it != s.end())
		{
			cnt++;
			curr = *it;
			it = lower_bound(it,s.end(),curr*k + b);
		}
		th(cnt);
	}
}
