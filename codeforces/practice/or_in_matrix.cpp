//https://codeforces.com/contest/486/problem/B
#include<bits/stdc++.h>
using namespace std;
const int N = 110;
int n,m,arr[N][N],pos[N][N];

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)scanf("%d",&arr[i][j]),pos[i][j]=1;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(arr[i][j])continue;
            for(int k = 0; k < n; ++k)pos[k][j] = 0;
            for(int k = 0; k < m; ++k)pos[i][k] = 0;
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0, s = 0; j < m; ++j, s = 0){
            if(!arr[i][j])continue;
            for(int k = 0; k < n; ++k)s+=pos[k][j];
            for(int k = 0; k < m; ++k)s+=pos[i][k];
            if(s == 0)return printf("NO\n"),0;
        }
    }
    printf("YES\n");
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j)printf("%d ",pos[i][j]);
        printf("\n");
    }
    return 0;
}