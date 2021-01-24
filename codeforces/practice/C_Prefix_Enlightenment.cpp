// code from neal
#include<bits/stdc++.h>
using namespace std;

struct bipartite_union_find{
    vector<int> parent,size,root_size,root_status;
    vector<bool> bipartite,parity;
    int components = 0, minimum_on = 0;
    bipartite_union_find(int n){
        parent.resize(n+1);
        size.assign(n+1,1);
        root_size.assign(n+1,1);
        root_status.assign(n+1,-1);
        bipartite.assign(n+1,true);
        parity.assign(n+1,false);
        components = n, minimum_on = 0;
        iota(parent.begin(),parent.end(),0);
    }
    int find(int x){
        if(x == parent[x]) return x;
        int root = find(parent[x]);
        parity[x] = parity[x] ^ parity[parent[x]];
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

        if(~root_status[y])
            root_status[x] = root_status[y] ^ need_parity;

        parent[y] = x;
        size[x] += size[y];
        bipartite[x] = bipartite[x] && bipartite[y];
        parity[y] = need_parity;
        components--;
        minimum_on += get_min_size(x);
        return {true,true};
    }   
    void set_status(int x, bool status){
        int root = find(x);
        minimum_on -= get_min_size(root);
        bool par = query_parity(root,x);
        x = root;
        status ^= par;
        root_status[x] = status;
        minimum_on += get_min_size(x);
    }
};

int main(){
    int n,k; cin >> n >> k;
    string s; cin >> s;
    vector<vector<int>> g(n+1);
    for(int i = 1; i <= k; ++i){
        int c; cin >> c;
        while(c--){
            int x; cin >> x;
            g[x].emplace_back(i);
        }
    }
    bipartite_union_find obj(k);
    for(int i = 1; i <= n; ++i){
        if(g[i].size() == 1){
            obj.set_status(g[i][0],'1' - s[i-1]);
        }else if(g[i].size() == 2){
            obj.unite(g[i][0],g[i][1],s[i-1] == '0');
        }
        cout << obj.minimum_on << "\n";
    }
}