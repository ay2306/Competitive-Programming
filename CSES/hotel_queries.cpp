#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+100;
int arr[N];
int tree[N<<2];
int n,m,a;
void build(int node = 0, int start = 0, int end = n-1){
	if(start == end){
		tree[node] = arr[start];
		return;
	}
	build(node*2 +1,start,(start+end>>1));
	build(node*2 +2,(start+end>>1)+1,end);
	tree[node] = max(tree[node*2+1],tree[node*2+2]);
}

void update(int ind, int val, int node = 0, int start = 0, int end = n-1){
	if(start == end){
		arr[start]-=val;
		tree[node] = arr[start];
		return;
	}
	if((start+end >> 1) >= ind)update(ind,val,node*2+1,start,(start+end>>1));
	else update(ind,val,node*2+2,(start+end>>1)+1,end);
	tree[node] = max(tree[node*2+1],tree[node*2+2]);
}

int query(int l, int r, int node = 0, int start = 0, int end = n-1){
	if(l > end || r < start)return 0;
	if(l <= start && end <= r)return tree[node];
	int p1 = query(l,r,node*2+1,start,(start+end>>1));
	int p2 = query(l,r,node*2+2,(start+end>>1)+1,end);
	return max(p1,p2);
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n; ++i)scanf("%d",arr+i);
	build();
	while(m--){
        scanf("%d",&a);
		int lo = 0;
		int hi = n-1;
		int ans = -1;
		int mi;
		while(lo <= hi){
			mi = lo+hi >> 1;
			int v1 = query(lo,mi);
			if(v1 >= a){
				hi = mi-1;
				ans = mi;
			}else if(mi+1 <= hi){
				v1 = query(mi+1,hi);
				if(v1 >= a){
					lo = mi+1;
					ans = mi;
				}else{
					lo = 1;
					hi = 0;
				}
			}else{
				lo = 1;
				hi = 0;
			}
		}
		if(ans != -1)update(ans,a);
		printf("%d ",ans+1);
	}
    return 0;
}