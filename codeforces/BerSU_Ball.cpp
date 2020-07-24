#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m,c,ans=0;
	vector<int> a,b;
	scanf("%d",&n);
	for(int i = 0; i < n; ++i){
		scanf("%d",&c);
		a.emplace_back(c);
	}
	scanf("%d",&m);
	for(int i = 0; i < m; ++i){
		scanf("%d",&c);
		b.emplace_back(c);
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	while(a.size() && b.size()){
		if(abs(a.back()-b.back()) <= 1){
			ans++;
			a.pop_back();
			b.pop_back();
		}
		else if(a.back() > b.back())a.pop_back();
		else b.pop_back();
	}
	return printf("%d",ans),0;

}
