#include<bits/stdc++.h>
using namespace std;

const int N = 2e5;
int p[N];
int main(){
    for(int i = 2; i < N; ++i){
        if(p[i])continue;
        for(int j = i; j < N; j+=i)p[j]=i;
    }
    int n,k;
    scanf("%d%d",&n,&k);
    vector<int> a;
    while(n > 1){
        a.emplace_back(p[n]);
        n/=p[n];
    }
    if((int)a.size() < k)return printf("-1"),0;
    while(a.size() > k){
        int u = a.back();
        a.pop_back();
        a.back()*=u;
    }
    for(int i: a)printf("%d ",i);
    return 0;
}