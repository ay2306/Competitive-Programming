//https://codeforces.com/contest/19/problem/E
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
const ll N = 1e4 + 100;
const ll inf = 1e9;
const double pi = acos(-1);
int n,m;
int col[N];
int vis[N];
V<int> g[N];
set<PII> cb;
V<PII> ans;
int up[N],down[N];
int nup[N],ndown[N];
int d[N];
int pa[N];
int c;
void dfs1(int s = 1, int p = 0){
	d[s] = ++c;
	pa[s] = p; 
	for(auto &i: g[s]){
		if(i == p)continue;
		if(col[i] == 0){
			(col[s] == 1)?col[i]=2:col[i]=1;
			dfs1(i,s);
		}else if(d[s] < d[i]){
			if(col[i] == col[s] && cb.find(mp(s,i))==cb.end()){
				cb.insert(mp(i,s));
			}
		}
	}
}
PII dfs2(int s = 1, int p = 0){
	for(auto &i: g[s]){
		if(i == p)continue;
		if(pa[i] == s){
			auto j =dfs2(i,s);
			up[s]+=j.F;
			nup[s]+=j.S;
		}else if(d[s] > d[i]){
			if(col[i] == col[s]){
				up[s]++;
				down[i]++;
			}else{
				nup[s]++;
				ndown[i]++;
			}
		}
	}
	up[s]-=down[s];
	nup[s]-=ndown[s];
	if(cb.size() && p != 0 && up[s] == cb.size() && nup[s] == 0){
		ans.pb(s,p);
	}
	return mp(up[s],nup[s]);
}

void solve(int test_case){
	cin >> n >> m;
	map<PII,int> in;
	loop(i,0,m){
		int a, b;
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
		in[mp(a,b)] = i+1;
		in[mp(b,a)] = i+1;
	}
	loop(i,1,n+1){
		if(col[i] == 0){
			col[i] = 1;
			dfs1(i);
			dfs2(i);
		}
	}

	if(cb.size() == 0){
		cout << m << "\n";
		loop(i,1,m+1)cout << i << " ";
		return;
	}
	if(cb.size() == 1){
		ans.pb(cb.begin()->first,cb.begin()->second);
	}
	// printf("CB = ");
	// for(auto &i: cb)printf(" (%d, %d) ",i.F,i.S);
	// printf("\n");
	set<int> op;
	for(auto &i: ans)op.insert(in[mp(i.first,i.second)]); 
	cout << op.size() << "\n";
	for(auto &i: op)cout << i << " "; 
}

int main(){
	int t = 1;
	//cin >> t;
	loop(i,1,t+1)solve(i);
}