#include<bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> uid(0,0x7fffffff);

struct node{
    int sz, prior, value;
    node *l, *r;
    node(): value(0), sz(0), prior(0), l(nullptr), r(nullptr){}
    node(int val): value(val), sz(1), prior(uid(rng)), l(nullptr), r(nullptr){}
};

typedef node* pnode;

int size(pnode v){
    return v ? v->sz : 0;
}

int updSize(pnode v){
    if(v)v->sz = size(v->l) + size(v->r) + 1; 
}

int main(){
    return 0;
}