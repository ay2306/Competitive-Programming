// code from neal
#include<bits/stdc++.h>
using namespace std;

struct bipartite_union_find{
    vector<int> parent,size,root_size,root_status;
    vector<int> bipartite,parity;
    int components = 0, minimum_on = 0;
    bipartite_union_find(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        root_size.resize(n+1,1);
        root_status.resize(n+1,-1);
        bipartite.resize(n+1,true);
        parity.resize(n+1,false);
        components = n, minimum_on = 0;
        iota(parent.begin(),parent.end(),0);
    }
    int find(int x){
        if(x == parent[x]) return x;
        int root = find(parent[x]);
        parity[x] ^= parity[parent[x]];
        return parent[x] = root;
    }
    int get_other_size(int x){
        x = find(x);
        return size[x] - root_size[x];
    }
    int get_min_size(int x){
        x = find(x);
        if(root_status[x] == 0)return get_other_size(x);
        if(root_status[x] > 0)return root_size[x];
        return min(root_size[x],get_other_size(x));
    }
    bool query_component(int x, int y){
        return find(x) == find(y);
    }
    bool query_parity(int x, int y){
        return parity[x]^parity[y];
    }
    pair<bool,bool> unite(int x, int y, int different = true){
        int x_root = find(x);
        int y_root = find(y);
        if(x_root == y_root){
            bool consistent = !(parity[x] ^ parity[y] ^ different);
            if(!consistent)bipartite[x_root] = false;
            return {false,consistent};
        }
        minimum_on -= get_min_size(x);
        minimum_on -= get_min_size(y);
        bool need_parity = parity[x] ^ parity[y] ^ different;
        x = x_root, y = y_root;
        if(size[x] < size[y])swap(x,y);
        if(need_parity)root_size[x] += get_other_size(y);
        else root_size[x] += root_size[y];
        parent[y] = x;
        size[x] += size[y];
        bipartite[x] &= bipartite[y];
        parity[y] = need_parity;
        components--;
        minimum_on += get_min_size(x);
        return {true,true};
    }
    void set_status(int x, bool status){
        minimum_on -= get_min_size(x);
        int root = find(x);
        bool par = status^parity[x]^parity[root];
        root_status[x] = par;
        minimum_on += get_min_size(x);
    }
};

int main(){
    
}