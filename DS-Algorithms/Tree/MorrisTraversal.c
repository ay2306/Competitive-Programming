/*
WHAT IS MORRIS INORDER TRAVERSAL?
ANS: IT IS AN ALGORITHM FOR INORDER TRAVERSAL OF BINARY TREES WITHOUT USING STACKS AND RECURRSION
TREE MADE:         1
                  / \
                /     \
              /         \
             2           3
           /   \       /   \
          4     5     6     7
         / \   / \   / \   / \
        8   9 10 11 12 13 14 15

*/
#include <stdio.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->right = NULL;
    ptr->left = NULL;
return ptr;
}

struct Node* createTree(){
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(11);
    root->right->left->left = newNode(12);
    root->right->left->right = newNode(13);
    root->right->right->left = newNode(14);
    root->right->right->right = newNode(15);
return root;
}

void MorrisTraversal(struct Node* root){
    if(root==NULL)return;
    struct Node *current, *pre;
    current = root;
    while(current!=NULL)
    {
        if(current->left==NULL)
        {
            printf("%d ",current->data);
            current=current->right;
        }
        else{
            pre = current->left;
            while(pre->right != NULL && pre->right!=current){
                pre=pre->right;
                if(pre->right == NULL){
                    pre->right = current;
                    current = current->left;
                }else{
                    pre->right = NULL;
                    printf("%d ",current->data);
                    current=current->right;
                }
            }
        }
    }

}

int main(){
struct Node* root = createTree();
MorrisTraversal(root);
return 0;
}
