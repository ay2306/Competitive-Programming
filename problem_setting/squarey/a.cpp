#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	if(n < 1 || n > 1000)return 0;
	for(int i = 1; i <= n; ++i)printf("%d ",i*i);
	return 0;
}
