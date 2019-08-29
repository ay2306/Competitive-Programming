#include <iostream>

using namespace std;


struct node{
    char character;
    int value;
    struct node* child[26];
};

struct node* newNode(char character, int data){
    struct node* ptr = new node;
    for(int i = 0; i < 26; ++i){
        ptr->child[i] = NULL;
    }
    ptr->character = character;
    ptr->value = data;
return ptr;
}
int child_node(char a){
   if(a>=65 && a<=90)return(a-65);
   if(a>=97 && a<=122)return(a-97);
}
struct node* child_node_with_value(struct node *ptr, int value){
    for(int i = 0; i < 26; ++i){
        if((ptr->child[i])->value == value)return ptr->child[i];
    }
return NULL;
}
void insert_value(struct node* root, string word, int value){
    for(int i = 0; i < word.length(); ++i){
        int child = child_node(word[i]);
        if(root->child[child] == NULL){
            root->child[child] = newNode(word[i],value);
        }
        root = root->child[child];
        if(root->value < value)root->value = value;
    }
}
int search_string(struct node* root, string word){
string reply = "";
    for(int i = 0; i < word.length(); ++i){
        int child = child_node(word[i]);
        if(root->child[child] == NULL)return -1;
        reply+=word[i];
        root = root->child[child];
    }
    int maximum_value = 0;
    for(int i = 0; i < 26; ++i){
        if(root->child[i]!=NULL){
            if(maximum_value < (root->child[i])->value)maximum_value = (root->child[i])->value;
        }
    }
    /*
    while(true){
        root = child_node_with_value(root,maximum_value);
        if(root==NULL)break;
        reply+=root->character;
    }*/
return maximum_value;
}
int main(){
    int n,q;
    struct node* root =  newNode(' ', 0);
    cin >> n >> q;

    //insert_value(root,"hackerearth",10);
    //insert_value(root,"hackerrank",9);

    while(n--){
        string a;
        int val;
        cin >> a >> val;
        insert_value(root,a,val);
    }

    //cout << search_string(root,"hacker") << "\n";

    while(q--){
        string a;
        cin >> a;
        cout << search_string(root,a) << "\n";
    }

return 0;

}
