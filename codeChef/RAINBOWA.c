
/*
CODECHEF: RAINBOWA
1 2 3 4 5 6 7 7 6 5 4 3 2 1
*/
#include <stdio.h>
int main(){
	int a[100],t,reverse,i,n,ok;
	scanf("%d",&t);
	while(t--){
		ok = 1;
		reverse = 0;
		scanf("%d",&n);
		for(i = 0; i < n; ++i){
			scanf("%d",&a[i]);
			if(a[i]!=1)ok = 0;
			if(i>0){
				if(((a[i]==a[i-1])||(a[i]==a[i-1]+1))&&(reverse==0)){
					continue;
				}
				else if((a[i-1]==a[i]+1)||(a[i]==a[i])){
					if(reverse==0){
						if(a[i-1]!=7){
							ok = 0;
						}
					}
					reverse = 1;
				}
				else{
					ok = 0;
				}
			}
		}
		if(ok){
			printf("yes");
		}
		if(!ok){
			printf("no");
		}
	}
	
}