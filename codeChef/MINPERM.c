#include<stdio.h>

int main(){
    int n;
    int i;
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        i = 1;
        if(n%2==0){
            while(i<=n){
                printf("%d %d ",(i+1),i);
                i+=2;
            }
        }else{
            while(i<(n-2)){
                printf("%d %d ",(i+1),i);
                i+=2;
            }
            printf("%d %d %d",(i+1),(i+2),i);
        }
    printf("\n");
    }
return 0;
}
