#include<bits/stdc++.h>
using namespace std;
template<class T>
struct node{
    node *l;
    node *r;
    node *p;
    T v;
    node(){}
    node(int val):v(val){}
};

template<class T>
class splay_tree{
    node<T> *root;
    void rightRotate(node<T> *A){
        node<T> *T = A->l;
        node<T> *B = T->r;
        node<T> *P = A->p;
        if(P){
            if(P->r == A)P->r=T;
            else P->l = T;
        }
        if(B)B->p=A;
        T->p=P;
        T->r=A;
        A->p=T;
        A->l=B;
    }   
    void leftRotate(node<T> *A){
        node<T> *T = A->r;
        node<T> *B = T->l;
        node<T> *P = A->p;
        if(P){
            if(P->r == A)P->r=T;
            else P->l = T;
        }
        if(B)B->p=A;
        T->p=P;
        T->l=A;
        A->p=T;
        A->r=B;
    }   
    void SPLAY(node<T> *A){
        while(true){
            node<T> *P = A->p;
            if(!P)break;
            node<T> *GP = P->p;
            if(!GP){
                if(P->l == A)rightRotate(P);
                else leftRotate(P);
                break;
            }
            if(GP->l == P){
                if(P->l == A){
                    rightRotate(GP);
                    rightRotate(P);
                }else{
                    rightRotate(GP);
                    leftRotate(P);
                }
            }else{
                if(P->l == A){
                    leftRotate(GP);
                    rightRotate(P);
                }else{
                    leftRotate(GP);
                    leftRotate(P);
                }
            }
        }
        root = A;
    }
public:
    splay_tree(){root=NULL;}
    void insert(int val){
        if(!root){
            root = new node<T>(val);
            return;
        }
        node<T> *ptr = root;   
        while(true){
            if(ptr->v==val)break;
            if(val < ptr->v){
                if(ptr->l)ptr=ptr->l;
                else{
                    ptr->l = new node<T>(val);
                    break;
                }
            }else{
                if(ptr->r)ptr=ptr->r;
                else{
                    ptr->r = new node<T>(val);
                    break;
                }
            }
        }
        SPLAY(ptr);
    }
    node<T> *find(int val){
        if(!root)return;
        node<T> *ptr = root;
        while(true){
            if(ptr->v == val)break;
            if(ptr->v > val && ptr->l)ptr=ptr->l;
            else if(ptr->v > val && !ptr->l)break;
            else if(ptr->v < val && ptr->r)ptr=ptr->r;
            else if(ptr->v < val && !ptr->r)break;
        }
        SPLAY(ptr);
        if(ptr->v == val)return ptr;
        return NULL;
    }
    bool erase(int val){
        node<T> *ptr = find(val);
        if(!ptr)return false;
        SPLAY(ptr);
        if(!ptr->l){
            root=ptr->r;
            root->p=NULL;
            free(ptr);
            return true;
        }
        node<T>* A = ptr->l;
        while(A->r)A=A->r;
        if(ptr->r){
            A->r=ptr->r;
            ptr->r->p=A;
        }
        root = ptr->l;
        root->p = NULL;
        free(ptr);
        return true;
    }
    // Utilities
    node<T> *getRoot(){return root;}
    void dfs(node<T>* ptr){
        if(!ptr)return;
        dfs(ptr->l);
        dfs(ptr->r);
        printf("node = %d",ptr->v);
        if(ptr->l)printf("\tL = %d",ptr->l->v);
        if(ptr->r)printf("\tR = %d",ptr->r->v);
        printf("\n");
    }
    
};

int main(){
    
    return 0;
}