//https://codeforces.com/problemset/problem/555/B
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

int n,m,ans[N];
ll l[N],r[N],a[N];
V<P<ll,PII>> e;
set<P<ll,int>> q;

void solve(int test_case){
	scanf("%d%d",&n,&m);
	loop(i,0,n)scanf("%lld%lld",l+i,r+i);
	loop(i,0,m)scanf("%lld",a+i);
	loop(i,0,n-1){
		e.emplace_back(l[i+1]-r[i],mp(-1,i));
		e.emplace_back(r[i+1]-l[i],mp(1,i));
	}
	loop(i,0,m){
		e.emplace_back(a[i],mp(0,i));
	}
	sort(e.begin(),e.end());
	for(auto i: e){
		if(i.S.F == -1){
			q.insert(mp(r[i.S.S+1]-l[i.S.S],i.S.S));
		}
		else if(i.S.F == 1){
			q.erase(mp(r[i.S.S+1]-l[i.S.S],i.S.S));
		}else if(!q.empty()){
			ans[q.begin()->second] = i.S.S+1;
			q.erase(q.begin());
		}
	}
	for(int i = 0; i < n-1; ++i){
		if(ans[i] == 0){
			printf("No\n");
			return ;
		}
	}
	printf("Yes\n");
	loop(i,0,n-1)printf("%d ",ans[i]);
}

int main(){
	int t = 1;
	//cin >> t;
	loop(i,1,t+1)solve(i);
}
