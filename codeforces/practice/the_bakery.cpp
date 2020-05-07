//https://codeforces.com/contest/834/problem/D
#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const long long N = 40000 + 100;
const long long inf = 1e9;

ll dp[60][N];
int arr[N]; 

class SegmentTree{
    ll tree[(N+15)<<2], lazy[(N+15) << 2];
public:
    void build(int part, int node = 1, int start = 1, int end = N-1){
		lazy[node] = 0;
		if(start == end){
			tree[node] = dp[part][start-1];
			return;
		}
		int mid = start + end >> 1;
		build(part,node << 1,start,mid);
		build(part,node << 1 | 1, mid+1, end);
		tree[node] = max(tree[node<<1],tree[node<<1|1]);
	}
	void update(int l, int r, int val, int node = 1, int start = 1, int end = N-1){
		if(lazy[node]){
			tree[node]+=lazy[node];
			if(start != end){
				lazy[node << 1] += lazy[node];
				lazy[node << 1 | 1] += lazy[node];
			}
			lazy[node] = 0;
		}
		if(l > end || r < start)return ;
		if(l <= start && end <= r){
			tree[node] += val;
			if(start != end){
				lazy[node << 1] += val;
				lazy[node << 1 | 1] += val;
			}
			return ;
		}
		int mid = start + end >> 1;
		update(l,r,val,node<<1,start,mid);
		update(l,r,val,node<<1|1,mid+1,end);
		tree[node] = max(tree[node<<1],tree[node<<1|1]);
	}
	ll query(int l, int r, int node = 1, int start = 1, int end = N-1){
		if(lazy[node]){
			tree[node]+=lazy[node];
			if(start != end){
				lazy[node << 1] += lazy[node];
				lazy[node << 1 | 1] += lazy[node];
			}
			lazy[node] = 0;
		}
		if(l > end || r < start)return LLONG_MIN;
		if(l <= start && end <= r)return tree[node];
		int mid = start + end >> 1;
		ll r1 = query(l,r,node<<1,start,mid);
		ll r2 = query(l,r,node<<1|1,mid+1,end);
		return max(r1,r2);
	}
};


inline int read(){
    int x;
    char c;
    while((c=getchar()) < '0' || c > '9');
    for(x = c-'0'; (c = getchar())>= '0' && c <= '9';)x=x*10+c-'0';
    return x;
}


int main(){
	int n = read();
    int k = read();
	for(int i = 1; i <= n; ++i)arr[i] = read();
	for(int i = 0; i <= n; ++i)
        for(int j = 0; j <= k; ++j)dp[j][i] = -inf;
    dp[0][0] = 0;
	SegmentTree s;
	s.build(0);
	for(int pack = 1; pack <= k; ++pack){
		unordered_map<int,int> prv;
		for(int i = 1; i <= n; ++i){
			s.update(prv[arr[i]]+1,i,1);
			prv[arr[i]] = i;
			dp[pack][i] = s.query(1,i);
		}
		s.build(pack);
	}
	return cout << dp[k][n],0;
}