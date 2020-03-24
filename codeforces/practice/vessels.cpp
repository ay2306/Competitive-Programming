#include<bits/stdc++.h>
#define loop(a,b,c) for(int a = b; a < c; ++a)
using namespace std;

struct node{
    int left;
    int fill;
    int index;
    node* next;
    node():left(0),fill(0),next(NULL){}
};

node* perform(node *a,int val){
    // printf("index = %d, fill = %d, left = %d, val = %d\n",a->index,a->fill,a->left,val);
    if(a == NULL)return NULL;
    if(a->left == 0){a->next=perform(a->next,val);return a->next;}
    else if(a->left > val){
        a->left-=val;
        a->fill+=val;
        return a;
    }
    val-=a->left;
    a->fill+=a->left;
    a->left = 0;
    a->next = perform(a->next,val);
    return a->next;
}

int main(){
    int n,q,t,l,v;
    scanf("%d",&n);
    vector<node*> a(n+1);
    loop(i,0,n+1){
        a[i] = new node();
        a[i]->index = i;
    }
    loop(i,1,n+1){
        scanf("%d",&a[i]->left);
        a[i-1]->next = a[i];
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d",&t);
        if(t == 1){
            scanf("%d%d",&l,&v);
            perform(a[l],v);
        }
        else{
            scanf("%d",&l);
            printf("%d\n",a[l]->fill);
        }
    }
    return 0;
}