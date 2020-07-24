#include<bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int getRandom(int l, int r){
    uniform_int_distribution<int> uid(l,r);
    return uid(rng);
}

struct Treap{
    struct node{
        int sz, val, pr, lazy, sum;
        node *left, *right;
    }*root;
    typedef node* pnode;
    Treap():root(nullptr){}
    int sz(pnode t){
        return t?t->sz:0;
    }
    void upd_sz(pnode t){
        if(t)t->sz = sz(t->left) + sz(t->right) + 1;
    }
    void split(pnode t, pnode &l, pnode &r, int pos, int add = 0){
        if(!t)return void(l = r = nullptr);
        int cur = add + sz(t->left);
        if(cur <= pos)split(t->right,t->right,r,pos,cur+1),l = t;
        else split(t->left,l,t->left,pos,add),r = t;
        upd_sz(t);
    }
    void merge(pnode &t, pnode l, pnode r){
        if(!l || !r) t = l ? l : r;
        else if(l->pr > r->pr)merge(l->right,l->right,r),t=l;
        else merge(r->left,l,r->left),t = r;
        upd_sz(t);
    }
    void insert(pnode &t, pnode it){
        if(!t){
            t = it;
        }
        else if(it->pr > t->pr)split(t,it->left,it->right,it->val),t=it;
        else insert(t->val < it->val ? t->right : t->left,it);
        upd_sz(t);
    }
    void erase(pnode &t, int key){
        if(!t)return;
        else if(t->val == key){
            pnode temp = t;
            merge(t,t->left,t->right);
            delete temp;
        }else{
            erase(t->val < key ? t->right : t->left, key);
        }
        upd_sz(t);
    }
    pnode newNode(int val){
        pnode p = new node();
        p->val = val;
        p->left  = p->right = nullptr;
        p->pr = getRandom(0,INT_MAX);
        return p;
    }
    pnode find(pnode t, int val){
        if(!t)return t;
        if(t->val == val)return t;
        if(t->val < val)return find(t->right,val);
        return find(t->left,val);
    }
    int kth(pnode cur,int k){
        if(sz(cur->left) >= k)return kth(cur->left,k);
        k-=sz(cur->left);
        if(k == 1)return cur->val;
        return kth(cur->right,k-1);
    }
    int cnt(pnode root, int val){
        if(!root)return 0;
        if(root->val < val)return cnt(root->right,val)+sz(root->left)+1;
        return cnt(root->left,val);
    }
    void lazy(pnode t){
        if(!t || !t->lazy)return;
        t->val+=t->lazy;
        t->sum+=t->lazy*sz(t);
        if(t->left)t->left->lazy+=t->lazy;
        if(t->right)t->right->lazy+=t->lazy;
        t->lazy = 0;
    }
    void reset(pnode t){
        if(t)t->sum = t->val;
    }
    void combine(pnode& t, pnode l, pnode r){
        if(!l || !r)return void(t = l?l:r);
        t->sum = l->sum + r->sum;
    }
    void operation(pnode &t){
        if(!t)return;
        reset(t);
        lazy(t);
        
    }
};
