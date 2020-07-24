#include<iostream>

using namespace std;

template<int MX>
struct BIT{
    int *tree;
    BIT():{
        tree = new int[MX];
    }
    void update(int x, int val){
        ++x;
        while(x <= N){
            tree[x]+=val;
            x+=(x&-x);
        }
    }
    int query(int x){
        ++x;
        int res = 0;
        while(x > 0){
            res+=tree[x];
            x-=(x&-x);
        }
        return res;
    }
};

