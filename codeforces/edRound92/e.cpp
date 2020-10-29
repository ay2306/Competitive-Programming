#include<bits/stdc++.h>
#define int long long
using namespace std;


pair<int,int> a,b;

pair<int,int> overlap(){
	pair<int,int> res;
	res.first = min(a.second,b.second) - max(a.first,b.first);
	res.second = max(a.second,b.second) - min(a.first,b.first);
	return res;
}

int cost(int x){
	auto res = overlap();
	if(x <= 0 || res.first >= x)return 0;
	if(res.second >= x)return x-res.first;
	return res.second-res.first+2*(x-res.second);
}

void solve(){
	int n,k;
	cin >> n >> k >> a.first >> a.second >> b.first >> b.second;
	auto res = overlap();
	if(res.first*n >= k)return void(cout << 0 << "\n");
	if(res.first > 0)k-=n*res.first;
	int ans = LLONG_MAX,covered = 0,cst=0;
	for(int i = 0; i < n; ++i){
		if(res.first > 0)k+=res.first;
		ans = min(ans, cst + cost(k-covered));
		cst += res.second - res.first;
		covered+=res.second;
	}
	cout << ans << "\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--)solve();
	return 0;
}
