#pragma GCC optimize("O2")
#pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>
#define ll long long
#ifdef LOCAL 
#define debug(x) cout << #x << " = " << x << " "; 
#define debugn(x) cout << #x << " = " << x << "\n"; 
#define line cout << "(LINE)" << __LINE__ << " ";
#endif
#ifndef LOCAL
#define debug(x) 42;
#define debugn(x) 42;
#define line 42;
#endif
using namespace std;

struct Node{
    int mx,pr;
    Node *l, *r;
    Node(int maximum = 0) : mx(maximum), l(0), r(0), pr(0){}
};
Node *row = new Node(), *col = new Node();
void push(Node *a){
    a->mx = max(a->mx,a->pr);
    if(a->l)a->l->pr = max(a->l->pr,a->pr);
    if(a->r)a->r->pr = max(a->r->pr,a->pr);
}
void update(Node *a, int tl, int tr, int l, int r, int val){
    push(a);
    if(l > tr || r < tl)return;
    if(l <= tl && tr <= r){
        a -> pr = val;
        return;
    }
    int tx = tl + tr >> 1;
    if(a->l == nullptr){
        a->l=new Node(a->mx);
        a->r=new Node(a->mx);
    }
    update(a->l,tl,tx,l,r,val);
    update(a->r,tx+1,tr,l,r,val);
}
int query(Node *a, int tl, int tr, int ind){
    push(a);
    if(tr == tl)return a->mx;
    int tx = tl + tr >> 1;
    if(a->l && ind <= tx)return query(a->l,tl,tx,ind);
    else if(a->r)return query(a->r,tx+1,tr,ind);
    return a->mx;
}

int C,R,n,q;
char c;

int main(){
    scanf("%d %d",&n,&q);
    while(q--){
        scanf("%d %d %c",&C, &R ,&c);
        if(c == 'L'){
            int last = query(row,1,n,R);
            printf("%d\n",C-last);
            update(row,1,n,R,R,C);
            update(col,1,n,last,C,R);           
        }else{
            int last = query(col,1,n,C);
            printf("%d\n",R-last);
            update(col,1,n,C,C,R);
            update(row,1,n,last,R,C);           
        }
    }
    return 0;
}