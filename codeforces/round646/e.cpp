//https://codeforces.com/contest/1363/problem/E
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
const long long mod = 1e9+7;
// const long long mod = 998244353;
const long long int special_prime = 982451653;
using namespace std;
// DEBUGGER
// *
vector<string> vec_splitter(string s) {
	s += ',';
	vector<string> res;
	while(!s.empty()) {
		res.push_back(s.substr(0, s.find(',')));
		s = s.substr(s.find(',') + 1);
	}
	return res;
}
void debug_out(
vector<string> __attribute__ ((unused)) args,
__attribute__ ((unused)) int idx, 
__attribute__ ((unused)) int LINE_NUM) { cerr << endl; } 
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
	if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
	stringstream ss; ss << H;
	cerr << args[idx] << " = " << ss.str();
	debug_out(args, idx + 1, LINE_NUM, T...);
}
#ifdef LOCAL
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define debug(...) 42
#endif
// *
// DEBUGGER

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
#define mp make_pair
#define pb emplace_back
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
#define ld long double
#define sz(x) (int)((x).size())
#define square(x) ((x)*(x))
#define cube(x) ((x)*(x)*(x))
#define distance(a,b,c,d) ((a-c)*1LL*(a-c)+(b-d)*1LL*(b-d))
#define range(i,x,y) ((x <= i) && (i <= y))
#define SUM(a) accumulate(a.begin(),a.end(),0LL)
#define lb lower_bound
#define ub upper_bound
#define REV reverse
#define seive(N) int pr[N]; void preSieve(){for(int i = 2; i < N; ++i){if(!pr[i])for(int j = i; j < N; j+=i)pr[j]=i;}}
#define modInv(N) ll inv[N]; void preModInv(){inv[0]=0;inv[1]=1;for(int i = 2; i < N; ++i)inv[i] = mod-mod/i*inv[mod%i]%mod;}
#define fact(N) ll fact[N]; void preFact(){fact[0] = 1,fact[1] = 1; for(int i = 2; i < N; ++i)fact[i]=fact[i-1]*i%mod;}
#define inFact(N) ll ifact[N]; void preiFact(){ifact[1] = 1; for(int i = 2; i < N; ++i)ifact[i]=ifact[i-1]*inv[i]%mod;}

// Randomization



// pair operation
template<class T, class U>istream& operator>>(istream& in, pair<T,U> &rhs){in >> rhs.first;in >> rhs.second;return in;}
template<class T, class U>ostream& operator<<(ostream& out,const pair<T,U> &rhs){out << rhs.first;out << " ";out << rhs.second;return out;}
template<class T, class U>pair<T,U> operator+(pair<T,U> &a, pair<T,U> &b){return pair<T,U>(a.first+b.first,a.second+b.second);}
template<class T, class U>pair<T,U> operator-(pair<T,U> &a, pair<T,U> &b){return pair<T,U>(a.first-b.first,a.second-b.second);}
// Linear STL
// VECTOR
template<class T>istream& operator>>(istream& in, vector<T> &a){for(auto &i: a)cin >> i;return in;}
template<class T>ostream& operator<<(ostream& out, const vector<T> &a){for(auto &i: a)cout << i << " ";return out;}
// SET
template<class T>ostream& operator<<(ostream& out, const set<T> &a){for(auto &i: a)cout << i << " ";return out;}
template<class T>ostream& operator<<(ostream& out, const unordered_set<T> &a){for(auto &i: a)cout << i << " ";return out;}
template<class T>ostream& operator<<(ostream& out, const multiset<T> &a){for(auto &i: a)cout << i << " ";return out;}
// MAP
template<class T,class U>ostream& operator<<(ostream& out, const map<T,U> &a){for(auto &i: a)cout << "(" << i.first << ", " << i.second << ")\n";return out;}
template<class T,class U>ostream& operator<<(ostream& out, const unordered_map<T,U> &a){for(auto &i: a)cout << "(" << i.first << ", " << i.second << ")\n";return out;}

using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

const long long N = 2e5 + 100;
const long long inf = 1e9;
const long double pi = acos(-1);
int n;
V<int> g[N];
ll c[N],dp[N];
int val[N],miss[N][2],avail[N][2];
int b[N],to[N];
int dem[2],merpe[2];
void dfs1(int s = 1, int p = -1){
	if(p!=-1)c[s] = min(c[s],c[p]);
	for(int i : g[s])if(i != p)dfs1(i,s);
}

void dfs(int s = 1, int p = -1){
	for(int i: g[s]){
		if(i == p)continue;
		dfs(i,s);
		miss[s][0] += miss[i][0];
		miss[s][1] += miss[i][1];
		avail[s][0] += avail[i][0];
		avail[s][1] += avail[i][1];
	}
	dp[s] = LLONG_MAX;
	if(b[s] != to[s]){
		miss[s][b[s]]++;
		avail[s][b[s]]++;
	}
	// try to fix everything from here;
	dp[s] = min(dp[s],2LL*min(miss[s][0]*1LL,miss[s][1]*1LL)*c[s]);
	//indicost
	ll ok = 0;
	debug(s,dp[s],miss[s][0],miss[s][1],c[s],2LL*min(miss[s][0]*1LL,miss[s][1]*1LL)*c[s]);
	for(int i: g[s]){
		if(i == p)continue;
		ok += dp[i];
	}
	ll mni = min(avail[s][0],avail[s][1]);
	debug(avail[s][0],avail[s][1]);
	avail[s][0] -= mni;
	avail[s][1] -= mni;
	ok += mni*2LL*c[s];
	debug(mni,dp[s],ok);
	dp[s] = min(dp[s],ok);
	if(s == 1 && (avail[s][0] > 0 || avail[s][1] > 0))dp[s] = -1; 
}

void solve(int test_case){
	cin >> n;
	loop(i,1,n+1)
		cin >> c[i] >> b[i] >> to[i];
	loop(i,1,n+1){
		merpe[b[i]]++;
		dem[to[i]]++;
	}
	if(merpe[0] != dem[0] || merpe[1] != dem[1]){
		cout << -1;
		return;
	}
	loop(i,1,n){
		int a,b;
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs1(1);
	dfs(1);
	cout << dp[1] << "\n";
}

int main(){
	FAST
	auto clk = clock();
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int t = 1;
	//cin >> t;
	loop(i,1,t+1)solve(i);
	#ifdef LOCAL
		cout << "\n\nTIME ELAPSED : " << double(clock() - clk)/CLOCKS_PER_SEC * 1000.0 << " ms.\n";
	#endif
}