#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MOD 998244353
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
const ll N = 2e5+10;
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

ll fact[N],inv[N];

ll power(ll a, ll n){
	if(n == 0)return 1;
	if(n == 1)return a%MOD;
	ll p = power(a,n/2);
	p*=p;
	if(p>=MOD)p%=MOD;
	if(n%2 == 1){
		p*=a;
		if(p>=MOD)p%=MOD;
	}
	return p;
}

void pre(){
	fact[0] = 1;
	fact[1] = 1;
	inv[0] = 1;
	inv[1] = 1;
	loop(i,2,N){
		fact[i] = fact[i-1]*i;
		if(fact[i] >= MOD)fact[i]%=MOD;
		inv[i] = power(fact[i],MOD-2);
	}
}

ll ncr(ll n, ll r){
	if(r > n || r < 0)return 0;
	return ((fact[n]*inv[r])%MOD*inv[n-r])%MOD;
}

void solve(int test_case){
	ll n,m;
	cin >> n >> m;
	V<ll> dp(n,0);
	loop(i,1,n-1){
		dp[i] = ncr(m,n-1)*ncr(n-2,i);
		dp[i]%=MOD;
		dp[i]*=i;
		dp[i]%=MOD;
	}
	cout << accumulate(all(dp),0LL)%MOD;
}

int main(){
	pre();
	int t = 1;
	//cin >> t;
	loop(i,1,t+1)solve(i);
}
