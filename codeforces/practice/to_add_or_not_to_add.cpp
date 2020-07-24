//https://codeforces.com/problemset/problem/231/C
#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int n,k;
	cin >> n >> k;
	vector<int> a(n);
	for(int &i: a)cin >> i;
	sort(a.begin(),a.end());
	int lo = 0, hi = n, ans = 0, el = -1;
	while(lo <= hi){
		int s = 0,mid = lo + hi >> 1;
		for(int i = 0; i < n; ++i){
			s+=a[i];
			if(i < mid - 1)continue;
			if(i >= mid)s-=a[i-mid];
			int cost = abs(a[i] * mid - s);
			if(cost <= k){
				ans = mid, el = a[i];
				break;
			}
		}
		if(ans == mid)lo=mid+1;
		else hi = mid-1;
	}
	return cout << ans << " " << el , 0;
}