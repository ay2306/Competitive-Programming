//https://codeforces.com/contest/609/problem/E
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
const ll N = 2e5 + 100;
const ll inf = 1e9;
const double pi = acos(-1);

struct edge{
	int a,b,ind;
	ll w;
	edge(int a = 0, int b = 0, ll c = 0, int d = 0): a(a),b(b),w(c),ind(d){}
	bool operator<(edge const &rhs)const{
		return w < rhs.w;
	}
};
int n,m;
V<edge> e;
int p[N];
V<pair<int,int>> g[N];
int fx(int x){return p[x] == x?x:p[x]=fx(p[x]);}
void un(int a,int b){p[fx(a)]=fx(b);}
int dp[N][20],lev[N];
ll ans[N],mx[N][20];

ll generate_mst(){
	for(int i = 0; i <= n; i++)p[i]=i;
	sort(all(e)); ll mst = 0;
	for(auto &i: e){
		if(fx(i.a) != fx(i.b)){
			un(i.a,i.b);
			mst+=i.w;
			g[i.a].pb(i.b,i.w);
			g[i.b].pb(i.a,i.w);
		}
	}
	return mst;
}

void dfs(int s = 1, int p = 0){
	dp[s][0] = p;
	lev[s] = lev[p]+1;
	for(auto &i: g[s]){
		if(i.first == p)continue;
		mx[i.first][0] = i.second;
		dfs(i.first,s); 
	}
}

void pre(){
	loop(i,1,20){
		loop(j,1,n+1){
			dp[j][i] = dp[dp[j][i-1]][i-1];
			mx[j][i] = max(mx[j][i-1],mx[dp[j][i-1]][i-1]);
		}
	}
}

int lca(int a, int b){
	if(lev[a] > lev[b])swap(a,b);
	int diff = lev[b]-lev[a];
	loop(i,0,20)if((diff >> i)&1)b=dp[b][i];
	if(a == b)return a;
	loopr(i,19,0)if(dp[a][i] != dp[b][i])a=dp[a][i],b=dp[b][i];
	return dp[a][0];
}

ll findMX(int a, int b){
	int l = lca(a,b);
	ll a1 = 0, a2 = 0;
	int d = lev[a]-lev[l];
	loop(i,0,20){
		if((d>>i)&1){
			a1=max(mx[a][i],a1);
			a=dp[a][i];
		}
	}
	d = lev[b]-lev[l];
	loop(i,0,20){
		if((d>>i)&1){
			a2=max(mx[b][i],a2);
			b=dp[b][i];
		}
	}
	return max(a1,a2);
}

void solve(int test_case){
	int a,b,c;
	scanf("%d%d",&n,&m);
	loop(i,0,m){
		scanf("%d%d%d",&a,&b,&c);
		e.emplace_back(edge(a,b,c,i));
	}
	ll mst = generate_mst();
	dfs();
	pre();
	for(auto &i: e){
		ans[i.ind] = mst - findMX(i.a,i.b) + i.w;
	}
	loop(i,0,m)printf("%lld\n",ans[i]);
}

int main(){
	int t = 1;
	//cin >> t;
	loop(i,1,t+1)solve(i);
}
