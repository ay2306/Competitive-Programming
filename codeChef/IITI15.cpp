#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define ll long long int
using namespace std;
const ll N = 3e4 + 100;

int K,n,Q;
ll arr[N],ans=0,res[N],l,r,curL=1,curR=0,tree[N<<2];
struct Query{
	int l, r, ind;
	Query(int L=0, int R=0, int IND=0):l(L),r(R),ind(IND){}
	bool operator<(const Query &rhs)const{
		if(l/K != rhs.l/K)return l < rhs.l;
		if(l/K & 1)return r < rhs.r;
		return r > rhs.r;
	}
}q[N];

void update(int ind, int val, int node = 0, int start = 0, int end = N-1){
	if(start == end){
		tree[node]+=val;
		return;
	}
	int mi = start+end >> 1;
	if(mi >= ind)update(ind,val,2*node+1,start,mi);
	else update(ind,val,2*node+2,mi+1,end);
	tree[node] = tree[2*node+1]+tree[2*node+2];
}

ll query(int l, int r, int node = 0, int start = 0, int end = N-1){
	if(r < l)return 0;
	if(l > end || r < start)return 0;
	if(l <= start && end <= r)return tree[node];
	return query(l,r,2*node+1,start,(start+end)>>1)+query(l,r,2*node+2,(start+end>>1)+1,end);
}

void coordinate_compression(){
	map<int,int> m;
	int a = 0;
	loop(i,0,n)m[arr[i]] = 1;
	for(auto &i: m)i.second=a++;
	loop(i,0,n)arr[i]=m[arr[i]];
}


void solve(int test_case){
	scanf("%d",&n);
	loop(i,0,n)scanf("%lld",arr+i);
	coordinate_compression();
	K = sqrt(n)+5;
	scanf("%d",&Q);
	loop(i,0,Q)scanf("%d%d",&q[i].l,&q[i].r),q[i].ind=i;
	sort(q,q+Q);
	loop(i,0,Q){	
		l = q[i].l-1;
		r = q[i].r-1;
		while(curL < l){
			if(arr[curL]!=0)ans-=query(0,arr[curL]-1);
			update(arr[curL],-1);
			curL++;
		}
		while(curL > l){
			curL--;
			if(arr[curL]!=0)ans+=query(0,arr[curL]-1);
			update(arr[curL],1);
		}
		while(curR < r){
			curR++;
			ans+=query(arr[curR]+1,n);
			update(arr[curR],1);
		}
		while(curR > r){
			ans-=query(arr[curR]+1,n);
			update(arr[curR],-1);
			curR--;
		}
		res[q[i].ind] = ans;
	}
	loop(i,0,Q)printf("%lld\n",res[i]);
}

int main(){
	int t = 1;
	// scanf("%d",&t);
	loop(i,1,t+1)solve(i);
}
