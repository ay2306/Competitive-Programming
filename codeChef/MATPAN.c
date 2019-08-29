/*
CODECHEF: MATPAN
*/
#include <stdio.h>
int main(){
	long price[26];
	int tmp[26];
	char input[50000];
	long i,t,var,sum;
	scanf("%ld",&t);
	while(t--){
		sum = 0;
		for(i = 0; i < 26; i++){
			scanf("%ld",&price[i]);
			tmp[i] = 1;
			sum+=price[i];
		}
		scanf("%s",input);
		for(i  = 0; input[i]!='\0'; ++i){
			var  = (int)input[i];
			if(var > 96){
				var-=97;
			}else{
				var-=65;
			}
			//printf("\nCHAR: %c\tVAR:%d\tPRICE:%d\tVAR*PRICE: %d",input[i],var,price[var],(tmp[var]*price[var]));
			sum-=(tmp[var]*price[var]);
			tmp[var] = 0;
		}
		printf("%ld\n",sum);
	}
}
