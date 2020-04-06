//https://codeforces.com/contest/1328/problem/D
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
const ll N = 2e5 + 100;
const ll inf = 1e9;
const double pi = acos(-1);

V<int> col;
void dfs(V<V<int>> g, int s = 1, int c = 1){
	col[s] = c;
	for(auto &i: g[s]){
		if(col[i] == 0)(col[s]==3)?dfs(g,i,1):dfs(g,i,3-c);
		else if (c == col[i])col[s]=3;
	}
}


void solve(int test_case){
	int n;
	map<int,int> m;
	int c = 1;
	cin >> n;
	V<int> arr(n);
	loop(i,0,n)cin >> arr[i],m[arr[i]]++;
	if(m.size() == 1){
		cout << "1\n";
		loop(i,0,n)cout << "1 ";
		cout << "\n";
		return;
	}
	if(n%2 == 0 || (n%2 == 1 && arr[0] == arr[n-1])){
		cout << "2\n";
		int k = n/2;
		loop(i,0,k)cout << "1 2 ";
		if(n&1)cout << "1";
		cout << "\n";
		return;
	}
	bool done = false;
	int i = 1;
	for(;i<n;++i){
		if(arr[i] == arr[i-1])break;
	}
	if(i == n){
		cout << 3 << "\n";
		int k = n/2;
		loop(i,0,k)cout << "1 2 ";
		cout << "3\n";
		return;
	}
	cout << 2 << "\n" << 1 << " ";
	loop(j,1,i){
		if(j&1)cout << "2 ";
		else cout << "1 ";
	}
	loop(j,i,n){
		if(j&1)cout << "1 ";
		else cout << "2 ";
	}
	cout << "\n";
}


int main(){
	FAST
	int t = 1;
	cin >> t;
	loop(i,1,t+1)solve(i);
}
