#include<bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());


int getRandom(){
    uniform_int_distribution<int> uid(INT_MIN,INT_MAX);
    return uid(rng);
}

struct node{
    int size,val,prior;
    int lsum, rsum, msum, sum;
    node *l, *r;
    node(int val = 0):sum(val),rsum(val),lsum(val),msum(val),val(val),size(1),l(nullptr),r(nullptr),prior(getRandom()){}
};
typedef node* pnode;
int sz(pnode t){
    return t ? t->size : 0;
}

void upd_sz(pnode t){
    if(t)t->size = sz(t->l) + 1 + sz(t->r);
}

void reset(pnode t){
    if(!t)return;
    t->sum =  t->val;
    t->rsum = t->val;
    t->lsum = t->val;
    t->msum = t->val;
}

void combine(pnode &t, pnode l, pnode r){
    if(!l || !r)return void(t = l?l:r);
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

void operation(pnode t){
    if(!t)return;
    reset(t);
    combine(t,t->l,t);
    combine(t,t,t->r);
}


void split(pnode t, pnode &l, pnode &r, int pos, int add = 0){
    if(!t)return void(l = r = nullptr);
    int cur = add + sz(t->l);
    if(pos >= cur)split(t->r,t->r,r,pos,cur+1),l=t;
    else split(t->l,l,t->l,pos,add),r=t;
    upd_sz(t);
    operation(t);
}

void merge(pnode &t, pnode l, pnode r){
    if(!l || !r)return void(t = l?l:r);
    if(l->prior > r->prior)merge(l->r,l->r,r),t=l;
    else merge(r->l,l,r->l),t = r;
    upd_sz(t);
    operation(t);
}

void erase(pnode &t, int pos){
    pnode l,r,tmp;
    split(t,l,r,pos-1);
    split(r,tmp,r,0);
    delete tmp;
    merge(t,l,r);
}

void insert(pnode &t, pnode it, int pos){
    pnode l,r;
    split(t,l,r,pos-1);
    merge(it,it,r);
    merge(t,l,it);
}

void update(pnode &t, int pos, int val){
    pnode l,r,mid;
    split(t,l,mid,pos-1);
    split(mid,mid,r,0);
    mid->val=val;
    reset(mid);
    merge(mid,mid,r);
    merge(t,l,mid);
}

int query(pnode &t, int L, int R){
    pnode l,r,mid;
    split(t,l,mid,L-1);
    split(mid,mid,r,R-L);
    int res = mid->msum;
    merge(mid,mid,r);
    merge(t,l,mid);
    return res;
}

node *treap;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        int a;
        cin >> a;
        if(i)merge(treap,treap,new node(a));
        else treap = new node(a);
    }
    int q;
    cin >> q;
    while(q--){
        char c;
        int l,r ;
        cin >> c;
        if(c == 'I'){
            cin >> l >> r;
            insert(treap,new node(r),l-1);
        }
        if(c == 'R'){
            cin >> l >> r;
            update(treap,l-1,r);
        }
        if(c == 'Q'){
            cin >> l >> r;
            cout << query(treap,l-1,r-1) << "\n";
        }
        if(c == 'D'){
            cin >> l;
            erase(treap,l-1);
        }
    }
    return 0;
}