//https://codeforces.com/contest/359/problem/D
#include<bits/stdc++.h>
using namespace std;
const int N = 3e5+10;
int g[20][N],arr[N],logs[N+1];
int n;
void build(){
	logs[1] = 0;
	for(int i = 2; i <= n; ++i){
		logs[i] = 1+logs[i>>1];
	}
	for(int i = 0; i <= logs[n]; ++i){
		int cur = 1 << i;
		for(int j = 0; j + cur <= n; ++j){
			if(cur == 1)g[i][j] = arr[j];
			else g[i][j] = __gcd(g[i-1][j],g[i-1][j+cur/2]);
		}
	}
}

int query(int l, int r){
	int p = logs[r - l + 1];
    int pLen = 1 << p; // 2^p
    return __gcd(g[p][l], g[p][r - pLen + 1]);
}

int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; ++i)scanf("%d",arr+i);
	build();
	int len = 1;
	vector<int> col[N];
	for(int i = 0; i < n; ){
		int lo = 0;
		int hi = i-1;
		int ans = n;
		while(lo <= hi){
			int mi = lo+hi >> 1;
			int val = query(mi,i);
			// cout << val << "\n";
			if(val == arr[i]){
				ans = mi;
				hi = mi-1;
			}else lo = mi+1;
		}
		int left = min(ans,i);
		lo = i+1;
		hi = n-1;
		ans = 0;
		while(lo <= hi){
			int mi = lo+hi >> 1;
			int val = query(i,mi);
			if(val == arr[i]){
				ans = mi;
				lo = mi+1;
			}else hi = mi-1;
		}
		int right = max(ans,i);
		if(len < right-left+1){
			len = right-left+1;
		}
		if(len == right-left+1){
			col[len].push_back(left);
		}
		i = right+1;
	}

	printf("%d %d\n",(int)col[len].size(),len-1);
	for(auto &i: col[len])printf("%d ",i+1);
}