#include<bits/stdc++.h>
using namespace std;

int main(){
    long double n,ans = 1,i = 1, k = 1;
    cin >> n;
    while(i <= n){
        k/=i++;
        ans+=k;
    }
    return printf("%.20Lf",ans),0;
}