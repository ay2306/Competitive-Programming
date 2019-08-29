#include<bits/stdc++.h>
using namespace std;

class dt{
    struct node{
        int a;
        struct node* next;
        struct node* prev;
    };
    bool lastDel;
    struct node *front, *rear;
    public:
    dt(){
        lastDel = false;
        front = NULL;
        rear  = NULL;
    }
    struct node* newNode(int a){
        struct node* ptr = new struct node;
        ptr->a = a;
        ptr->next = NULL;
        ptr->prev = NULL;
        return ptr;
    }
    struct node* insert(int a){
        if(front == NULL){
            front = newNode(a);
            rear = front;
        }
        else{
            struct node *ptr = newNode(a);
            rear->next = ptr;
            ptr->prev = rear;
            rear = ptr;
        }
    }
    struct node* delSpecificNode(struct node* ptr){
        // cout << "DELETED\n";
        if(ptr->prev!=NULL)ptr->prev->next = ptr->next;
        if(ptr->next!=NULL)ptr->next->prev = ptr->prev;
        if(ptr == front)front=ptr->next;
        if(ptr == rear){rear = rear->prev;lastDel = true;}
        struct node *tmp = ptr->prev;
        delete ptr;
        return tmp;
    }
    struct node* delOneTime(){
        // cout << "DELETED\n";
        struct node *ptr = front;
        struct node *tmp = front;
        if(!lastDel){
        while(ptr->next->a <= ptr->a && ptr->next!=NULL){
            ptr = ptr->next;
        }
        if(ptr->prev!=NULL)ptr->prev->next = ptr->next;
        if(ptr->next!=NULL)ptr->next->prev = ptr->prev;
        if(ptr == front)front=ptr->next;
        if(ptr == rear){rear = rear->prev;lastDel = true;}
        tmp = ptr->prev;
        delete ptr;
        }
        else{
            rear = rear->prev;
            delete(rear->next);
            tmp = rear;
        }
        return tmp;
    }
    void ans(int k){
        int i = 0; 
        struct node* tmp;
        for(i = 0; i < k; ){
            tmp = delOneTime();
            i++;
            while(i < k && tmp!=NULL && tmp->next!=NULL && (tmp->a < tmp->next->a) && !lastDel){
                tmp = delSpecificNode(tmp);
                ++i;
            }
        }
    }
    void disp(){
        struct node *ptr = front;
        while(ptr!=NULL){
            cout << ptr->a << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
};

int main(){
    int t;
    cin >> t;
    while(t--){
        dt a;
        // stack<struct node*> st;
        // vector<struct node*> vec;
        int n,k;
        cin >> n >> k;
        while(n--){
            int b;
            cin >>b;
            a.insert(b);
            // while(st.size() && b > )
        }
        a.ans(k);
        a.disp();
    }
}