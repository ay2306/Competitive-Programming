//https://codeforces.com/problemset/problem/507/E
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
const ll N = 1e5 + 100;
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

int disR[N],cntR[N],parent[N],vis[N];
int n,m,a,b,c;
V<PII> g[N];
V<pair<PII,int>> e;

void dfs(int s = 1, int p = -1, int dis = 0, int cnt = 0){
	parent[s] = p;
	int choice = -1;
	int cnt1 = -1;
	vis[s] = 1;
	int cur;
	for(auto &i: g[s]){
		if(vis[i.F])continue;
		// printf("cur = %d adj data node = %d, disR = %d, cntR = %d\n",s,i.F,disR[i.F],cntR[i.F]);
		if(dis + disR[i.F] + 1 == disR[1] && cnt+cntR[i.F]+i.S > cnt1){
			cnt1 = cnt+cntR[i.F]+i.S;
			choice = i.F;
			cur = i.S;
		}
	}
	if(choice != -1)dfs(choice,s,dis+1,cnt+cur);
}

void solve(int test_case){
	scanf("%d%d",&n,&m);
	loop(i,0,m){
		scanf("%d%d%d",&a,&b,&c);
		g[a].pb(b,c);
		g[b].pb(a,c);
		e.pb(mp(a,b),c);
	}
	deque<int> q;
	q.push_back(n);
	while(q.size()){
		int s = q.front();
		q.pop_front();
		vis[s] = 1;
		for(auto &i: g[s]){
			if(vis[i.F])continue;
			disR[i.F] = disR[s]+1;
			cntR[i.F]+=(i.S);
			if(i.S)q.push_front(i.F);
			else q.push_back(i.F);
		}
	}
	memset(vis,0,sizeof(vis));
	// cout << disR[1] << "\n";
	dfs();
	set<PII> c;
	int cur = n;
	while(parent[cur] != -1){
		// cout << cur << " " << parent[cur] << "\n";
		c.insert(mp(cur,parent[cur]));
		cur = parent[cur];
	}
	V<P<PII,int>> changes;
	for(auto &i: e){
		if(c.find(mp(i.F.F,i.F.S)) != c.end() || c.find(mp(i.F.S,i.F.F)) != c.end()){
			if(i.S == 0){
				changes.pb(mp(i.F.F,i.F.S),1);
			}
		}else if(i.S){
				changes.pb(mp(i.F.F,i.F.S),0);
		}
	}
	printf("%d\n",int(changes.size()));
	for(auto &i: changes){
		printf("%d %d %d\n",i.F.F,i.F.S,i.S);
	}
}

int main(){
	int t = 1;
	//cin >> t;
	loop(i,1,t+1)solve(i);
}
