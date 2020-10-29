#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int n,m;
	cin >> n >> m;
	vector<pair<int,pair<int,int>>> c(n);
	for(int i = 1; i <= n; ++i){
		cin >> c[i-1].first;
		c[i-1].second = make_pair(0,i);
	}
	while(m--){
		int x,y,z;
		cin >> x >> y >> z;
		c.emplace_back(z,make_pair(x,y));
	}
	sort(c.begin(),c.end());
	vector<int> p(n+1);
    iota(p.begin(),p.end(),0);
    function<int(int)> fp = [&](int x)->int{
        if(p[x] != x)p[x] = fp(p[x]);
        return p[x];
    };
    auto u = [&](int a, int b){
        p[fp(a)] = fp(b);
    };
	int ans = 0;
	for(auto i: c){
		int x,y,z;
		tie(x,y) = i.second;
		z = i.first;
		if(fp(x) == fp(y))continue;
		ans += z;
		u(x,y);
	}
	cout << ans << "\n";
	return 0;
}
