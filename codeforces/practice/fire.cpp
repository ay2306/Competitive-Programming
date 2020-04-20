//https://codeforces.com/problemset/problem/864/E
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 110;

int n,dp[N][N*100],in[N][N*100],mx;

struct node{
    int t,val,d,ind;
    bool operator<(const node &rhs)const{
        return d < rhs.d;
    } 
}a[N];

int main(){
    scanf("%d",&n);
    for(int i = 1; i <= n; ++i)scanf("%d%d%d",&a[i].t,&a[i].d,&a[i].val),a[i].ind=i;
    sort(a+1,a+n+1);
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j <= 100*(n+1); ++j){
            dp[i][j] = dp[i-1][j];
            if(a[i].t <= j && j < a[i].d && dp[i][j] < dp[i-1][j-a[i].t]+a[i].val){
                in[i][j] = 1;
                dp[i][j]=dp[i-1][j-a[i].t]+a[i].val;
            }
            mx = max(mx,dp[i][j]);
        }
    }
    stack<int> ans;
    int i = n,j;
    for(j = 0; j <= 100*(n+1) && dp[i][j] != mx; ++j);
    while(i > 0){
        if(in[i][j])ans.push(a[i].ind),j-=a[i].t;
        i--;
    }
    printf("%d\n%d\n",mx,(int)ans.size());
    for(;!ans.empty();ans.pop())printf("%d ",ans.top());
    return 0;
}