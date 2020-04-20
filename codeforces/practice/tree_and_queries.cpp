//https://codeforces.com/contest/375/problem/D
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

// Constants
const ll N = 1e5 + 100;
const ll inf = 1e9;
const double pi = acos(-1);

V<pair<int,int>> q[N];
int col[N], sub[N], tree[(N+1)<<2],cnt[N],n,m,a,b,ans[N];
V<int> g[N];
map<int,int> f[N];

void update(int ind, int val, int node = 0, int start = 0, int end = N){
	if(ind == 0)return;
	if(start == end){tree[node]=max(0,tree[node]+=val);return;}
	if(ind <= (start+end >> 1))update(ind,val,2*node+1,start,start+end>>1);
	else update(ind,val,2*node+2,((start+end)>>1)+1,end);
}

int query(int l, int r, int node = 0, int start = 0, int end = N){
	if(r < l || l > end || r < start)return 0;
	if(l <= start && end <= r)return tree[node];
	return query(l,r,2*node+1,start,(start+end>>1))+query(l,r,2*node+2,((start+end)>>1)+1,end);
}

int initD(int s, int p = -1){
	sub[s] = 1;
	for(auto &i: g[s])if(i != p)sub[s]+=initD(i,s);
	return sub[s];
}

void dfs(int s = 1, int p = -1, bool valid = true){
	int bigChild = -1, mx = -1;
	for(auto &i: g[s]){
		if(i != p && sub[i] > mx)mx=sub[i],bigChild = i;
	}
	if(bigChild != -1){
		dfs(bigChild,s,true);
		swap(f[bigChild],f[s]);
	}
	for(auto &i: g[s]){
		if(i == p || i == bigChild)continue;
		dfs(i,s,false);
		for(auto &j: f[i]){
			update(f[s][j.first],-1);
			f[s][j.first]+=j.second;
			update(f[s][j.first],1);
		}
	}
	update(f[s][col[s]],-1);
	f[s][col[s]]++;
	update(f[s][col[s]],1);
	for(auto &i: q[s]){
		ans[i.second] = query(i.first,N);
	}
	if(valid){
		update(f[s][col[s]],-1);	
		f[s][col[s]]--;
		update(f[s][col[s]],1);	
		for(auto &i: g[s]){
			if(i == p || i == bigChild)continue;
			for(auto &j: f[i]){
				update(f[s][j.first],-1);
				f[s][j.first]-=j.second;
				update(f[s][j.first],1);
			}
		}
		update(f[s][col[s]],-1);	
		f[s][col[s]]++;
		update(f[s][col[s]],1);	
	}
}

void solve(int test_case){
	scanf("%d%d",&n,&m);
	loop(i,1,n+1)scanf("%d",col+i);
	loop(i,1,n){
		scanf("%d%d",&a,&b);
		g[a].pb(b);
		g[b].pb(a);
	}
	loop(i,0,m){
		scanf("%d%d",&a,&b);
		q[a].pb(b,i);
	}
	// loop(i,1,n+1)sort(all(q[i]));
	initD(0);
	dfs();
	loop(i,0,m)printf("%d ",ans[i]);
}

int main(){
	int t = 1;
	//cin >> t;
	loop(i,1,t+1)solve(i);
}
