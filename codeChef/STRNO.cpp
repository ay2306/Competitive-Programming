#include <bits/stdc++.h>
#define loop(i,a,b) for(int i=a;i<b;i++)

void solve(int test_case){
	int x,k;
	scanf("%d%d",&x,&k);
	int cnt = 0;
	for(int i = 2; i*i <= x; ++i){
		while(x%i == 0){
			x/=i;
			cnt++;
		}
	}
	if(x > 1)cnt++;
	printf("%d\n",cnt>=k);
}

int main(){
	// FAST
	int t = 1;
	scanf("%d",&t);
	loop(i,1,t+1)solve(i);
}
