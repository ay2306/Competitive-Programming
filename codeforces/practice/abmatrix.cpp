//https://codeforces.com/contest/1360/problem/G
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m,a,b;
        scanf("%d%d%d%d",&n,&m,&a,&b);
        if(n*a != m*b){
            printf("NO\n");
            continue;
        }
        vector<vector<int>> arr(n,vector<int>(m,0));
        priority_queue<pair<int,int>> p;
        for(int i = 0; i < m; ++i)p.emplace(b,i);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < a; ++j){
                auto k = p.top();
                p.pop();
                arr[i][k.second] = 1;
                k.first--;
                if(k.first)p.emplace(k);
            }
        }
        printf("YES\n");
        for(auto &i: arr){
            for(int j: i)printf("%d",j);
            printf("\n");
        }
    }
}