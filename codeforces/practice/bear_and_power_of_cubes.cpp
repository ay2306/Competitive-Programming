//https://codeforces.com/problemset/problem/679/B
#include<bits/stdc++.h>
#define cube(a) ((a)*(a)*(a))
using namespace std;

long long maximum_blocks, maximum_sum;

void cal(long long left, long long sum, long long blocks){
    if(left < 0)return;
    if(blocks > maximum_blocks)maximum_blocks = blocks, maximum_sum = sum;
    else if (blocks == maximum_blocks)maximum_sum = max(maximum_sum,sum);
    if(left == 0)return;
    long long a = cbrt(left);
    cal(left - cube(a), sum+cube(a), blocks+1);
    if(a >= 1)cal(cube(a) - 1 - cube(a-1), sum+cube(a-1), blocks+1);
}


int main(){
    long long x;
    scanf("%lld",&x);
    cal(x,0,0);
    return printf("%lld %lld",maximum_blocks,maximum_sum),0;
}