#include<iostream>
using namespace std; 
struct dataType{
    int value;
    struct dataType *prev;
    struct dataType *next;
};
 
struct dataType* insert(struct dataType* ptr, int a){
    ptr->next = new dataType;
    ptr->next->prev = ptr;
    ptr->next->next = NULL;
    ptr->next->value = a;
return ptr->next;
}
 
void deleteData(struct dataType* ptr){
     ptr->prev->next = ptr->next;
     ptr->next->prev = ptr->prev;
     delete (ptr);
}
 
 
int main(){
    struct dataType* root = new dataType;
    root->next = NULL;
    root->prev = NULL;
    root->value = 2;
    struct dataType* rear = root;
    for(int i = 3; i <= 2000000; ++i){
        rear = insert(rear,i);
    }
    bool iterationHappened;
    struct dataType* ptr = root;
    for(ptr = root; ptr!=NULL; ptr=ptr->next){
        iterationHappened = false;
        struct dataType* node;
        for(node = ptr->next; node!=NULL;){
            if(node->value%ptr->value==0){
                iterationHappened = true;
                struct dataType* tmp = node;
                tmp = node;
                node = node->next;
                deleteData(tmp);
            }else{
                node = node->next;
            }
        }
        if(!iterationHappened){
            break;
        }
    }
    unsigned long long int sum = 0;
    while(root!=NULL){
        sum+=root->value;
        root = root->next;
    }
    cout << "SUM : " << sum;
    return 0;
}
