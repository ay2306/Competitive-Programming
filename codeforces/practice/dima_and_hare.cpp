#include<bits/stdc++.h>
using namespace std;

int dp[3005][2],n,a[3005][3];
int solve(int pos = 0, int state = 0){
    if(pos == n-1)return a[pos][state];
    int &res = dp[pos][state];
    if(res != -1)return res;
    res = 0;
    if(!state)res=max(solve(pos+1,1)+a[pos][0],solve(pos+1,0)+a[pos][1]);
    else res=max(solve(pos+1,1)+a[pos][1],solve(pos+1,0)+a[pos][2]);
    return res;
}
int main(){
    scanf("%d",&n);
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < n; ++j)scanf("%d",&a[j][i]);
    memset(dp,-1,sizeof(dp));
    return printf("%d",solve()),0;
}