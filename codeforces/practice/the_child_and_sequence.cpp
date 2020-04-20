//https://codeforces.com/problemset/problem/438/D
// Code reffered from KAN
#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define ll long long int
using namespace std;
const ll N = 1e5 + 100;

pair<int,int> tree[N<<2];
ll sum[N<<2];
void update(int ind, int val, int node = 0, int start = 0, int end = N-1){
	if(start == end){
		tree[node] = make_pair(val,ind);
		sum[node] = val;
		return ;
	}
	((start+end>>1) >= ind)?update(ind,val,2*node+1,start,(start+end>>1)):update(ind,val,2*node+2,(start+end>>1)+1,end);
	tree[node] = max(tree[2*node+1],tree[2*node+2]);
	sum[node] = sum[2*node+1]+sum[2*node+2];
}

pair<int,int> getMax(int l, int r, int node = 0, int start = 0, int end = N-1){
	if(l > end || r < start)return pair<int,int>(-1,-1);
	if(l <= start && end <= r)return tree[node];
	return max(getMax(l,r,2*node+1,start,(start+end>>1)),getMax(l,r,2*node+2,(start+end>>1)+1,end));
}

ll getSum(int l, int r, int node = 0, int start = 0, int end = N-1){
	if(l > end || r < start)return 0;
	if(l <= start && end <= r)return sum[node];
	return getSum(l,r,2*node+1,start,(start+end>>1))+getSum(l,r,2*node+2,(start+end>>1)+1,end);
}

int main(){
	int n,a,m,op,r,l,k,x;
	scanf("%d%d",&n,&m);
	loop(i,0,n){
		scanf("%d",&a);
		update(i,a);
	}
	loop(i,0,m){
		scanf("%d%d%d",&op,&l,&r);
		if(op == 1)printf("%lld\n",getSum(l-1,r-1));
		else if(op == 2){
			scanf("%d",&x);
			pair<int,int> g = getMax(l-1,r-1);
			while(g.first >= x){
				update(g.second,g.first%x);
				g = getMax(l-1,r-1);
			}
		}else if(op == 3)update(l-1,r); //Note: l = index here and r = val 
	}
}