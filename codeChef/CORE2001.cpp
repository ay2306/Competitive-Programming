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
const ll N = 1e5;
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

void solve(int test_case){
	int n,m;
	cin >> n >> m;
	V<V<V<ll>>> dp(n,V<V<ll>>(m,V<ll>(2,0)));
	loops(i,1,m,2)dp[0][i][0] = 1;
	loop(i,0,n){
		loop(j,0,m){
			if(i+1 < n && j+2 < m) dp[i+1][j+2][0]+=dp[i][j][1];
			if(i+1 < n && j-2 >= 0)dp[i+1][j-2][0]+=dp[i][j][1];
			if(i+2 < n && j+1 < m) dp[i+2][j+1][0]+=dp[i][j][1];
			if(i+2 < n && j-1 >= 0)dp[i+2][j-1][0]+=dp[i][j][1];

			if(i+1 < n && j+2 < m) dp[i+1][j+2][0]%=MOD;
			if(i+1 < n && j-2 >= 0)dp[i+1][j-2][0]%=MOD;
			if(i+2 < n && j+1 < m) dp[i+2][j+1][0]%=MOD;
			if(i+2 < n && j-1 >= 0)dp[i+2][j-1][0]%=MOD;
			
			if(i+1 < n && j+2 < m) dp[i+1][j+2][1]+=dp[i][j][0];
			if(i+1 < n && j-2 >= 0)dp[i+1][j-2][1]+=dp[i][j][0];
			if(i+2 < n && j+1 < m) dp[i+2][j+1][1]+=dp[i][j][0];
			if(i+2 < n && j-1 >= 0)dp[i+2][j-1][1]+=dp[i][j][0];

			if(i+1 < n && j+2 < m) dp[i+1][j+2][1]%=MOD;
			if(i+1 < n && j-2 >= 0)dp[i+1][j-2][1]%=MOD;
			if(i+2 < n && j+1 < m) dp[i+2][j+1][1]%=MOD;
			if(i+2 < n && j-1 >= 0)dp[i+2][j-1][1]%=MOD;
		}
	}
	ll ans = 0;
	loop(i,0,m){
		ans+=dp[n-1][i][1];
		ans%=MOD;
	}
	cout << ans;
}

int main(){
	FAST
	int t = 1;
	//cin >> t;
	loop(i,1,t+1)solve(i);
}
