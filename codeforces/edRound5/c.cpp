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

int n,m;
V<string> a;
V<V<int>> ans;
V<V<bool>> vis,vis1;
map<PII,PII> parent;
PII cur;
set<PII> s;
void setThem(int i, int j, int val){
	if(i >= n || i < 0 || j >= m || j < 0 || vis1[i][j] || a[i][j] != '.')return;
	vis1[i][j] = true;
	setThem(i+1,j,val);
	setThem(i-1,j,val);
	setThem(i,j+1,val);
	setThem(i,j-1,val);
	ans[i][j] = val;
}

int dfs(int i, int j){
	if(i >= n || i < 0 || j >= m || j < 0 || vis[i][j] || a[i][j] != '.')return 0;
	// cout << i << " " << j << "\n";
	vis[i][j] = true;
	ans[i][j] = 1;
	ans[i][j]+=dfs(i+1,j);
	ans[i][j]+=dfs(i-1,j);
	ans[i][j]+=dfs(i,j+1);
	ans[i][j]+=dfs(i,j-1);
	parent[mp(i,j)] = cur;
	return ans[i][j];
}

int VAL(int i, int j){
	if(i >= n || i < 0 || j >= m || j < 0 || a[i][j] != '.')return 0;
	if(s.find(parent[mp(i,j)]) != s.end())return 0;
	s.insert(parent[mp(i,j)]);
	return ans[i][j];
}

void solve(int test_case){
	cin >> n >> m;
	a.resize(n);
	loop(i,0,n)cin >> a[i];
	ans.resize(n,V<int>(m,0));
	vis.resize(n,V<bool>(m,false));
	vis1.resize(n,V<bool>(m,false));
	loop(i,0,n){
		loop(j,0,m){
			if(a[i][j] == '.' && !vis[i][j]){
				cur=mp(i,j);
				dfs(i,j);
				setThem(i,j,ans[i][j]);
			}
		}
	}
	loop(i,0,n){
		loop(j,0,m){
			if(a[i][j] == '.')cout << '.';
			else{
				s.clear();
				int cnt = 0;
				cnt+=VAL(i-1,j);	
				cnt+=VAL(i+1,j);	
				cnt+=VAL(i,j-1);	
				cnt+=VAL(i,j+1);	
				cout << (cnt+1)%10;
			}
		}
		cout << "\n";
	}
}

int main(){
	int t = 1;
	//cin >> t;
	loop(i,1,t+1)solve(i);
}
