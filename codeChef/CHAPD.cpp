#include<bits/stdc++.h>
using namespace std;
long long t,g,a,b;
int main(){
    scanf("%lld",&t);
    while(t--){
        scanf("%lld %lld",&a,&b);
        while(b > 1){
            g = __gcd(a,b);
            if(g == 1)break;
            while(b%g == 0)b/=g;
        }
        b == 1 ? printf("Yes\n"):printf("No\n");
    }
    return 0;
}
