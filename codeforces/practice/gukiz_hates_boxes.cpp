//https://codeforces.com/problemset/problem/551/C
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
long long n,arr[N],m,lo,hi=LLONG_MAX,mi,ans = LLONG_MAX;
bool check(long long x){
    long long i = 0, j = n-1, left = 0, cur = arr[n-1];
    while(i <= m && j >= 0){
        if(cur > left){
            i++;
            cur -= left;
            left = x-(j+1);
        }else{
            left-=cur;
            j--;
            if(j >= 0)cur = arr[j];
        }
    }
    return i <= m;
}
int main(){
    scanf("%lld%lld",&n,&m);
    for(int i = 0; i < n; ++i)scanf("%lld",arr+i);
    while(lo <= hi){
        mi = lo + hi >> 1;
        if(check(mi))ans = mi,hi=mi-1;
        else lo = mi+1;
    } 
    printf("%lld\n",ans);
    return 0;
}