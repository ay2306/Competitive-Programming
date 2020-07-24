//https://codeforces.com/contest/508/problem/E
#pragma Optimize("O3")
#include<bits/stdc++.h>
using namespace std;
const int N = 1500;
int n;
int dp[N][N],l[N],r[N];
char ans[2*N];

void create(int i, int j){
    if(i > j)return;
    int k = dp[i][j];
    putchar('(');
    create(i+1,i+k/2);
    putchar(')');
    create(i+k/2+1,j);
}

int main(){
    scanf("%d",&n);
    for(int i = 0; i < n; ++i)scanf("%d %d",l+i,r+i);
    for(int len = 0; len < n ; ++len){
        for(int open = 0; open+len < n; ++open){
            int last = open+len;
            for(int dis = 1; open+dis/2 <= last; dis+=2){
                if(dis < l[open] || dis > r[open])continue;
                if(open+dis/2 != last){
                    if((dis == 1 || dp[open+1][open+dis/2]) && dp[open+dis/2+1][last]){
                        dp[open][last] = dis;
                        break;
                    }
                }else{
                    if(open == last || dp[open+1][last]){
                        dp[open][last] = dis;
                    }
                }
            }
        }
    }
    if(!dp[0][n-1])return printf("IMPOSSIBLE\n"),0;
    create(0,n-1);
    return 0;
}