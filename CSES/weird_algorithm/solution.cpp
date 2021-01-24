#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
	int n;
	scanf("%lld",&n);
	while(true){
		printf("%lld ",n);
		if(n == 1)break;
		if(n & 1) n = n * 3 + 1;
		else n >>= 1;
	}
	return 0;
}
