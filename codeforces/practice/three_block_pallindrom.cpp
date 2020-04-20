//https://codeforces.com/contest/1335/problem/E2
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int N = 2e5+10;
const int M = 201;
const int inf = 1e9;
int t,f[N][M],n,a[N];
vector<int> pos[N];

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i = 0 ; i < M; ++i)pos[i].clear();
        for(int i = 1; i <= n; ++i){
            scanf("%d",a+i);
            for(int j = 0; j < M; ++j)f[i][j]=f[i-1][j];
            f[i][a[i]]++;
            pos[a[i]].emplace_back(i);
        }
        int ans = 0;
        for(int i = 1; i < M; ++i){
            for(int x = 1; x <= (int)pos[i].size()/2; ++x){
                int l = pos[i][x-1], r = pos[i][(int)pos[i].size()-x];
                for(int j = 1; j < M; ++j){
                    if(i != j)ans = max(ans,f[r][j]-f[l][j]+2*x);
                }
            }
            ans = max(ans,(int)pos[i].size());
        }
        printf("%d\n",ans);
    }   
}