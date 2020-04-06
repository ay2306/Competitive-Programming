//https://codeforces.com/problemset/problem/280/B
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
// Constants
const ll N = 1e5 + 100;
const ll inf = 1e9;
const double pi = acos(-1);
V<int> a;

int cal(V<int> &arr){
	vector<int> s;
	int x = 0;
	for(auto &i: arr){
		while(s.size() && s.back() < i)s.pop_back();
		s.push_back(i);
		if(s.size() >= 2)x = max(x,s[s.size()-1]^s[s.size()-2]);	
	}
	return x;
}

void solve(int test_case){
	int n;
	cin >> n;
	a.resize(n);
	loop(i,0,n)cin >> a[i];
	int ans = cal(a);
	reverse(all(a));
	ans = max(ans,cal(a));
	cout << ans;
}

int main(){
	int t = 1;
	//cin >> t;
	loop(i,1,t+1)solve(i);
}
