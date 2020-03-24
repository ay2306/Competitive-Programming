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
#define M map
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
const ll inf = 1e9;
const double pi = acos(-1);

V<int> g[N];
unordered_map<int,int> dnode;
int anc[N][20];
ll dp[N][20];
ll a[N];
int col[N], lev[N];
int n,q;
int t ;
set<int> d[N];
ll ans;
int dt[N];


void dfs(int s = 1, int p = 0){
	dnode[++t] = s;
	dt[s] = t;
	anc[s][0] = p;
	dp[s][0] = a[s];
	for(auto &i: g[s]){
		if(i != p){
			lev[i] = lev[s] + 1;
			dfs(i,s);
		}
	}
}
void pre(){
	loop(j,1,20){
		loop(i,1,n+1){
			anc[i][j] = anc[anc[i][j-1]][j-1];
			dp[i][j] = dp[i][j-1] + dp[anc[i][j-1]][j-1];
		}
	}
}
int lca(int a, int b){
	if(a == 0 || b == 0)return 0;
	if(lev[a] > lev[b])swap(a,b);
	int diff = lev[b]-lev[a];
	loop(i,0,20)if((diff>>i)&1)b=anc[b][i];
	if(a != b){
		loopr(i,19,0)if(anc[a][i] != anc[b][i])a=anc[a][i],b=anc[b][i];
		a = anc[a][0];
	}
	return a;
}
ll update(int node, int c){
	if(col[node] == c)return 0;
	ll ret = 0;
	int left = 0;
	int right = 0;
	if(d[c].size()){
		auto it = d[c].upper_bound(dt[node]);
		if(it != d[c].end()){
			right = dnode[*it];
		}
		if(it != d[c].begin()){
			left = dnode[*prev(it)];
		}
	}
	left = lca(node,left);
	right = lca(node,right);
	int pref;
	(lev[right] > lev[left])?pref=right:pref=left;
	int diff = abs(lev[node]-lev[pref]);
	loop(i,0,20){
		if((diff>>i)&1){
			ret+=dp[node][i];
			node = anc[node][i];
		}
	}
	return ret;
}

void solve(int test_case){
	ans = t = 0;
	lev[1] = 1;
	lev[0] = 0;
	cin >> n >> q;
	loop(i,1,n+1){
		g[i].clear();
		d[i].clear();
	}
	loop(i,1,n){
		int e,f;
		cin >> e >> f;
		g[e].pb(f);
		g[f].pb(e);
	}
	loop(i,1,n+1)cin >> col[i];
	loop(i,1,n+1)cin >> a[i];
	dfs();
	pre();
	loop(i,1,n+1){
		int ci = col[i];
		col[i] = -1;
		ans+=update(i,ci);
		d[ci].insert(dt[i]);
		col[i] = ci;
	}
	// printf("PREANSWER = %lld\n",ans);
	while(q--){
		int a,x;
		cin >> a >> x;
		// Uncoloring step
		int ci = col[a];
		d[col[a]].erase(dt[a]);
		col[a] = -1;
		ans-=update(a,ci);
		ans+=update(a,x);
		d[x].insert(dt[a]);
		col[a] = x;
		cout << ans << "\n";
	}
}

int main(){
	int t = 1;
	cin >> t;
	loop(i,1,t+1)solve(i);
}
