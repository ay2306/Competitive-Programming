// To revise again sometime
// Remind me if you read this (Just DM me)
// Thank you
#include<bits/stdc++.h>
using namespace std;
const int N = 251;
int a[N][N], r[N*N], c[N*N], ans[N][N];
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    for(int i = 0 ; i < n; ++i)
        for(int j = 0; j < m; ++j)
            scanf("%d",&a[i][j]);
    for(int i = 0 ; i < n; ++i){
        int mx = 0;
        for(int j = 0; j < m; ++j)mx=max(mx,a[i][j]);
        r[mx]=1;
    }
    for(int i = 0 ; i < m; ++i){
        int mx = 0;
        for(int j = 0; j < n; ++j)mx=max(mx,a[j][i]);
        c[mx]=1;
    }
    queue<pair<int,int>> q;
    int x = -1, y = -1;
    for(int i = n*m; i ; i--){
        x+=r[i],y+=c[i];
        if(r[i]||c[i]){
            ans[x][y] = i;
        }else{
            int a,b;
            tie(a,b) = q.front();
            q.pop();
            ans[a][b] = i;
        }
        if(r[i])
            for(int j = y-1; ~j; --j)q.emplace(x,j);
        if(c[i])
            for(int j = x-1; ~j; --j)q.emplace(j,y);
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j)printf("%d ",ans[i][j]);
        printf("\n");
    }
    return 0;
}