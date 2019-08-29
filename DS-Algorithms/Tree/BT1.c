/*
BINARY TREES 
SAMPLE: 		1
			   / \
			  2   3
			 / \  
			4   5
*/
struct Node{
	Node *left;
	Node *right;
	int data;
}

Node* createSampleTree(){
	Node *tmp = new Node;
	tmp->data = 1;
	tmp->left = new Node;
	tmp->right = new Node;
	(tmp->left)->data = 2;
	(tmp->right)->data = 3;
	(tmp->right)->right = NULL;
	(tmp->right)->right = NULL;
	(tmp->left)->left = new Node;
	(tmp->left)->left = new Node;
	((tmp->left)->left)->data = 4;
	((tmp->left)->right)->data = 5;
	((tmp->left)->left)->left = NULL;
	((tmp->left)->right)->left = NULL;
	((tmp->left)->left)->right = NULL;
	((tmp->left)->right)->right = NULL;
return tmp;
}
/*
TRAVERSAL: DEPTH FIRST TRAVERSAL 
SUBTYPE: INORDER(LEFT ROOT RIGHT)
EXPECTED OUTPUT: 4 2 5 1 3
*/

void inorder(Node *ptr){
	if(ptr->left!=NULL)inorder(ptr->left);
	printf("%d\t",(ptr->data));
	if(ptr->left!=NULL)inorder(ptr->right);
}

int main(){
	Node *top = createSampleTree();
	inorder(top);
	return 0;
}