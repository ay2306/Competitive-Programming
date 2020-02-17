#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include<cmath>
#include <cassert>
#include<spoj.h>
using namespace std;
typedef long long int ll;
ll a[100100],b[100100],n,k;

int main()
{
    spoj_init();
    fscanf(spoj_p_in,"%lld %lld",&n,&k);
    for(int i = 0; i < n; ++i)fscanf(spoj_p_in,"%lld",a+i);
    fscanf(spoj_t_out,"%lld",&b[0]);
    int pos;
    fscanf(spoj_p_out,"%lld",&pos);
    if(pos == -1 && b[0] == -1)return SPOJ_RV_POSITIVE;
    else if(pos == -1)spoj_assert(1==0);
    for(int i = 1; i < n; ++i)fscanf(spoj_t_out,"%lld",b+i);
    ll sum = 0;
    for(int i = 0; i < n; ++i)sum+=(a[i]|b[i]);
    fprintf(spoj_p_info,"sum = %lld, k = %lld\n",sum,k);
    spoj_assert(sum == k);
    return SPOJ_RV_POSITIVE;
}