#include<bits/stdc++.h>
using namespace std;

int main(){
    int t,n,m,arr[300][300],dx[]={-1,1,0,0},dy[]={0,0,1,-1};
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        int im = 0;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j){
                scanf("%d",arr[i]+j);
                im += (arr[i][j] > (i-1 >= 0) + (j-1 >= 0) + (i+1 < n) + (j+1 < m));
                arr[i][j] = (i-1 >= 0) + (j-1 >= 0) + (i+1 < n) + (j+1 < m);
            }
        printf(im ? "NO\n" : "YES\n");
        for(int i = 0; i < n && im == 0; ++i){
            for(int j = 0; j < m; ++j)printf("%d ",arr[i][j]);
            printf("\n");
        }
    }
    return 0;
}