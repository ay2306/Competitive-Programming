#include<bits/stdc++.h>
using namespace std;

class DSU{
    vector<int> p;
public:
    DSU(int n):p(n+1){
        iota(p.begin(),p.end(),0);
    }
    int fp(int x){
        if(p[x] != x)p[x] = fp(p[x]);
        return p[x];
    }
    void u(int a, int b){
        p[fp(a)] = fp(b);
    }
};

int main(){
    int n,k,l,a,b;
    scanf("%d%d%d",&n,&k,&l);
    DSU train(n),road(n);
    while(k--){
        scanf("%d%d",&a,&b);
        road.u(a,b);
    }
    while(l--){
        scanf("%d%d",&a,&b);
        train.u(a,b);
    }
    map<int,map<int,int>> f;
    for(int i = 1; i <= n; ++i){
        f[road.fp(i)][train.fp(i)]++;
    }
    for(int i = 1; i <= n; ++i){
        printf("%d ",f[road.fp(i)][train.fp(i)]);
    }
    return 0;
}