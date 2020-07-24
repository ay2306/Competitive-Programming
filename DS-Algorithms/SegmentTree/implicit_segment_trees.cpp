#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct ImplicitSegmentTree{
    struct Node{
        int mx,left, right, pr;
        Node *l, *r;
        Node() : mx(0), l(nullptr), r(nullptr), left(0), right(-1), pr(0){}
    };
    Node *root;
    ImplicitSegmentTree(int l, int r):root(newNode(l,r)){}
    struct Node *newNode(int l, int r){
        struct Node *a = new Node();
        a->left = l;
        a->right = r;
        return a;
    }
    void push(struct Node *a){
        a->mx = max(a->mx,a->pr);
        if(a->right != a->left){
            a->l->pr = max(a->l->pr,a->pr);
            a->r->pr = max(a->r->pr,a->pr);
        }
    }
    void update(struct Node *a, int l, int r, int val){
        push(a);
        if(l > a->right || r < a->left)return;
        if(a -> left == l && a -> right == r){
            a -> pr = val;
            return;
        }
        int mid = l + r >> 1;
        if(a->l == nullptr)a->l=newNode(l,mid);
        if(a->r == nullptr)a->r=newNode(mid+1,r);
        if(mid >= r)update(a->l, l, r, val);
        else if(l > mid)update(a->r, l, r, val);
        else{
            update(a->l,l,mid,val);
            update(a->r,mid+1,r,val);
        } 
    }
    int query(struct Node *a, int ind){
        push(a);
        if(a->right == a->left)return a->mx;
        int mid = a->left + a->right >> 1;
        if(ind <= mid)return query(a->l,ind);
        return query(a->r,ind);
    }
};

int main(){
    int C,R,n,q;
    char c;
    scanf("%d %d",&n,&q);
    ImplicitSegmentTree row(1,n),col(1,n);
    while(q--){
        scanf("%d %d %c",&C, &R ,&c);
        if(c == 'L'){
            int last = row.query(row.root,R);
            printf("%d\n",last);
            col.update(col.root,1,R,R-1);           
        }else{
            int last = col.query(col.root,C);
            printf("%d\n",last);
            row.update(row.root,1,C,C-1);           
        }
    }
    return 0;
}