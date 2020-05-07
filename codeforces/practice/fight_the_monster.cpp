//https://codeforces.com/contest/487/problem/A
#include<bits/stdc++.h>
using namespace std;

int main(){
    long long h[2],at[2],d[2],cost = LLONG_MAX,c[3],i,j,k,t,a,b,l;
    for(i = 1; i >= 0; i--)cin >> h[i] >> at[i] >> d[i];
    for(i = 0; i < 3; ++i)cin >> c[i];
    for(i = 0; i <= 300; ++i){
        for(j = 0; j <= 300; ++j){
            a = at[1]+i;
            b = d[1]+j;
            if(a <= d[0])continue;
            k = a-d[0];
            t = ((h[0]+k-1)/k);
            l = h[1]-t*max(at[0]-b,0LL);
            l = max(0LL,1-l);
            cost = min(cost,i*c[1]+j*c[2]+l*c[0]);
        }
    }
    return cout << cost,0;
}