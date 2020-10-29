#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,e = 0,ans = 0;
    scanf("%d%d",&a,&b);
    ans = a;
    while(a >= b){
        ans += (a / b);
        a = a/b + a % b;
    }
    printf("%d",ans);
    return 0;
}