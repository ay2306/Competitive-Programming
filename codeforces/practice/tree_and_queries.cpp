#include<bits/stdc++.h>
using namespace std;
const int K = 340, N = 1e5+10;

inline int read(){
	int x; char c;
	while((c=getchar()) < '0' || c > '9');
	for(x=c-'0';(c=getchar()) >= '0' && c <= '9';)x=x*10+c-'0';
	return x;
}

inline void out(int x, char end = ' ',bool first = true){
	if(x/10)out(x/10,' ',false);
	putchar(x%10+'0');
	if(first)putchar(end);
}

inline int64_t gilbertOrder(int x, int y, int pow, int rotate) {
	if (pow == 0) {
		return 0;
	}
	int hpow = 1 << (pow-1);
	int seg = (x < hpow) ? (
		(y < hpow) ? 0 : 3
	) : (
		(y < hpow) ? 1 : 2
	);
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	int64_t subSquareSize = int64_t(1) << (2*pow - 2);
	int64_t ans = seg * subSquareSize;
	int64_t add = gilbertOrder(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}

class SegmentTree{
	int tree[N<<2];
public:
	SegmentTree(){
		memset(tree,0,sizeof(tree));
	}
	void update(int id, int val, int node = 1, int start = 0, int end = N-1){
		if(start == end){
			tree[node] += val;
			return;
		}
		int mid = start+end >> 1;
		if(id <= mid)update(id,val,node<<1,start,mid);
		else update(id,val,node<<1|1,mid+1,end);
		tree[node] = tree[node<<1]+tree[node<<1|1];
	}
	int query(int l, int r, int node = 1, int start = 0, int end = N-1){
		if(l > end || r < start)return 0;
		if(l <= start && end <= r)return tree[node];
		int mid = start + end >> 1;
		int p1 = query(l,r,node<<1,start,mid);
		int p2 = query(l,r,node<<1|1,mid+1,end);
		return p1+p2;
	}
}s;

struct query{
	int l,r,ind,freq;
	query(){}
	int64_t ord;
	void cal(){
		ord = gilbertOrder(l,r,21,0);
	}
	bool operator<(const query &rhs)const {
		// if(l/K != rhs.l/K)return l < rhs.l;
		// if(l/K &1)return r > rhs.r;
		// return r < rhs.r;
		return ord < rhs.ord;
	}
}q[N];
vector<int> g[N];
int pos[N],sub[N],a[N],arr[N],t,Q,n,x,y,ans[N],curL=1,curR=0;
int color_frequency[N],color_frequency_frequency[N];

void dfs(int s = 1, int p = -1){
	pos[s] = t;
	sub[s] = 1;
	arr[t++] = s;
	for(int &i: g[s]){
		if(i == p)continue;
		dfs(i,s);
		sub[s] += sub[i];
	}
}

void add(int i){
	int col = a[i];
	auto &cf = color_frequency;
	if(cf[col])s.update(cf[col],-1);
	cf[col]++;
	s.update(cf[col],1);
}

void remove(int i){
	int col = a[i];
	auto &cf = color_frequency;
	if(cf[col])s.update(cf[col],-1);
	cf[col]--;
	if(cf[col])s.update(cf[col],1);
}

int main(){
	n = read();
	Q = read();
	for(int i = 1; i <= n; ++i)scanf("%d",a+i);
	for(int i = 1; i < n; ++i){
		x = read();
		y = read();
		g[x].emplace_back(y);
		g[y].emplace_back(x);
	}
	dfs(1);
	for(int i = 0; i < Q; ++i){
		x = read();
		y = read();
		q[i].l = pos[x];
		q[i].r = pos[x]+sub[x]-1;
		q[i].ind = i;
		q[i].freq = y;
		q[i].cal();
	}
	sort(q,q+Q);
	for(int index = 0; index < Q; ++index){
		int L = q[index].l, R = q[index].r, freq = q[index].freq;
		while(curL > L)add(arr[--curL]);
		while(curR < R)add(arr[++curR]);
		while(curL < L)remove(arr[curL++]);
		while(curR > R)remove(arr[curR--]);
		ans[q[index].ind] = s.query(q[index].freq,N-1);
	}
	// for(int index = 0; index < Q; ++index)printf("%d\n",ans[index]);
	for(int index = 0; index < Q; ++index)out(ans[index],'\n');
	return 0;
}
