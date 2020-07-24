#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,a;
	scanf("%d",&n);
	map<int,vector<int>> m;
	vector<int> b(n);
	for(int i = 0; i < n; ++i){
		scanf("%d%d",&a,&b[i]);
		m[b[i]].emplace_back(a);
	}
	for(auto& i: m)sort(i.second.begin(),i.second.end());
	long long ans = 0;
	for(int i = 0; i < n; ++i){
		ans += m[b[i]].back() * 1LL * (i+1);
		m[b[i]].pop_back();
	}
	return printf("%lld",ans) , 0;
}
