#include <bits/stdc++.h>
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
// pair operation
template<class T, class U>istream& operator>>(istream& in, pair<T,U> &rhs){in >> rhs.first;in >> rhs.second;return in;}
template<class T, class U>ostream& operator>>(ostream& out,const pair<T,U> &rhs){out << rhs.first;out << " ";out << rhs.second;return out;}
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
template<class T,class U>ostream& operator<<(ostream& out, const map<T,U> &a){for(auto &i: a)cout << "(" << i.first << ", " << i.second << "(\n";return out;}
template<class T,class U>ostream& operator<<(ostream& out, const unordered_map<T,U> &a){for(auto &i: a)cout << "(" << i.first << ", " << i.second << "(\n";return out;}

// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

// Constants
const ll N = 1e5 + 100;
const ll M = 1e6 + 100;
const ll inf = 1e9;
const double pi = acos(-1);
int K,n,Q,a,b;
ll arr[N],ans=1,inv[M],res[N],en[N],id[N<<1];
V<int> g[N];
int dp[N][20],lo[N],hi[N],cur,lev[N];
bool vis[N];
int pr[M];
map<int,map<int,int>>f;
map<int,int> current;

struct Query{
	int l,r,ind,lc;
	Query(int l = 0, int r = 0, int ind = 0):l(l),r(r),ind(ind){}
	bool operator<(const Query &rhs)const{
		if(l/K != rhs.l/K)return l < rhs.l;
		if(l/K&1)return r < rhs.r;
		return r > rhs.r;
	}
}q[N];


ll power(ll a, ll n){
	if(n == 0)return 1;
	if(n == 1)return a%MOD;
	ll p = power(a,n>>1);
	p*=p;
	p%=MOD;
	if(n&1)p*=a;
	p%=MOD;
	return p;
}

void dfs(int s = 1, int p = 0){
	dp[s][0] = p;
	lo[s] = ++cur;
	id[cur] = s;
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

int lca(int a, int b){
	if(lev[a] > lev[b])swap(a,b);
	int d = lev[b]-lev[a];
	loop(i,0,20)if((d>>i)&1)b=dp[b][i];
	if(a == b)return a;
	loopr(i,19,0)if(dp[a][i] != dp[b][i])a=dp[a][i],b=dp[b][i];
	return dp[a][0];
}

void add_to_current(int x){
	if(arr[x] < 2)return;
	// printf("add %lld to current\nIts primes factors: ",arr[x]);
	for(auto &i: f[arr[x]]){
		// printf("(p = %d, c = %d) ",i.F,i.S);
		if(current[i.F] !=0)ans*=inv[current[i.F]+1];
		// ,MOD-2);
		if(ans >= MOD)ans%=MOD;
		current[i.F]+=i.S;
		if(current[i.F] !=0)ans*=(current[i.F]+1);
		if(ans >= MOD)ans%=MOD;
	}
	// printf("\nans = %lld\n",ans);
}
void remove_from_current(int x){
	if(arr[x] < 2)return;
	// printf("removing %lld from current\n",arr[x]);
	for(auto &i: f[arr[x]]){
		// printf("(p = %d, c = %d) ",i.F,i.S);
		if(current[i.F] !=0)ans*=inv[current[i.F]+1];
		// ,MOD-2);
		if(ans >= MOD)ans%=MOD;
		current[i.F]-=i.S;
		if(current[i.F] !=0)ans*=(current[i.F]+1);
		if(ans >= MOD)ans%=MOD;
	}
}


void implement(int x){
	if(vis[x])remove_from_current(x);
	else if(!vis[x])add_to_current(x);
	vis[x]^=1;
}

void solve(int test_case){
	current.clear();
	ans = 1;
	cur = 0;
	f.clear();
	loop(i,0,N)g[i].clear();
	memset(vis,0,sizeof(vis));
	scanf("%d",&n);
	loop(i,1,n){
		scanf("%d%d",&a,&b);
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	loop(i,1,n+1)scanf("%lld",arr+i);
	loop(i,1,n+1){
		if(f[arr[i]].size() != 0)continue;
		int x = arr[i];
		while(x > 1){
			f[arr[i]][pr[x]]++;
			x/=pr[x];
		}
	}
	dfs(); 
	pre();
	K = sqrt(n);
	scanf("%d",&Q);
	loop(i,0,Q){
		scanf("%d%d",&a,&b);
		q[i].lc = lca(a,b);
		if(lo[a] > lo[b])swap(a,b);
		if(q[i].lc == a)q[i].l=lo[a],q[i].r=lo[b];
		else q[i].l = en[a], q[i].r = lo[b];
		q[i].ind = i;
	}
	sort(q,q+Q);
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
	}
	loop(i,0,Q)printf("%lld\n",res[i]);
}
	
int main(){
	// f.reserve(1024);
	// f.max_load_factor(0.25);
	// current.reserve(1024);
	// current.max_load_factor(0.25);
	inv[1] = 1;
	loop(i,2,M){
		inv[i] = MOD-MOD/i*inv[MOD%i]%MOD;
		if(pr[i] == 0){
			loops(j,i,M,i)pr[j] = i;
		}
	}
	int t = 1;
	scanf("%d",&t);
	loop(i,1,t+1)solve(i);
	return 0;
}
