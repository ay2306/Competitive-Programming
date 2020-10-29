#include<bits/stdc++.h>
using namespace std;

const int N = 1e6,MX = N+101;
int tree[MX<<2];

void update(int id, int val, int node = 1, int start = 0, int end = N){
	if(start == end)return void(tree[node]+=val);
	int mid = start + end >> 1;
	if(id <= mid)update(id,val,node<<1,start,mid);
	else update(id,val,node<<1|1,mid+1,end);
	tree[node] = tree[node<<1] + tree[node<<1|1];
}

int query(int l, int r, int node = 1, int start = 0, int end = N){
	if(l > end || r < start)return 0;
	if(l <= start && end <= r)return tree[node];
	int mid = start + end >> 1;
	return query(l,r,node<<1,start,mid)+query(l,r,node<<1|1,mid+1,end);
}

int32_t main(){
	int n,q;
	scanf("%d",&n);
	vector<int> arr(n+1);
	for(int i = 1; i <= n; ++i)scanf("%d",&arr[i]);
	for(int i = 1; i <= n; ++i)update(arr[i],1);
	scanf("%d",&q);
	while(q--){
		int u,x;
		scanf("%d%d",&u,&x);
		int val = arr[u];
		int index1 = query(0,val-1);
		update(val,-1);
		val+=x;
		arr[u] = val;
		int index2 = query(0,val-1);
		update(val,1);
		printf("%d\n",abs(index1-index2));
	}
	return 0;
}


/*
Initially we can represent our BST as

![image](https://s3.amazonaws.com/hr-assets/0/1602332778-2f67fb8d52-bst1.JPG)

When $2$ is added to node $3$, tree becomes this but in-order sequence do not change

![image](https://s3.amazonaws.com/hr-assets/0/1602332791-c13538950c-bst2.JPG)

When $7$ is subtracted from node $2$, tree becomes this and in-order sequence change, shifting index of Node $2$ by $1$

![image](https://s3.amazonaws.com/hr-assets/0/1602332802-41646a6194-bst3.JPG)

When $7$ is added to node $1$, tree becomes this but in-order sequence do not change

![image](https://s3.amazonaws.com/hr-assets/0/1602332809-deb9998c15-bst4.JPG)

When $8$ is added to node $2$, tree becomes this and in-order sequence change, shifting index of Node $2$ by $1$

![image](https://s3.amazonaws.com/hr-assets/0/1602332819-5a6cdad416-bst5.JPG)
*/