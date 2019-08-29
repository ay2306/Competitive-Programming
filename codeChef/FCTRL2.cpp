#include <iostream>
using namespace std;

struct Node
{
	int info;
	Node* prev;
	Node* next;
};

class list
{
	Node* top;
	Node* rear;
public:
	list();
	void insertNode(int);
	void multiply(int);
	void out();
    void countZero();
    
};

list::list(){
		rear = NULL;
		top = NULL;
}

void list::insertNode(int a){
	Node *ptr =  new Node;
	ptr->info = a;
	ptr->prev = NULL;
	ptr->next = NULL;
	if(rear == NULL && top==NULL){
		rear = ptr;
		top = ptr;
	}else{
		ptr->next = top;
		top->prev = ptr;
		top = ptr;
	}
}

void list::multiply(int a){
	//cout << "NEW MULTIPLY\n";
	Node *ptr = rear;
	int carry = 0;
	int k;
	while(ptr!=NULL){
      //  cout << "CURRENT NUMBER  ";
		//out();
		//cout << "\tCARRY = "<< carry << endl;
		k = ptr->info*a;
		k+=carry;
		ptr->info = k%10;
		carry = k/10;
		ptr = ptr->prev;
	}
	if(carry!=0){
		insertNode(carry%10);
		carry/=10;
	}
}

void list::out(){
	Node* ptr = top;
	while(ptr!=NULL){
		1cout << ptr->info;
		ptr = ptr->next;
	}
}

void list::countZero(){
    int con = 0;
    Node *ptr = rear;
    while(ptr->info == 0){
        con++;
        ptr = ptr->prev;
    }
    cout << con << endl;

}int main(){
	int t;
	cin  >> t;
	while(t--){
	list obj;
	obj.insertNode(1);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i){
		obj.multiply(i);
	}
	obj.countZero();
	}
	return 0;
}
