#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	if(n == 2 || n == 3)return printf("NO SOLUTION"), 0;
	int i = 1, j = n/2+1;
	for(int k = 0; k < n; ++k){
		if(k&1)printf("%d ",i++);
		else printf("%d ",j++);
	}
	return 0;
}
