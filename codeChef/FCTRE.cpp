#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O2")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
#define UM unordered_map
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
#define random_init mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define shuffle_random(a) random_shuffle(all(a),rng);
using namespace std;
// Constants
const ll N = 1e5 + 100;
const ll M = 1e6 + 100;
const ll inf = 1e9;
const double pi = acos(-1);
int n,Q,a,b;
int K;
ll arr[N],ans=1,inv[M],res[N],en[N],id[N<<1];
V<int> g[N];
int dp[N][20],lo[N],hi[N],cur,lev[N];
short vis[N],at;
int pr[M];
unordered_map<int,int> f[N],froot[N];
unordered_map<int,int> current;
vector<int> primes;
/** Interface */

inline int readChar();
template <class T = int> inline T readInt(); 
template <class T> inline void writeInt( T x, char end = 0 );
inline void writeChar( int x ); 
inline void writeWord( const char *s );

/** Read */

static const int buf_size = 4096;

inline int getChar() {
	static char buf[buf_size];
	static int len = 0, pos = 0;
	if (pos == len)
		pos = 0, len = fread(buf, 1, buf_size, stdin);
	if (pos == len)
		return -1;
	return buf[pos++];
}

inline int readChar() {
	int c = getChar();
	while (c <= 32)
		c = getChar();
	return c;
}

template <class T>
inline T readInt() {
	int s = 1, c = readChar();
	T x = 0;
	if (c == '-')
		s = -1, c = getChar();
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getChar();
	return s == 1 ? x : -x;
}

/** Write */

static int write_pos = 0;
static char write_buf[buf_size];

inline void writeChar( int x ) {
	if (write_pos == buf_size)
		fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
	write_buf[write_pos++] = x;
}

template <class T> 
inline void writeInt( T x, char end ) {
	if (x < 0)
		writeChar('-'), x = -x;

	char s[24];
	int n = 0;
	while (x || !n)
		s[n++] = '0' + x % 10, x /= 10;
	while (n--)
		writeChar(s[n]);
	if (end)
		writeChar(end);
}

inline void writeWord( const char *s ) {
	while (*s)
		writeChar(*s++);
}

struct Flusher {
	~Flusher() {
		if (write_pos)
			fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
	}
} flusher;


inline int64_t gilbertOrder(int x, int y, int pow, int rotate) {
	if (pow == 0) {
		return 0;
	}
	int hpow = 1 << (pow-1);
	int seg = (x < hpow) ? (
		(y < hpow) ? 0 : 3
	) : (
		(y < hpow) ? 1 : 2
	);
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	int64_t subSquareSize = int64_t(1) << (2*pow - 2);
	int64_t ans = seg * subSquareSize;
	int64_t add = gilbertOrder(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}

struct Query{
	int l,r,ind,lc;
	int64_t ord;
	Query(int l = 0, int r = 0, int ind = 0):l(l),r(r),ind(ind){}
	void cal(){ord=gilbertOrder(l,r,21,0);}
}q[N];

ll power(ll a, ll n){
	if(n == 0)return 1;
	if(n == 1)return a%MOD;
	ll p = power(a,n>>1);
	p*=p;
	if(p >= MOD)p%=MOD;
	if(n&1)p*=a;
	if(p >= MOD)p%=MOD;
	return p;
}

void dfs(int s = 1, int p = 0){
	dp[s][0] = p;
	lo[s] = ++cur;
	id[cur] = s;
	for(auto &i: f[s])froot[s][i.first]=i.second;
	if(p){
		for(auto &i: froot[p])froot[s][i.first]+=i.second;
	}
	for(int &i: g[s]){
		if(i != p){
			lev[i] = lev[s]+1;
			dfs(i,s);
		}
	}
	en[s] = ++cur; id[cur] = s;
}

void pre(){
	loop(i,1,20){
		loop(j,1,n+1)dp[j][i] = dp[dp[j][i-1]][i-1];
	}
}

inline int lca(int a, int b){
	if(lev[a] > lev[b])swap(a,b);
	int d = lev[b]-lev[a];
	loop(i,0,20)if((d>>i)&1)b=dp[b][i];
	if(a == b)return a;
	loopr(i,19,0)if(dp[a][i] != dp[b][i])a=dp[a][i],b=dp[b][i];
	return dp[a][0];
}

void add_to_current(int x){
	if(arr[x] < 2)return;
	if(current[arr[x]] !=0)ans*=inv[current[arr[x]]+1];
	if(ans >= MOD)ans%=MOD;
	current[arr[x]]++;
	if(current[arr[x]] !=0)ans*=(current[arr[x]]+1);
	if(ans >= MOD)ans%=MOD;
}
void remove_from_current(int x){
	if(arr[x] < 2)return;
	if(current[arr[x]] !=0)ans*=inv[current[arr[x]]+1];
	if(ans >= MOD)ans%=MOD;
	current[arr[x]]--;
	if(current[arr[x]] !=0)ans*=(current[arr[x]]+1);
	if(ans >= MOD)ans%=MOD;
}


inline void implement(int x){
	if(vis[x])remove_from_current(x);
	else add_to_current(x);
	vis[x]^=1;
}

void solve(int test_case){
	current.clear();
	ans = 1;
	cur = 0;
	n = readInt();
	loop(i,0,n+1)g[i].clear(),f[i].clear(),vis[i]=0;
	loop(i,1,n){
		a = readInt();
		b = readInt();
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	loop(i,1,n+1)arr[i] = readInt();
	loop(i,1,n+1){
		while(pr[arr[i]] > 1){
			f[i][pr[arr[i]]]++;
			arr[i]/=pr[arr[i]];
		}
	}
	dfs(); 
	pre();
	K = sqrt(N);
	Q = readInt();
	loop(i,0,Q){
		a = readInt();
		b = readInt();
		q[i].lc = lca(a,b);
		if(lo[a] > lo[b])swap(a,b);
		if(q[i].lc == a)q[i].l=lo[a],q[i].r=lo[b];
		else q[i].l = en[a], q[i].r = lo[b];
		q[i].ind = i;
		q[i].cal();
	}
	sort(q,q+Q,[](const Query &lhs, const Query &rhs)->bool{
		return lhs.ord < rhs.ord;
	});
	int curL = q[0].l, curR = q[0].l-1;
	loop(i,0,Q){
		while(curL < q[i].l)implement(id[curL++]);
		while(curR < q[i].r)implement(id[++curR]);
		while(curL > q[i].l)implement(id[--curL]);
		while(curR > q[i].r)implement(id[curR--]);
		int a = id[curL], b = id[curR];
		if(a != q[i].lc && b != q[i].lc)implement(q[i].lc);
		res[q[i].ind] = ans;
		if(a != q[i].lc && b != q[i].lc)implement(q[i].lc);
		for(auto &j: primes){
			res[q[i].ind] *= (froot[a][j]+froot[b][j]-2*froot[q[i].lc][j]+f[q[i].lc][j]+1);
			if(res[q[i].ind] >= MOD)res[q[i].ind] %= MOD;
		}
	}
	loop(i,0,Q)writeInt(res[i],'\n');
}

int main(){
	FAST
	current.reserve(32786);
	current.max_load_factor(0.25);
	inv[1] = 1;
	loop(i,2,M)
		inv[i] = MOD-MOD/i*inv[MOD%i]%MOD;
	loop(i,2,1001){
		if(pr[i] == 0){
			primes.emplace_back(i);
			loops(j,i,M,i)pr[j] = i;
		}
	}
	int t = 1;
	t = readInt();
	loop(i,1,t+1)solve(at++);
	return 0;
}
