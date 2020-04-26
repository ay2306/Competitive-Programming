#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
const long long mod = 1e9+7;
// const long long mod = 998244353;
using namespace std;
// DEBUGGER
// *
vector<string> vec_splitter(string s) {
	s += ',';
	vector<string> res;
	while(!s.empty()) {
		res.push_back(s.substr(0, s.find(',')));
		s = s.substr(s.find(',') + 1);
	}
	return res;
}
void debug_out(
vector<string> __attribute__ ((unused)) args,
__attribute__ ((unused)) int idx, 
__attribute__ ((unused)) int LINE_NUM) { cerr << endl; } 
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
	if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
	stringstream ss; ss << H;
	cerr << args[idx] << " = " << ss.str();
	debug_out(args, idx + 1, LINE_NUM, T...);
}
#ifdef LOCAL
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define debug(...) 42
#endif
// *
// DEBUGGER

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
#define sz(x) (int)((x).size())
#define square(x) ((x)*(x))
#define cube(x) ((x)*(x)*(x))
#define distance(a,b,c,d) ((a-c)*1LL*(a-c)+(b-d)*1LL*(b-d))
#define range(i,x,y) ((x <= i) && (i <= y))
#define SUM(a) accumulate(a.begin(),a.end(),0LL)
#define lb lower_bound
#define ub upper_bound
#define REV reverse
#define seive(N) int pr[N]; void preSieve(){for(int i = 2; i < N; ++i){if(!pr[i])for(int j = i; j < N; j+=i)pr[j]=i;}}
#define modInv(N) ll inv[N]; void preModInv(){inv[0]=0;inv[1]=1;for(int i = 2; i < N; ++i)inv[i] = mod-mod/i*inv[mod%i]%mod;}
#define fact(N) ll fact[N]; void preFact(){fact[0] = 1,fact[1] = 1; for(int i = 2; i < N; ++i)fact[i]=fact[i-1]*i%mod;}
#define inFact(N) ll ifact[N]; void preiFact(){ifact[1] = 1; for(int i = 2; i < N; ++i)ifact[i]=ifact[i-1]*inv[i]%mod;}
// pair operation
template<class T, class U>istream& operator>>(istream& in, pair<T,U> &rhs){in >> rhs.first;in >> rhs.second;return in;}
template<class T, class U>ostream& operator<<(ostream& out,const pair<T,U> &rhs){out << rhs.first;out << " ";out << rhs.second;return out;}
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
template<class T,class U>ostream& operator<<(ostream& out, const map<T,U> &a){for(auto &i: a)cout << "(" << i.first << ", " << i.second << ")\n";return out;}
template<class T,class U>ostream& operator<<(ostream& out, const unordered_map<T,U> &a){for(auto &i: a)cout << "(" << i.first << ", " << i.second << ")\n";return out;}

// using namespace __gnu_pbds;
// template <typename T>
// using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

const long long N = 1e5 + 100;
const int inf = 1e9;
const long double pi = acos(-1);

int n;

class MergeSortTree{
	vector<int> *tree;
public:
	MergeSortTree(V<PII> &arr){
		tree = new vector<int>[(n+1)<<2];
		build(arr);
	}
	void build(V<PII> &arr, int node = 1, int start = 0, int end = n-1){
		if(start == end){
			tree[node].pb(arr[start].second);
			return;
		}
		int mid = start+end >> 1;
		build(arr,node<<1,start,mid);
		build(arr,node<<1|1,mid+1,end);
		merge(tree[node<<1].begin(),tree[node<<1].end(),tree[node<<1|1].begin(),tree[node<<1|1].end(),back_inserter(tree[node]));
	}
	int query(int l, int r, int k, int node = 1, int start = 0, int end = n-1){
		if(l > end || r < start)return 0;
		if(l <= start && end <= r){
			return start-end+1-(lb(all(tree[node]),k)-tree[node].begin());
		}
		int mid = start+end >> 1;
		int p1 = query(l,r,k,node << 1,start,mid);
		int p2 = query(l,r,k,node << 1 | 1,mid+1,end);
		return p1+p2;
	}

};


void solve(int test_case){
	int q;
	cin >> n >> q;
	V<PII> a(n);
	cin >> a;
	V<PII> A(n),B(n);
	loop(i,0,n){
		B[i] = mp(a[i].F,-a[i].F-a[i].S);
		A[i] = mp(a[i].F,a[i].F-a[i].S);
		debug(a[i].F,a[i].S,B[i].F,B[i].S,A[i].F,A[i].S);
	}
	sort(all(A));
	sort(all(B));
	MergeSortTree t1(A),t2(B);
	while(q--){
		int p1,p2,ans=0;
		cin >> p1 >> p2;
		int l,r;
		l = lb(all(A),mp(p1,-inf)) - A.begin();
		r = ub(all(A),mp(p1+p2>>1,-inf)) - A.begin() - 1;
		debug(l,r,ans);
		loop(i,l,r+1){
			debug(i,A[i].F,A[i].S);
		}
		if(l <= r)ans+=t1.query(l,r,p1);
		l = lb(all(B),mp((p2+p1>>1)+1,-inf)) - B.begin();
		r = ub(all(B),mp(p2,-inf)) - B.begin() - 1;
		if(l <= r)ans+=t2.query(l,r,-p2);
		debug(l,r,ans);
		loop(i,l,r+1){
			debug(i,A[i].F,A[i].S);
		}
		int mid = true;
		if(p1%2 == p2%2){
			int k = p1+p2>>1;
			ans+=ub(all(A),mp(k,2*p1-k))-lb(all(A),mp(k,0));
		}
		cout << ans << " ";
	}
	cout << "\n";
}

int main(){
	FAST
	int t = 1;
	cin >> t;
	loop(i,1,t+1)solve(i);
}
