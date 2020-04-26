//https://codeforces.com/contest/877/problem/E
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+100;
template<class T, int SZ>
struct SegmentTree{
	int tree[SZ<<1],lazy[SZ<<2];
	SegmentTree(){
		memset(tree,0,sizeof(tree));
		memset(lazy,0,sizeof(lazy));
	}
	void update(int l, int r, int node = 1, int start = 0, int end = SZ-1){
		if(lazy[node]){
			tree[node] = (end-start+1)-tree[node];
			if(start != end){
				lazy[node<<1]^=1;
				lazy[node<<1|1]^=1;
			}
			lazy[node] = 0;
		}
		if(l > end || r < start)return;
		if(l <= start && end <= r){
			tree[node] = (end-start+1)-tree[node];
			if(start != end){
				lazy[node<<1]^=1;
				lazy[node<<1|1]^=1;
			}
			return;
		}
		int mid = start + end >> 1;
		update(l,r,node<<1,start,mid);
		update(l,r,node<<1|1,mid+1,end);
		tree[node] = tree[node << 1]+tree[node << 1 | 1];
	}
	long long  query(int l, int r, int node = 1, int start = 0, int end = SZ-1){
		if(lazy[node]){
			tree[node] = (end-start+1)-tree[node];
			if(start != end){
				lazy[node<<1]^=1;
				lazy[node<<1|1]^=1;
			}
			lazy[node] = 0;
		}
		if(l > end || r < start)return 0;
		if(l <= start && end <= r)return tree[node];
		int mid = start + end >> 1;
		long long  p1 = query(l,r,node<<1,start,mid);
		long long  p2 = query(l,r,node<<1|1,mid+1,end);
		return p1+p2;
	}
};
vector<int> g[N];
int pos[N],sub[N],en[N];
int dfs(int s = 1, int p = 0){
	static int t = 0;
	pos[s] = t++;
	sub[s] = 1;
	for(int& i: g[s]){
		if(i != p)sub[s]+=dfs(i,s);
	}
	en[s] = t-1;
	return sub[s];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	SegmentTree<long long,N> tree;
	int a,b,n;
	cin >> n;
	for(int i = 2; i <= n; ++i){
		cin >> a;
		g[a].emplace_back(i);
	}
	dfs();
	for(int i = 1; i <= n; ++i){
		cin >> a;
		if(a)tree.update(pos[i],pos[i]);
	}
	int q;
	cin >> q;
	while(q--){
		string k;
		cin >> k >> a;
		if(k[0] == 'g'){
			cout << tree.query(pos[a],en[a]) << "\n";
		}else{
			tree.update(pos[a],pos[a]+sub[a]-1);
		}
	}
	return 0;
}