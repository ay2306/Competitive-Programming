#include<bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int getRandom(){
    uniform_int_distribution<int> uid(INT_MIN,INT_MAX);
    return uid(rng);
}

struct node{
    int val,lazy,sum;
    int lsum, rsum, msum ;
    int sz, prior;
    node *l, *r;
    node(int val = 0):lsum(val),rsum(val),msum(val),sum(val),lazy(0),val(val),sz(1),prior(getRandom()),l(nullptr),r(nullptr){}
};
typedef node* pnode;

int sz(pnode t){
    return t?t->sz:0;
}

void upd_sz(pnode t){
    if(t)t->sz = sz(t->l) + sz(t->r) + 1;
}

void reset(pnode t){
    if(t){
        t->sum = t->val;
        t->rsum = t->val;
        t->msum = t->val;
        t->lsum = t->val;
    }
}

void printNode(pnode t){
    printf("val = %d, sum = %d, lsum = %d, msum = %d, rsum = %d\n",t->val,t->sum,t->lsum,t->msum,t->rsum);
}

void combine(pnode &t, pnode l, pnode r){
    if(!l || !r)return void(t = l ? l : r);
     node x;
    x.sum = l->sum + r->sum;
    x.lsum = max({l->lsum,l->sum+r->lsum});
    x.rsum = max({r->rsum,r->sum+l->rsum});
    x.msum = max({l->msum,r->msum,l->rsum+r->lsum});
    t->sum=x.sum;
    t->lsum=x.lsum;
    t->rsum=x.rsum;
    t->msum=x.msum;
}

void lazy(pnode t){
    if(!t || !t->lazy) return void();
    t->sum += sz(t)*t->lazy;
    t->val += t->lazy;
    if(t->l)t->l->lazy+=t->lazy;
    if(t->r)t->r->lazy+=t->lazy;
    t->lazy = 0;
}

void operation(pnode t){
    if(!t)return ;
    reset(t);
    lazy(t->l);
    lazy(t->r);
    combine(t,t->l,t);
    combine(t,t,t->r);
}

void split(pnode t, pnode &l, pnode &r, int pos, int add = 0){
    if(!t)return void(l = r = nullptr);
    lazy(t);
    int cur = add + sz(t->l);
    if(cur <= pos)split(t->r,t->r,r, pos, cur+1),l = t;
    else split(t->l,l,t->l,pos,add),r = t;
    upd_sz(t);
    operation(t);
}

void merge(pnode &t, pnode l, pnode r){
    lazy(l);
    lazy(r);
    if(!l || !r)return void(t = l?l:r);
    if(l->prior > r->prior)merge(l->r,l->r,r),t=l;
    else merge(r->l,l,r->l),t=r;
    upd_sz(t);
    operation(t);
}

void update(pnode t,int l, int r, int val){
    pnode L,R,mid;
    split(t,L,mid,l-1);
    split(mid,t,R,r-l);
    t->val += val;
    reset(t);
    merge(mid,L,t);
    merge(t,mid,R);
}

int query(pnode t, int l, int r){
    pnode L,R,mid;
    split(t,L,mid,l-1);
    split(mid,t,R,r-l);
    int ans = t->msum;
    merge(mid,L,t);
    merge(t,mid,R);
    return ans;
}


void print(pnode t, int l, int r){
    pnode L,R,mid;
    split(t,L,mid,l-1);
    split(mid,t,R,r-l);
    merge(mid,L,t);
    merge(t,mid,R);
}

pnode treap;

int main(){
    int n,q,a,l,r;
    scanf("%d",&n);
    for(int i = 0; i < n; ++i){
        scanf("%d",&a);
        if(!i)treap = new node(a);
        else merge(treap,treap,new node(a));
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d%d%d",&a,&l,&r);
        if(!a){
            l--;
            int val = query(treap,l,l);
            val = r-val;
            update(treap,l,l,val);
        }else{
            l--;
            r--;
            printf("%d\n",query(treap,l,r));
        }
    }
    return 0;
}