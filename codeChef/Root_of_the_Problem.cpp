#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,sum=0,a,b;
        scanf("%d",&n);
        while(n--){
            scanf("%d%d",&a,&b);
            sum+=b-a;
        }
        printf("%d\n",-sum);
    }
    return 0;
}