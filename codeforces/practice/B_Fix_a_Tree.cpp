#include<bits/stdc++.h>
using namespace std;

int main(){
    int root = -1,n,change = 0;
    cin >> n;
    vector<int> p(n+1),par(n+1);
    for(int i = 1; i <= n; ++i){
        cin >> par[i];
    }
    iota(p.begin(),p.end(),0);
    function<int(int)> fp = [&](int x)->int{
        if(p[x] != x)p[x] = fp(p[x]);
        return p[x];
    };
    auto u = [&](int a, int b){
        p[fp(a)] = fp(b);
    };
    for(int i = 1; i <= n; ++i){
        if(par[i] == i){
            root = i;
            break;
        }
    }
    if(root == -1)
    for(int i = 1; i <= n; ++i){
        if(fp(par[i]) == fp(i)){
            root = i;
            break;
        }
        u(par[i],i);
    }
    iota(p.begin(),p.end(),0);
    for(int i = 1; i <= n; ++i){
        if(i == root){
            if(par[i] != root)change++,par[i] = root;
        }else if(fp(i) == fp(par[i])){
            change++;
            par[i] = root;
        }
        u(i,par[i]);
    }
    cout << change << "\n";
    for(int i = 1; i <= n; ++i)cout << par[i] << " ";
    return 0;
}