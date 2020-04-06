//https://codeforces.com/contest/915/problem/D
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
const ll N = 505;
const ll inf = 1e9;
const double pi = acos(-1);

V<int> g[N];
int d[N],ac[N];
int c;
int b = 0;
int ina,inb;
int cur;
int parent[N];
V<PII> cyc;
void dfs(int s){
	ac[s] = 1;
	d[s] = ++c;
	for(auto &i: g[s]){
		if(s == ina && i == inb)continue;
		if(d[i] <= cur)dfs(i);
		else if(d[i] < d[s] && ac[i])b++;
		// printf("i = %d, s = %d, b = %d\n",i,s,b);
	}
	ac[s] = 0;
}

void find_any_cycle(int s){
	ac[s] = 1;
	d[s] = ++c;
	for(auto &i: g[s]){
		if(s == ina && i == inb)continue;
		if(d[i] <= cur){parent[i] = s;find_any_cycle(i);}
		else if(d[i] < d[s] && ac[i]){
			cyc.pb(s,i);
			return;
		}
	}
	ac[s] = 0;

}

void solve(int test_case){
	int n , m;
	cin >> n >> m;
	while(m--){
		int a,b;
		cin >> a >> b;
		g[a].pb(b);
	}
	loop(i,1,n+1){
		if(d[i] <= cur)find_any_cycle(i);
	}
	cur = c;
	if(cyc.size() == 0){
		cout << "YES\n";
		return;
	}
	auto p1 = cyc[0];
	cyc.clear();
	cyc.pb(p1);
	int node = p1.first;
	while(node != p1.second){
		cyc.pb(parent[node],node);
		node = parent[node];
	} 
	for(auto i: cyc){
		ina = i.first;
		inb = i.second;
		b = 0;
		// printf("______________\n");
		loop(f,1,n+1)if(d[f] <= cur){
			// printf("MAIN = %d\n",f);
			dfs(f);
		}
		cur = c;
		if(b == 0){
			cout << "YES\n";
			// cout << ina << " " << inb << "\n";
			return;	
		}	
	}
	cout << "NO\n";
}

int main(){
	FAST
	int t = 1;
	//cin >> t;
	loop(i,1,t+1)solve(i);
}
