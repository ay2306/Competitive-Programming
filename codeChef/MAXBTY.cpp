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
int sz;
struct NODE{
	ll sum;
	ll pref;
	ll suff;
	ll max;
	NODE():sum(-inf),pref(-inf),suff(-inf),max(-inf){}
};

class segmentTree{
	V<NODE> tree;
public:
	segmentTree(){
		tree.resize((sz<<2)+100);
	}
	void build(V<ll> &arr, int node = 0, int start = 0, int end = sz-1){
		tree[node] = NODE();
		if(start == end){
			tree[node].sum = arr[start];
			tree[node].pref = arr[start];
			tree[node].suff = arr[start];
			return ;
		}
		int mid = start+end>>1;
		build(arr,2*node+1,start,mid);
		build(arr,2*node+2,mid+1,end);
		tree[node].sum = tree[2*node+1].sum+tree[2*node+2].sum;
		tree[node].pref = max(tree[2*node+1].pref,tree[2*node+1].sum+tree[2*node+2].pref);
		tree[node].suff = max(tree[2*node+2].suff,tree[2*node+2].sum+tree[2*node+1].suff);
		// printf("node = %d, (%lld, %lld, %lld)\n",node,tree[node].sum,tree[node].pref,tree[node].suff);
	}
	void update(int ind, int val, int node = 0, int start = 0, int end = sz-1){
		if(start == end){
			tree[node].sum = val;
			tree[node].pref = val;
			tree[node].suff = val;
			return;
		}
		int mid = start+end>>1;
		if(ind <= mid)update(ind,val,2*node+1,start,mid);
		else update(ind,val,2*node+2,mid+1,end);
		tree[node].sum = tree[2*node+1].sum+tree[2*node+2].sum;
		tree[node].pref = max(tree[2*node+1].pref,tree[2*node+1].sum+tree[2*node+2].pref);
		tree[node].suff = max(tree[2*node+2].suff,tree[2*node+2].sum+tree[2*node+1].suff);
	}
	NODE query(int l, int r, int node = 0, int start = 0, int end = sz-1){
		if(l > end || r < start){
			NODE p;
			p.sum = 0;
			p.pref = 0;
			p.suff = 0;
			return p;
		}
		if(l <= start && end <= r)return tree[node];
		int mid = start+end>>1;
		NODE p1 = query(l,r,2*node+1,start,mid);
		NODE p2 = query(l,r,2*node+2,mid+1,end);
		NODE p3;
		p3.sum = p1.sum+p2.sum;
		p3.pref = max(p1.pref,p1.sum+p2.pref);
		p3.suff = max(p2.suff,p2.sum+p1.suff);
		return p3;
	}
};

void solve(int test_case){
	int n,q;
	cin >> n >> q;
	V<ll> a(n);
	sz = n;
	cin >> a;
	segmentTree s;
	s.build(a);
	while(q--){
		int x,y;
		char c;
		cin >> c >> x >> y;
		if(c == 'Q'){
			x--;
			y--;
			ll ans = s.query(x,y).sum;
			if(x-1 >= 0)ans+=max(0LL,s.query(0,x-1).suff);
			if(y+1 < n)ans+=max(0LL,s.query(y+1,n-1).pref);
			cout << ans << "\n";
		}else{
			s.update(x-1,y);
		}
	}
}

int main(){
	FAST
	int t = 1;
	cin >> t;
	loop(i,1,t+1)solve(i);
}
