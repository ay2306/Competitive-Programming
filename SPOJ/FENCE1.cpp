#include<bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
int main(){
    while(1){
        double l;
        scanf("%lf",&l);
        if(l < 0.9)break;
        printf("%.2lf\n",(l*l)/(2*pi));
    }
    return 0;
}