#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,x;
	scanf("%d",&n);
	long long s = n*1LL*(n+1)/2;
	n--;
	while(n--){
		scanf("%d",&x);
		s-=x;
	}
	printf("%lld",s);
	return 0;
}
