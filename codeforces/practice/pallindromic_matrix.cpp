//https://codeforces.com/contest/1118/problem/C
#include<bits/stdc++.h>
using namespace std;
int n,ans[25][25],a;
map<int,int> m;
int main(){
    scanf("%d",&n);
    for(int i = 0; i < n*n; ++i){
        scanf("%d",&a);
        m[a]++;
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>> p;
    set<pair<int,set<pair<int,int>>>,greater<pair<int,set<pair<int,int>>>>> s;
    for(int i = 0; i <= n-1-i; ++i){
        for(int j = 0; j <= n-1-i; ++j){
            set<pair<int,int>> k;
            k.insert(make_pair(i,j));
            k.insert(make_pair(n-1-i,n-1-j));
            k.insert(make_pair(i,n-1-j));
            k.insert(make_pair(n-1-i,j));
            s.insert(make_pair(k.size(),k));
        }
    }
    for(auto &i: m)p.push(make_pair(i.second,i.first));
    while(s.size()){
        auto block = p.top();
        p.pop();
        auto mat = *s.begin();
        s.erase(s.begin());
        if(block.first < mat.first)return printf("NO\n"),0;
        block.first-=mat.first;
        p.push(block);
        for(auto &i: mat.second){
            ans[i.first][i.second] = block.second;
        }
    }
    printf("YES\n");
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j)
            printf("%d ",ans[i][j]);
        printf("\n");
    }
    return 0;
}