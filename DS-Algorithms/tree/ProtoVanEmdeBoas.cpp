#include<bits/stdc++.h>

class PVEB{
    int universe_size;
    PVEB *summary;
    std::vector<PVEB*> clusters;
    int root(int u){
        return int(sqrt(u));
    }
    int high(int x){
        return x/root(this->universe_size);
    }
    int low(int x){
        return x%root(this->universe_size);
    }
    int generate_index(int cluster,int position){
        return cluster*(root(this->universe_size)) + position;
    }
public:
    PVEB(int size){
        this->universe_size = size;
        if(size <= 2){
            summary = nullptr;
            clusters = std::vector<PVEB*> (size,nullptr);
        }else{
            summary = new PVEB(root(size));
            clusters = std::vector<PVEB*> (root(size),nullptr);
            for(int _index = 0; _index < root(size); ++_index){
                clusters[_index] = new PVEB(root(size));
            }
        }
    }
    bool in(int key, PVEB *helper = nullptr){
        if(helper == nullptr){
            if(key >= universe_size)return false;
            if(universe_size == 2)return clusters[key];
            else{
                return in(low(key),clusters[high(key)]);
            }
        }else{
            if(key >= helper->universe_size)return false;
            if(helper->universe_size == 2)return helper->clusters[key];
            else{
                return in(helper->low(key),helper->clusters[helper->high(key)]);
            }
        }
    }
    void insert(int key, PVEB* helper = nullptr){
        if(helper == nullptr){
            if(universe_size == 2){
                clusters[key] = new PVEB(1);
            }else{
                insert(low(key),clusters[high(key)]);
                insert(high(key),summary);
            }
        }else{
            if(helper->universe_size == 2){
                helper->clusters[key] = new PVEB(1);
            }else{
                insert(helper->low(key),helper->clusters[helper->high(key)]);
                insert(helper->high(key),helper->summary);
            }
        }
    }
};