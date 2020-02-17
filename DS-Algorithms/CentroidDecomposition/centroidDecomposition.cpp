#include<bits/stdc++.h>
using namespace std;

struct CentroidDecomposition{
    vector<set<int>> tree;
    vector<int> dad;
    vector<int> sub;
    CentroidDecomposition(vector<set<int>> &tree): tree(tree){
        int n = tree.size();
        dad.resize(n);
        sub.resize(n);
        build(0,-1);
    }
    void build(int u, int p){
        int n = dfs(u,p);
        int centroid = dfs(u,p,n);
        if(p == -1)p=centroid;
        dad[centroid]=p;
        for(auto v: tree[centroid]){
            tree[centroid].erase(v);
            tree[v].erase(centroid);
            build(v,centroid);
        }
    }
    int dfs(int u, int p){
        sub[u] = 1;
        for(auto v: tree[u]){
            if(v != p)sub[u]+=dfs(v,u);
        }
        return sub[u];
    }
    int dfs(int u, int p, int n){
        for(auto v: tree[u]){
            if(v != p && sub[v] > n/2)return dfs(v,u,n);
        }
        return u;
    }
    int operator[](int i){
        return dad[i];
    }
};

int main(){

}