/*
BINARY TREE AND TRY TRAVERSAL OF BREADTH FIRST APPROACH
*/

#include <stdio.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node* newNode(int);
struct node* createTree();
void printBFT(struct node*);
void printGivenLevel(struct node*, int);
int height(struct node*);

struct node* newNode(int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
return(ptr);
}

struct node* createTree(){
    struct node* top = newNode(1);
    top->left = newNode(2);
    top->left->right = newNode(5);
    top->left->left = newNode(4);
    top->right = newNode(3);
return top;
}
void printBFT(struct node* root){
    int h = height(root);
    int i;
    for(i = 0; i <= h; i++){
        printGivenLevel(root,i);
        printf("\n");
    }
}

void printGivenLevel(struct node* root, int level){
    if(root==NULL)return;
    if(level == 1)printf("%d  ",root->data);
    else if(level > 1){
        printGivenLevel(root->left,level-1);
        printGivenLevel(root->right,level-1);
    }
}

int height(struct node* ptr){
    if(ptr!=NULL){
        int lheight = height(ptr->left);
        int rheight = height(ptr->right);

        if(lheight > rheight)return (lheight+1);
        return (rheight+1);
    }
    return 0;
}
int main(){
    struct node* root = createTree();
    printf("BREADTH FIRST TRAVERSAL IS AS FOLLOWS:\n");
    printBFT(root);
    return 0;
}
