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

int tree[N<<2];

void update(int ind, int node = 0, int start = 0, int end = N-1){
	if(start == end){
		tree[node]++;
		return;
	}
	int mi = start + end >> 1;
	if(ind <= mi)update(ind,2*node+1,start,mi);
	if(ind > mi)update(ind,2*node+2,mi+1,end);
	tree[node] = tree[2*node+1]+tree[2*node+2];
}

int query(int l, int r, int node = 0, int start = 0, int end = N-1){
	if(start > r || end < l)return 0;
	if(l <= start && end <= r)return tree[node];
	int mi = start+end >> 1;
	return query(l,r,2*node+1,start,mi)+query(l,r,2*node+2,mi+1,end);
}

void solve(int test_case){
	memset(tree,0,sizeof(tree));
	int n;
	cin >> n;
	cout << "Case #" << test_case << ": ";
	loop(i,0,n){
		int a;
		cin >> a;
		update(a);
		int lo = 1;
		int hi = i+1;
		int ans = lo;
		while(lo <= hi){
			int mi = lo + hi >> 1;
			int cnt = query(mi,N-1);
			if(cnt >= mi){
				ans = mi;
				lo = mi + 1;
			}else{
				hi = mi - 1;
			}
		}
		cout << ans << " ";
	}
	cout << "\n";
}

int main(){
	// FAST
	int t = 1;
	cin >> t;
	loop(i,1,t+1)solve(i);
}
