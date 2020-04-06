//https://codeforces.com/contest/1325/problem/E
#include <bits/stdc++.h>
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

// Constants
const ll N = 1e5 + 100;
ll MX = 0;
const ll inf = 1e9;
const double pi = acos(-1);

int a[N], dist[N], ans = inf, vis[N];
V<int> v[N],adj[N],start;
map<int,int> ind;
queue<P<int,PII>> q;
int n;
int c;
int main(){
	FAST
	cin >> n;
	// scanf("%d",&n);
	loop(i,0,n){
		// scanf("%d",a+i);
		cin >> a[i];
		MX = max(MX,1LL*a[i]);
	}
	MX = sqrt(MX);
	loop(i,0,n){
		int x = a[i];
		for(int j = 2; j <= sqrt(x); ++j){
			int cnt = 0;
			while(x%j == 0)x/=j,cnt++;
			if(cnt & 1)v[i].pb(j);
		}
		if(v[i].size() == 0 && x == 1){
			printf("1");
			return 0;
		}
		v[i].pb(x);
		if(v[i].size() == 1)v[i].pb(1);
		// printf("VALUE = %d ",a[i]);
		for(int j: v[i]){
			// printf("%d ",j);
			if(ind.find(j) == ind.end()){
				ind[j] = c;
				if(j <= MX){
					start.pb(c);
				}
				++c;
			}
		}
		// printf("\n");
		adj[ind[v[i][0]]].pb(ind[v[i][1]]);
		adj[ind[v[i][1]]].pb(ind[v[i][0]]);
	}
	for(int j: start){
		// printf("Started from j = %d\n",j);
		memset(vis,0,sizeof(vis));
		q.push(mp(0,mp(j,j)));
		while(q.size()){
			int dis = q.front().F;
			int u = q.front().S.F;
			int v = q.front().S.S;
			q.pop();
			if(vis[u])continue;
			vis[u] = 1;
			dist[u] = dis;
			bool metParent = false;
			for(int k: adj[u]){
				// printf("par = %d, k = %d\n",u,k);
				if(k != v || metParent){
					if(vis[k]){
						ans = min(ans,dist[u]+dist[k]+1);
					}else{
						q.push(mp(dist[u]+1,mp(k,u)));
					}
				}else{
					metParent = true;
				}
			}
		}
	}
	if(ans == inf)ans = -1;
	// printf("%d",ans);
	cout << ans;
}
