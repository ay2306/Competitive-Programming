/*
TESTCASES
5
1 2 3 4 5
(1) 1+ 15 = 16
(2) 3+ 14 = 17
(3) 6+ 12 = 18
(4) 10 + 9 = 19
(5) 15 + 5 = 20
-----------------
8
3 5 4 4 3 2 6 2
(1) 3 + 29 = 32
(2) 8 + 26 = 32
(3) 12 + 21 = 33
(4) 16 + 17 = 33
(5) 19 + 13 = 32
(6) 21 + 10 = 31
(7) 27 + 8 = 35
(8) 29 + 2 = 31
------------------
7
4 5 5 4 7 8 5
(1) 4 + 38 = 42
(2) 9 + 34 = 43
(3) 14 + 29 = 43
(4) 18 + 24 = 42
(5) 25 + 20 = 45
(6) 33 + 13 = 46
(7) 38 + 5 = 43
*/

#include<stdio.h>
#include<limits.h>

int main(){
    int testCases;
    scanf("%d",&testCases);
    int n,i,j,min_index,sum1,sum2,sum;
    int min;
    int *arr;
    while(testCases--){
        min = INT_MAX;
        sum = 0;
        sum1 = 0;
        sum2 = 0;
        scanf("%d",&n);
        arr = (int *)malloc(sizeof(int)*n);
        for(i = 0 ; i < n; i++){
            scanf("%d",&arr[i]);
            sum+=arr[i];
        }
        sum+=arr[0];
        min_index = 1;
        min = sum;
        for(i = 1; i < n; ++i){
            sum+=arr[i];
            sum-=arr[i-1];
            if(min>sum){
                min = sum;
                min_index = (i+1);
            }
        }
                printf("%d\n",min_index);
    }
return 0;

}
