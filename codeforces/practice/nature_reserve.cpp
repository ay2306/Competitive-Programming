#include<bits/stdc++.h>
#define ld long double
using namespace std;
template<class T>
T abs(T a){
    if(a < (T)0)return -a;
    return a;
}

vector<pair<ld,ld>> arr;
bool valid(__float128 mi){
    __float128 left = -2e15, right = 2e15;
    for(auto &[x,y] : arr){
        __float128 dy = abs(abs((__float128)y)-mi);
        if(dy*dy - mi*mi > 1e-9){
            left = 1,right=0;
            break;
        }
        __float128 dx = sqrtl(mi*mi - dy*dy);
        left = max(left,x-dx),right = min(right,x+dx);
    }
    if(right-left > 1e-9)return true;
    return false;
}

int n;
int main(){
    scanf("%d",&n);
    arr.resize(n);
    for(auto& [x,y] : arr)scanf("%Lf %Lf",&x,&y);
    int neg = 0,pos = 0;
    for(auto& [x,y] : arr)neg+=(y<0),pos+=(y>0);
    if(neg*pos != 0)return printf("-1"),0;
    __float128 ans = 2e15;
    __float128 lo = 0;
    __float128 hi = ans;
    bool arith = true;
    // function<__float128(__float128,__float128)> getMid;
    if(valid(1.00000000000000))arith = false;
    // if(arith)printf("EXPECTED GREATER THAN 1\n"); 
    for(int steps = 200; steps > 0 && hi-lo > 1e-9; --steps){
        __float128 mi = (lo+hi)/2;
        // if(arith)mi = sqrtl(lo*hi);
        if(valid(mi))ans = mi, hi = mi;
        else lo = mi;
    }
    return printf("%.12Lf\n",(ld)ans),0;
}