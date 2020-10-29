#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d%d",&n,&k);
        int total = n + n + k;
        for(int i = 1; i <= n && total; ++i)
            for(int j = i + 1; j <= n && total; j++, total--)printf("%d %d\n",i,j);
    }
    return 0;
}