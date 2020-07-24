#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+100;
int arr[N];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,k;
		scanf("%d %d",&n,&k);
		for(int i = 0; i < n; ++i)scanf("%d",arr+i);
		sort(arr,arr+n);
		int ans = 0, lo = 0, hi = arr[n-1];
		while(lo <= hi){
			int cnt = 0, prev = -arr[n-1]-1, mid = lo + hi >> 1;
			for(int i = 0; i < n; ++i)
				if(arr[i]-prev >= mid)cnt++,prev=arr[i];
			if(cnt >= k)ans = mid, lo = mid + 1;
			else hi = mid - 1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
