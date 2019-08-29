#include<iostream>

using namespace std;

struct node{
int val;
struct node* prev;
struct node* next;
};
struct node* newNode(int val){
struct node* ptr = new node;
ptr->val = val;
ptr->next = NULL;
ptr->prev = NULL;
return ptr;
}

void join(struct node *top, struct node* left, struct node *right){
top = left;
while(left->next!= NULL){
    left = left->next;
}
left->next = right;
}

void split(struct node *top, struct node* left, struct node *right){
int i = 1;
while(top!=NULL){
    if(i == 1){
        left = top;
    }
    else if(i == 2){
        right = top;
    }
    else if(i%2==1){
        left->next = top;
        top->prev = left;
    }
    else if(i%2==0){
        right->next = top;
        top->prev = right;
    }
    top = top->next;
    ++i;
}
}

void deleteNode(struct node* root){
if(root->prev==NULL){
    if(root->next == NULL)delete root;
    else{
        (root->next)->prev = NULL;
    }
}
else if(root->next==NULL){
     (root->prev)->next = NULL;
}

}
int main(){
int t;
cin >> t;
while(t--){
    struct node *top, *left, *right;
    int m,x,y;
    cin >> m >> x >> y;
    int s = m/2;
    float r = (float)x/(float)y;
    m--;
    int i = 2;
    struct node* tmp = top;
    top  = newNode(1);
    while(m--){
        struct node* ptr = newNode(i);
        ++i;
        tmp->next = ptr;
        ptr->prev = tmp;
        tmp = ptr;
    }
    while(s>1){
        split(top,left,right);
        struct node* ptr_left = left;
        struct node* ptr_right = right;
        for(int i = 0; i < (int)(s*r); ++i){
            ptr_left = ptr_left->next;
            ptr_right = ptr_right->next;
        }
        deleteNode(ptr_left);
        deleteNode(ptr_right);
        join(top,left,right);
        s--;
    }
    int a = top->val;
    int b = top->next->val;
    cout << (a^b) << "\n";
}
return 0;
}
