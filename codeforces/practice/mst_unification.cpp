
// ____________________________________________

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
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll N = 2e5+100;
const ll inf = 1e9;
const double pi = acos(-1);
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

struct edge{
	int a,b;
	ll w;
	edge(){}
	edge(int a, int b, ll c):a(a),b(b),w(c){}
	bool operator<(const edge &rhs){
		return w < rhs.w;
	}
} e[N];
int n,m,p[N],lev[N];
ll dp[N][20],up[N][20];
set<pair<int,ll>> g[N];
int ans;
int fp(int x){
	if(x != p[x])p[x]=fp(p[x]);
	return p[x];
}
void un(int a, int b){
	p[fp(a)] = fp(b);
}

void dfs(int s = 1, int p = -1){
	if(p == -1)lev[s] = 0;
	else lev[s] = lev[p]+1;
	for(auto &i: g[s]){
		if(i.first == p)continue;
		up[i.first][0] = s;
		dp[i.first][0] = i.second;
		dfs(i.first,s); 
	}
}

void pre(){
	loop(j,1,20){
		loop(i,1,N){
			up[i][j] = up[up[i][j-1]][j-1];
			dp[i][j] = max({dp[i][j],dp[i][j-1],dp[up[i][j-1]][j-1]});
		}
	}
}

int lca(int a, int b){
	if(lev[a] > lev[b])swap(a,b);
	int diff = lev[b] - lev[a];
	loop(i,0,20)if((diff >> i) & 1)b = up[b][i];
	if(a == b)return a;
	loopr(i,19,0)if(up[a][i] != up[b][i])a=up[a][i],b=up[b][i];
	return up[a][0];
}

int findMx(int a, int b){
	int l = lca(a,b);
	int diff = lev[a] - lev[l];
	ll mx = 0;
	loopr(i,19,0)if((diff >> i)&1){
		mx = max(mx,dp[a][i]);
		a = up[a][i];
	}
	diff = lev[b] - lev[l];
	loopr(i,19,0)if((diff >> i)&1){
		mx = max(mx,dp[b][i]);
		b = up[b][i];
	}
	return mx;
}

void krushkal(){
	loop(j,0,m){
		auto &i = e[j];
		if(fp(i.a) != fp(i.b)){
			un(i.a,i.b);
			g[i.a].insert(make_pair(i.b,i.w));
			g[i.b].insert(make_pair(i.a,i.w));
		}
	}
	dfs();
	pre();
}


void solve(int test_case){
	loop(i,1,N)p[i] = i;
	scanf("%d%d",&n,&m);
	loop(i,0,m){
		scanf("%d%d%lld",&e[i].a,&e[i].b,&e[i].w);
	}
	sort(e,e+m);
	krushkal();
	loop(j,0,m){
		auto &i = e[j];
		if(g[i.a].find(make_pair(i.b,i.w)) != g[i.a].end())continue;
		if(findMx(i.a,i.b) == i.w)ans++;
	}
	cout << ans;
}

int main(){
	int t = 1;
	//cin >> t;
	loop(i,1,t+1)solve(i);
}
