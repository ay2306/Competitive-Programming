#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
	int t;
	scanf("%lld",&t);
	while(t--){
		int row,col;
		scanf("%lld%lld",&row,&col);
		int outer = max(row,col);
		int ans = (outer-1)*(outer-1);
		if(outer & 1){
			if(outer == col)ans+=2*outer-row;
			else ans += col;
		}else{
			if(outer == row)ans+=2*outer-col;
			else ans+=row;
		}
		printf("%lld\n",ans);

	}	
	return 0;
}
