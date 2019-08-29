#include<stdio.h>

int main(){
int t,n,q,c,a,b,j,i,check;
int arr [100][100];
int tmp[100];
scanf("%d",&t);
while(t--){
    //printf("T: %d\n",t);
    check = 1;
    scanf("%d%d",&n,&q);
    for(i = 0; i < n; ++i){
        for(j = 0; j < n; ++j){
            arr[i][j]=-1;
        }
    }
    for(i = 0; i < q; ++i){
        scanf("%d%d%d",&a,&b,&c);
        arr[a-1][b-1] = c;
        if(!((arr[a-1][b-1]==arr[b-1][a-1])||(arr[b-1][a-1]==(-1)))){
            check = 0;
        }
        if(a==b){
            if(c!=0)check = 0;
        }

    }

    if(check==1){
        printf("yes\n");
    }else{
        printf("no\n");
    }
}
return 0;
}
/*

A11 A12
A21 A22

0  1
A21 A22

ANSWER: YES

A11 A12 A13
A21 A22 A23
A31 A32 A33

A11 A12 A13
A21 0 1
A31 A32 A33


A11 A12 A13
A21 A22 A23
A31 A32 A33


A11 1 1
A21 A22 1
A31 A32 A33


*/
