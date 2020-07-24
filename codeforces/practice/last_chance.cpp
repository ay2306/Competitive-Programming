//https://codeforces.com/contest/137/problem/E
#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int mx,base;
class Tree{
	int *tree;
public:
	Tree(){
		tree = new int[mx<<3];
		fill(tree,tree+(mx << 3),inf);
	}	
	void update(int idx, int val, int node = 1, int start = 0, int end = mx){
		if(start == end){
			tree[node] = min(tree[node],val);
			return;
		}
		int mid = start + end >> 1;
		if(idx <= mid)update(idx,val,node<<1,start,mid);
		if(idx > mid)update(idx,val,node<<1|1,mid+1,end);
		tree[node] = min(tree[node<<1],tree[node<<1|1]);
	}
	int query(int l, int r, int node = 1, int start = 0, int end = mx){
		if(l > end || r < start)return INT_MAX;
		if(l <= start and end <= r)return tree[node];
		int mid = start + end >> 1;
		return min(query(l,r,node<<1,start,mid),query(l,r,node<<1|1,mid+1,end));
	}
};


int main(){
	string a;
	cin >> a;
	int len = a.size();
	base = 2*len + 1;
	mx = 5*len;
	Tree s;
	int ans = -1, v = 0, c = 0, cnt = 0;
	function<int(char)> f = [](char a)->int{
		a = tolower(a);
		return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u';
	};
	s.update(base,-1);
	for(int i = 0; i < len; ++i){
		if(f(a[i]))v++;
		else c++;
		int val = v - 2 * c;
		int id = s.query(val+base,mx);
		int sub =  i - id;
		if(sub == ans)cnt++;
		if(sub > ans)ans = sub,cnt = 1;
		s.update(val+base,i);
	}
	if(cnt == 0)return cout << "No solution",0;
	return cout << ans << " " << cnt , 0;
}
