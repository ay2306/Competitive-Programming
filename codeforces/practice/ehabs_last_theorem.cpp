
// Code reffered from cerberus97
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
int sq;
int deg[N], lev[N], par[N], vis[N];
bool bad[N];
int low_back[N];
void dfs(int s, int p = 0){
	vis[s] = 1;
	low_back[s] = s;
	for(int &i: g[s]){
		if(!vis[i]){
			par[i] = s;
			++deg[i];
			++deg[s];
			lev[i] = lev[s] + 1;
			dfs(i,s);
		}else if(i != p){
			if(lev[low_back[s]] > lev[i])low_back[s]=i;
		}
	}
}

void solve(int test_case){
	int n,m;
	cin >> n >> m;
	sq = sqrt(n);
	sq+=(sq*sq!=n);
	loop(i,0,m){
		int a,b;
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(1);
	loop(s,1,n+1){
		if(lev[s]-lev[low_back[s]]+1 >= sq){
			cout << 2 << "\n" << lev[s]-lev[low_back[s]]+1 << "\n";
			cout << s << " ";
			for(int j = s; j != low_back[s]; j = par[j]){
				cout << par[j] << " ";
			}
			return ;
		}
	}
	V<int> leaves,ans;
	loop(i,1,n+1)if(deg[i] == 1)leaves.pb(i);
	// loop(i,1,n+1)printf("NODE = %d, parent = %d\n",i,par[i]);
	while(leaves.size()){
		int u = leaves.back();
		leaves.pop_back();
		--deg[par[u]];
		if(deg[par[u]] == 1)leaves.pb(par[u]);
		if(!bad[u]){
			ans.pb(u);
			for(int &i: g[u])bad[i]=true;
		}
	}
	assert(int(ans.size()) >= sq);
	ans.resize(sq);
	cout << 1 << "\n";
	for(int &i: ans)cout << i << " ";
}

int main(){
	FAST
	int t = 1;
	//cin >> t;
	loop(i,1,t+1)solve(i);
}
