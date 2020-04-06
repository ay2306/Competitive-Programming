//https://codeforces.com/contest/1249/problem/D2
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
const ll N = 2e5 + 100;
const ll inf = 1e9;
const double pi = acos(-1);
int n,m;
V<pair<PII,int>> arr;
V<PII> starting[N];
V<PII> ending[N];
class MAXTREE{
	V<ll> tree,lazy;
public:
	MAXTREE(){
		tree.resize(N<<2,0);
		lazy.resize(N<<2,0);
	}
	void push(int node, int start, int end){
		tree[node] += lazy[node];
		if(start != end){
			lazy[2*node+1] += lazy[node];
			lazy[2*node+2] += lazy[node];
		}
		lazy[node] = 0;
	}
	ll operate(ll a1, ll a2){
		return max(a1,a2);
	}
	void update(int l, int r, ll val, int node = 0, int start = 0, int end = N-1){
		if(l > r)swap(l,r);
		if(lazy[node])push(node,start,end);
		if(l > end || r < start)return;
		if(l <= start && end <= r){
			lazy[node] = val;
			push(node,start,end);
			return;
		}
		update(l,r,val,2*node+1,start,(start+end>>1));
		update(l,r,val,2*node+2,(start+end>>1)+1,end);
		tree[node] = operate(tree[node*2+1],tree[2*node+2]);
	}
	ll query(int l, int r, int node = 0, int start = 0, int end = N-1){
		if(lazy[node])push(node,start,end);
		if(l > end || r < start)return 0LL;
		if(l <= start && end <= r){
			return tree[node];
		}
		return operate(query(l,r,2*node+1,start,(start+end>>1)),query(l,r,2*node+2,(start+end>>1)+1,end));
	}
};


void solve(int test_case){
	scanf("%d%d",&n,&m);
	arr.resize(n);
	MAXTREE s;
	loop(i,1,n+1)arr[i-1].second = i;
	for(auto &i : arr)scanf("%d%d",&i.first.first,&i.first.second);
	for(auto &i : arr){
		s.update(i.first.first,i.first.second,1);
		starting[i.first.first].pb(mp(i.first.second,i.second));
		ending[i.first.second].pb(mp(i.first.second,i.second));
	}
	multiset<PII,greater<PII>> ms;
	set<int> del;
	loop(i,1,N){
		for(auto j: starting[i])if(del.count(j.second) == 0)ms.insert(j);
		int mx = s.query(i,i);
		if(mx > m){
			int times = mx-m;
			loop(heheehe,0,times){
				int ind = ms.begin()->second;
				del.insert(ind);
				ms.erase(ms.begin());
				s.update(arr[ind-1].first.first,arr[ind-1].first.second,-1);
			}
		}
		for(auto j: ending[i]){
			auto it = ms.find(j);
			if(it != ms.end())ms.erase(it);
		}
	}
	printf("%d\n",(int)del.size());
	for(auto &i: del)printf("%d ",i);
}

int main(){
	// FILE_READ_OUT
	int t = 1;
	//cin >> t;
	loop(i,1,t+1)solve(i);
}
