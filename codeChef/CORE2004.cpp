#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
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
// using namespace __gnu_pbds;
// template <typename T>
// using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll N = 1e5+10;
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
ll levMax[N], lev[N], a[N];
multiset<PLL> mx[N];
V<int> g[N];
V<ll> tree;
int n;
int mxLevel;
void init(int s = 1, int p = -1){
	for(int &i: g[s]){
		if(i == p)continue;
		lev[i] = lev[s] + 1;
		mxLevel = max(mxLevel*1LL,lev[i]);
		mx[lev[i]].insert(mp(a[i],i));
		init(i,s);
	}
}

void build(int node = 0, int start = 0, int end = mxLevel){
	if(start == end){
		tree[node] = prev(mx[start].end())->F;
		return;
	}
	int mi = start + end >> 1;
	build(2*node+1,start,mi);
	build(2*node+2,mi+1,end);
	tree[node] = max(tree[2*node+1],tree[2*node+2]);
}

void update(int ind, int node = 0, int start = 0, int end = mxLevel){
	if(start == end){
		tree[node] = prev(mx[start].end())->F;
		return;
	}
	int mi = start + end >> 1;
	if(mi >= ind)update(ind,2*node+1,start,mi);
	else update(ind,2*node+2,mi+1,end);
	tree[node] = max(tree[2*node+1],tree[2*node+2]);
}

ll query(int l, int r, int node = 0, int start = 0, int end = mxLevel){
	if(start > r || end < l)return LLONG_MIN;
	if(l <= start && end <= r)return tree[node];
	int mi = start + end >> 1;
	ll p1 = query(l,r,2*node+1,start,mi);
	ll p2 = query(l,r,2*node+2,mi+1,end);
	return max(p1,p2);
}

void solve(int test_case){
	scanf("%d",&n);
	loop(i,1,n+1)scanf("%lld",a+i);
	loop(i,1,n){
		int a,b;
		scanf("%d%d",&a,&b);
		g[a].pb(b);
		g[b].pb(a);
	}
	mx[0].insert(mp(a[1],1));
	init();
	// loop(i,0,mxLevel+1){	
	// 	levMax[i] = prev(mx[i].end())->second;
	// }
	tree.resize((mxLevel+1) << 2);
	build();
	int q;
	scanf("%d",&q);
	while(q--){
		int t;
		scanf("%d",&t);
		if(t == 1){
			int node;
			ll v;
			scanf("%d%lld",&node,&v);
			// cin >> node >> v;
			int l = lev[node];
			auto it = mx[l].find(mp(a[node],node));
			mx[l].erase(it);
			mx[l].insert(mp(v,node));
			update(l);
			a[node] = v;
			continue;
		}
		ll x;
		scanf("%lld",&x);
		int lo = 0;
		int hi = mxLevel;
		int pos = -1;
		while(lo <= hi){
			int mi = lo + hi >> 1;
			ll val = query(0,mi);
			if(val > x){
				pos = mi;
				hi = mi - 1;
			}else{
				lo = mi+1;
			}
		}
		if(pos == -1){
			printf("-1\n");
			continue;
		}
		auto it = mx[pos].lower_bound(mp(x+1,LLONG_MIN));
		if(it == mx[pos].end()){
			printf("-1\n");
			continue;
		}else{
			printf("%d\n",it->second);
		}
	}
}

int main(){
	int t = 1;
	//cin >> t;
	loop(i,1,t+1)solve(i);
}
