#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int tree[N << 2],n,coord = 1,ans;

void update(int id, int node = 1, int start = 1, int end = 2*n){
	if(start == end){
		tree[node]++;
		return;
	}
	int mid = start + end >> 1;
	if(id <= mid)update(id,node<<1,start,mid);
	else update(id,node<<1|1,mid+1,end);
	tree[node] = tree[node<<1]+tree[node<<1|1];
}

int query(int l, int r, int node = 1, int start = 1, int end = 2*n){
	if(l > end || r < start)return 0;
	if(l <= start && end <= r)return tree[node];
	int mid = start+ end >> 1;
	return query(l,r,node<<1,start,mid)+query(l,r,node<<1|1,mid+1,end);
}

int main(){
	scanf("%d",&n);
	vector<pair<int,int>> a(n);
	map<int,int> coordinate_compress;
	for(auto& [x,y]: a)scanf("%d%d",&x,&y);
	for(auto& [x,y]: a)coordinate_compress[x]=1,coordinate_compress[y]=1;
	for(auto &i: coordinate_compress)i.second = coord++;
	for(auto &[x,y]: a)x=coordinate_compress[x],y=coordinate_compress[y];
	sort(a.begin(),a.end());
	for(auto &[x,y]: a){
		if(query(y,2*n) > 0)ans++;
		update(y);
	}
	return printf("%d",ans),0;
}
