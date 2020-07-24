//https://codeforces.com/contest/220/problem/C
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+5,inf = 1e6;
class SegmentTree{
	vector<int> lazy,tree;
public:
	SegmentTree(){}
	SegmentTree(int N):lazy(N<<2,0),tree(N<<2,inf){}
	void push(int node, int start, int end){
		tree[node]+=lazy[node];
		if(start != end){
			lazy[node<<1]+=lazy[node];
			lazy[node<<1|1]+=lazy[node];
		}
		lazy[node]=0;
	}
	void update(int l, int r, int val, int node = 1, int start = 1, int end = N){
		// cout << start << " " << end << " " << l << " " << r << "\n";
		if(lazy[node])push(node,start,end);
		if(l > end || r < start)return;
		if(l <= start && end <= r){
			// cout << "EXIT " << start << " " << end << " " << l << " " << r << "\n";
			lazy[node]+=val;
			push(node,start,end);
			return;
		}
		int mid = start + end >> 1;
		update(l,r,val,node<<1,start,mid);
		update(l,r,val,node<<1|1,mid+1,end);
		tree[node] = min(tree[node<<1],tree[node<<1|1]);
		// cout << "EXIT " << start << " " << end << " " << l << " " << r << "\n";
	}			
	int query(int l, int r, int node = 1, int start = 1, int end = N){
		if(lazy[node])push(node,start,end);
		if(l > end || r < start)return INT_MAX;
		if(l <= start && end <= r)return tree[node];
		int mid = start + end >> 1;
		return min(query(l,r,node<<1,start,mid),query(l,r,node<<1|1,mid+1,end));
	}			
};

int32_t main(){
	int n;
	scanf("%lld",&n);
	SegmentTree inc(N+3),dec(N+3);
	int a[N],b[N],ind[N];
	for(int i = 1; i <= n; ++i){
		scanf("%lld",a+i);
		ind[a[i]]=i;
	}
	map<int,vector<int>> toEnd,cross;
	for(int i = 1; i <= n; ++i){
		scanf("%lld",b+i);
		if(i <= ind[b[i]]){
			inc.update(i,i,-inf);
			inc.update(i,i,ind[b[i]]-i-1);
			// after i+1 moves it will move to the back of the array will be start decreasing
			toEnd[i].emplace_back(i);
			// after i+1 moves to end and then after n-ind[b[i]] it will enter inc again
			cross[i+n-ind[b[i]]].emplace_back(i);
		}else{
			dec.update(i,i,-inf);
			dec.update(i,i,i - ind[b[i]] + 1);	
			// after i+1 moves it will move to the back of the array will be start decreasing
			toEnd[i].emplace_back(i);
			// i-ind[b[i]] it will enter inc again
			cross[i-ind[b[i]]].emplace_back(i);
		}
	}
	for(int moves = 0; moves < n; ++moves){
		//First find all element which were going to last
		for(auto& i: toEnd[moves]){
			//this element was at start to must be in positive
			// printf("moves = %d, toEnd = %d\n",moves,i);
			int posVal = inc.query(i,i);
			//make it zero
			inc.update(i,i,-posVal);
			//make it infinite
			inc.update(i,i,inf);
			//set its value in dec
			int decVal = dec.query(i,i);
			dec.update(i,i,-decVal);
			dec.update(i,i,n-ind[b[i]]+1);
		}
		//Now consider those which were crossing
		for(auto& i: cross[moves]){
			//this element must be in decreasing
			// printf("move = %d, cross = %d\n",moves,i);
			dec.update(i,i,inf);
			int posVal = inc.query(i,i);
			//make it 1
			inc.update(i,i,-posVal - 1);
		}
		inc.update(1,n,1);
		dec.update(1,n,-1);
		printf("%d\n",min(inc.query(1,n),dec.query(1,n)));
	}
	return 0;
} 