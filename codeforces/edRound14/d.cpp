#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;

int p[N],arr[N];
int fp(int x){
    if(p[x] != x)p[x] = fp(p[x]);
    return p[x];
}

void u(int a, int b){
    p[fp(a)] = fp(b);
}

map<int,vector<int>> m;

int main(){
    int n,m1;
    scanf("%d%d",&n,&m1);
    for(int i = 1; i <= n; ++i)p[i] = i;
    for(int i = 1; i <= n; ++i)scanf("%d",arr+i);
    while(m1--){
        int a,b;
        scanf("%d%d",&a,&b);
        u(a,b);
    }
    for(int i = 1; i <= n; ++i)m[fp(i)].emplace_back(arr[i]);
    for(auto &i: m){
        sort(i.second.begin(),i.second.end());
    }
    for(int i = 1; i <= n; ++i){
        printf("%d ",m[fp(i)].back());
        m[fp(i)].pop_back();
    }
    return 0;
}