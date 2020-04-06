//https://codeforces.com/contest/776/problem/D
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
const ll N = 3e5 + 100;
const ll M = 1e5 + 100;
const ll inf = 1e9;
const double pi = acos(-1);
int n,m,t,a;
V<int> g[N],gr[N];
int cyc[N];
V<int> rem[N];
int st[N],vis[N],cur;
stack<int> s;

void pnode(int a){
	if(a - m > 0){
		printf(" ~%d ",a-m);
	}else{
		printf(" %d ",a);
	}
}

void add_edge(int a, int b){
	// cout << "Edge between "; pnode(a);
	// cout << " and "; pnode(b);
	// cout << endl;
	g[a].pb(b);
	gr[b].pb(a);
}

void unlocked_edge(int i){
	// *    ~(v1 xor v2)
 	// *    ~((v1 ^ v2) V (v1' ^ v2'))
	// *    (v1' V v2') ^ (v1 ^ v2)
	// *    v2 to v1'
	// *    v2' to v1
	// *    v1' to v2
	// *    v1 to v2'
	int v1 = rem[i][0];   
	int v2 = rem[i][1];
	add_edge(v1,v2+m);
	add_edge(v2,v1+m);
	add_edge(v1+m,v2);
	add_edge(v2+m,v1);
}

void locked_edge(int i){
	// *    (v1 xor v2)
 	// *    ((v1' V v2) ^ (v1 V v2'))
	// *    v2' to v1'
	// *    v2 to v1
	// *    v1 to v2
	// *    v1' to v2'
	int v1 = rem[i][0];   
	int v2 = rem[i][1];
	add_edge(v1,v2);
	add_edge(v2,v1);
	add_edge(v1+m,v2+m);
	add_edge(v2+m,v1+m);
}

void dfs1(int u){
	vis[u] = true;
	for(auto &i: g[u]){
		if(!vis[i])dfs1(i);
	}
	s.push(u);
}
void dfs2(int u){
	cyc[u] = cur;
	for(auto &i: gr[u]){
		if(cyc[i] == 0)dfs2(i);
	}
}

void solve(int test_case){
	scanf("%d%d",&n,&m);
	loop(i,1,n+1)scanf("%d",st+i);
	loop(i,1,m+1){
		scanf("%d",&t);
		while(t--){
			scanf("%d",&a);
			rem[a].emplace_back(i);
		}
	}
	loop(i,1,n+1){
		if(!st[i])unlocked_edge(i);
		else locked_edge(i);
	}
	loop(i,1,2*m+1)if(!vis[i])dfs1(i);
	while(!s.empty()){
		if(cyc[s.top()] == 0){
			cur++;
			dfs2(s.top());
		}
		s.pop();
	}
	// loop(i,1,m+1){
	// 	printf("cyc = %d, neg cyc = %d\n",cyc[i],cyc[i+m]);
	// }
	loop(i,1,m+1){
		if(cyc[i] != 0 && cyc[i+m] != 0 && cyc[i+m] == cyc[i]){
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");
}

int main(){
	int t = 1;
	//cin >> t;
	loop(i,1,t+1)solve(i);
}
