//https://codeforces.com/problemset/problem/1253/E
#include<bits/stdc++.h>
using namespace std;
const int M = 1e5+100;

int dp[M],n,m;
vector<pair<int,int>> a;
int main(){
    scanf("%d%d",&n,&m);
    a.resize(n);
    for(auto &i: a){
        scanf("%d%d",&i.first,&i.second);
        i = pair<int,int>(i.first-i.second,i.first+i.second);
    }
    for(int i = m ; i ; --i){
        dp[i] = m-i+1;
        for(auto j: a){
            if(i >= j.first && i <= j.second){
                dp[i] = dp[i+1];
                break;
            }
            if(j.first > i){
                int gap = j.first-i;
                dp[i] = min(dp[i],gap + dp[min(m+1,j.second+gap+1)]);
            }
        }
    }    
    printf("%d",dp[1]);
    return 0;
}