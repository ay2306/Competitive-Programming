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

pair<int,char> convert(string &a){
	int g = 0;
	for(int i = 0; ; ++i){
		if(a[i] == '-'){
			++i;
			break;
		}
		g*=10;
		g+=(a[i]-'0');
	}
	return pair<int,char> (g,a[a.size()-1]);
}
struct node{
	char c;
	ll cnt;
	node(){}
	node(int a, char b):cnt(a),c(b){}
	bool operator==(node const &a)const{
		return c == a.c && cnt == a.cnt; 
	}
	bool operator>=(node const &a)const{
		return c == a.c && cnt >= a.cnt;
	}
	bool operator<=(node const &a)const{
		return c == a.c && cnt <= a.cnt;
	}
};
int n,m;
string p;
V<node> a,b;
V<int> lps;


void compute_lps(vector<node> &s){
	int n = s.size(), i = 1, j = 0;
	lps.resize(n,0);
	while(i < n){
		if(b[i] == b[j]){
			lps[i++] = ++j;
		}else{
			if(j == 0)i++;
			else j = lps[j-1];
		}
	}
}

void solve(int test_case){
	cin >> n >> m >> p;
	auto it = convert(p);
	a.push_back(node(it.first,it.second));
	for(int i = 1; i < n; ++i){
		cin >> p;
		it = convert(p);
		if(it.second == a.back().c)a.rbegin()->cnt+=it.first;
		else a.push_back(node(it.first,it.second));
	}
	cin >> p;
	it = convert(p);
	b.push_back(node(it.first,it.second));
	for(int i = 1; i < m; ++i){
		cin >> p;
		it = convert(p);
		if(it.second == b.back().c)b.rbegin()->cnt+=it.first;
		else b.push_back(node(it.first,it.second));
	}
	ll ans = 0;
	// if(n == 165864 && m == 1){
	// 	cout 
	// }
	n = a.size();
	m = b.size();
	if(m == 1){
		for(int i = 0; i < n; ++i)if(a[i] >= b[0])ans+=(a[i].cnt-b[0].cnt+1);
	}else if(m == 2){
		for(int i = 1; i < n; ++i)if(a[i] >= b[1] && a[i-1] >= b[0])ans++;
	}else{
		node f = b[0];
		node l = b.back();
		b.erase(b.begin());
		b.pop_back();
		compute_lps(b);
		m = b.size();
		int i = 0, j = 0;
		while(i < n){
			if(a[i] == b[j]){
				i++;
				j++;
				if(j == m){
					int start = i-j;
					int end = i;
					start--;
					if(start >= 0 && end < n && a[start] >= f && a[end] >= l)ans++;
					j = lps[j-1];
				}
			}else{
				if(j == 0)i++;
				else j = lps[j-1];
			}
		}
	}
	cout << ans;
}

int main(){
	FAST
	int t = 1;
	//cin >> t;
	loop(i,1,t+1)solve(i);
}
