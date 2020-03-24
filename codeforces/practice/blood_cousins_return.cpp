//https://codeforces.com/problemset/problem/246/E
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

unordered_map<int,vector<pair<int,int>>> queries;
V<int> g[N];
V<int> parent(N,-1);
vector<set<string>> v[N];
vector<int> ans;
int vis[N];
int findParent(int x){
	if(parent[x] < 0){
		return x;
	}
	return parent[x] = findParent(parent[x]); 
}

void join(int a, int b){
	int p1 = findParent(a);
	int p2 = findParent(b);
	if(p1 == p2)return;
	if(parent[p1] > parent[p2])swap(p1,p2);
	parent[p2] = p1;
	for(int i = 0; i < v[p2].size(); ++i){
		for(auto j: v[p2][i]){
			if(v[p1].size() > i)v[p1][i].insert(j);
			else{
				set<string> oo;
				oo.insert(j);
				v[p1].pb(oo);
			}
		}
	}
}

void dfs(int s = 1, int p = 0){
	vis[s] = 1;
	for(auto &i: g[s]){
		if(i == p)continue;
		dfs(i,s);
		join(i,s);
	}
	int pr = findParent(s);
	for(auto &i: queries[s]){
		if(v[pr].size() > i.first)ans[i.second] = v[pr][i.first].size();
	}
	set<string> k;
	v[pr].insert(v[pr].begin(),k);
	if(s != pr)v[s].clear();
	for(auto &i: g[s]){
		if(i == p || i == pr)continue;
		v[i].clear();
	}

}

void solve(int test_case){
	int n;
	cin >> n;
	loop(i,1,n+1){
		string a;
		int p;
		cin >> a >> p;
		g[i].pb(p);
		g[p].pb(i);
		set<string> k;
		k.insert(a);
		v[i].pb(k);
	}
	int q;
	cin >> q;
	ans.resize(q);
	loop(i,0,q){
		int l,r;
		cin >> l >> r;
		queries[l].pb(r,i);
	}
	loop(i,1,n+1)if(!vis[i])dfs(i,0);
	for(auto &i: ans)cout << i << "\n";
}

int main(){
	FAST
	int t = 1;
	//cin >> t;
	loop(i,1,t+1)solve(i);
}
