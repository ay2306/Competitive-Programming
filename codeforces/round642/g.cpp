#include<bits/stdc++.h>
using namespace std;

int main(){
	multiset<pair<long long,int>> X,Y;
	int n,p1,p2;
	scanf("%d",&n);
	long long x,y,mx = LLONG_MIN;
	for(int i = 1; i <= n; ++i){
		scanf("%lld%lld",&x,&y);
		long long a = x+y,b=x-y;
		X.emplace(x+y,i);
		Y.emplace(x-y,i);
		x = a, y = b;
		if(abs(X.begin()->first-x) > mx){
			mx = abs(X.begin()->first-x);
			p1 = X.begin()->second;
			p2 = i;
		}
		if(abs(prev(X.end())->first-x) > mx){
			mx = abs(prev(X.end())->first-x);
			p1 = prev(X.end())->second;
			p2 = i;
		}
		if(abs(Y.begin()->first-y) > mx){
			mx = abs(Y.begin()->first-y);
			p1 = Y.begin()->second;
			p2 = i;
		}
		if(abs(prev(Y.end())->first-y) > mx){
			mx = abs(prev(Y.end())->first-y);
			p1 = prev(Y.end())->second;
			p2 = i;
		}
		printf("%d %d\n",p1,p2);
	}
	return 0;
}