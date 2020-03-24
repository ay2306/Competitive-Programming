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
const ll N = 5e3 + 100;
const ll inf = 1e9;
const double pi = acos(-1);
ll cnt [N];
ll cnt2[N];
ll inv [N];
ll fct [N];
ll ans [N];

ll power(ll a, ll n){
	if(n == 0)return 1;
	if(n == 1)return a%MOD;
	ll p = power(a,n>>1);
	p*=p;
	p%=MOD;
	if(n&1)p*=a;
	p%=MOD;
	return p;
}

V<int> setOrder(vector<char> &s){
	vector<int> z(s.size(),0);
	int n = s.size();
	for(int i = 1, l = 0, r = 0; i < n; ++i){
		if(i <= r){
			z[i] = min(r-i+1,z[i-l]);
		}
		while(i+z[i] < n && s[z[i]] == s[i+z[i]])z[i]++;
		if(i+z[i]-1 > r){
			l = i;
			r = i+z[i]-1;
		}
	}
	return z;
}

void pre(){
	fct[0] = 1;
	fct[1] = 1;
	inv[0] = 1;
	inv[1] = 1;
	loop(i,2,N){
		fct[i] = (i*fct[i-1])%MOD;
		inv[i] = power(fct[i],MOD-2);
	}
}

ll ncr(int n, int r){
	if(r < 0 || r > n)return 0;
	return ((fct[n]*inv[r])%MOD * inv[n-r])%MOD;
}

void solve(int test_case){
	int n,Q;
	memset(cnt2,0,sizeof(cnt2));
	memset(ans,0,sizeof(ans));
	cin >> n >> Q;
	string bs;
	cin >> bs;
	vector<char> a(all(bs));
	loop(i,0,n){
		vector<int> z = setOrder(a);
		memset(cnt,0,sizeof(cnt));
		for(auto &x: z){
			cnt[0]++;
			cnt[x+1]--;
		}
		loop(i,1,n+1){
			cnt[i] += cnt[i-1];
			cnt2[cnt[i]]++;
		}
		ans[1] += n-i;	
		a.erase(a.begin());
	}
	loop(i,1,n+1){
		loop(j,1,i+1){
			ans[j+1] += (cnt2[i] * ncr(i,j))%MOD;
			ans[j+1] %= MOD;
		}
	} 
	while(Q--){
		ll k;
		cin >> k;
		if(k > n){
			cout << "0\n";
		}else{
			cout << ans[k] << "\n";
		}
	}
}

int main(){
	FAST
	pre();
	int t = 1;
	cin >> t;
	loop(i,1,t+1)solve(i);
}
