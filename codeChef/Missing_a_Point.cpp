#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,x = 0, y = 0,a,b;
        scanf("%d",&n);
        for(int i = 0; i < 4*n - 1; ++i){
            scanf("%d%d",&a,&b);
            x^=a;
            y^=b;
        }
        printf("%d %d\n",(int)x,(int)y);
    }
    return 0;
}