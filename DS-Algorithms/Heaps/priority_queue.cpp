#include <bits/stdc++.h>
#define ull unsigned long long int
#define ll long long int
#define P pair
#define L list
#define V vector
#define S set
#define MS multiset
#define M map
#define mp make_pair
#define MM multimap
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
using namespace std;

class p_queue{
    int *arr;
    int n;
    int length;
public:
    p_queue(int*, int);
    int maximum();
    int extract_maximum();
    void increase_value(int i, int val);
    void insert_value(int);
    void max_heapify(int);
    void display();
};

p_queue::p_queue(int *arr, int n){
    this->arr = arr;
    this->n = n;
    length = n;
}

int p_queue::maximum(){
    return arr[1];
}

int p_queue::extract_maximum(){
    if(length == 0){
        cout << "QUEUE OVERFLOW\n";
        return INT_MIN;
    }
    int max = arr[1];
    arr[1] = arr[length];
    length--;
    max_heapify(1);
    return max;
}

void p_queue::increase_value(int i, int value){
    if(value < arr[i]){
        cout << "INDEX VALUE DECREASING ERROR\n";
        return ;
    }
    arr[i] = value;
    while(i > 1 && arr[i/2] < arr[i]){
        swap(arr[i/2],arr[i]);
        i/=2;
    }
}

void p_queue::insert_value(int value){
    length++;
    arr[length] = INT_MIN;
    increase_value(length,value);
}

void p_queue::max_heapify(int i){
    int left,right,largest;
    left = 2*i;
    right = 2*i + 1;
    if(left <= length && arr[left]>arr[i])largest=left;
    else largest = i;
    if(right <= length && arr[right] > arr[largest])largest = right;
    if(largest != i){
        swap(arr[i],arr[largest]);
        max_heapify(largest);
    }
}

void p_queue::display(){
    for(int i = 1; i <= length; ++i)cout << arr[i] << " ";
    cout << endl;
}

int main(){
    int arr[1000] = {0};
    int b,c;
    p_queue p(arr,0);
    bool lalala = true;
    while(lalala){
        cout << "1. Enter Element";
        cout << "\n2.Extract maximum";
        cout << "\n3.Check maximum";
        cout << "\n4.Increase element";
        cout << "\n5.Display list";
        cout << "\n6.Clear Screen";
        cout << "\n7.Exit";
        cout << "\nEnter Choice: ";
        int a;
        cin >> a;
        switch(a){
            case 1: cout << "ENTER A VALUE: "; cin >> b;p.insert_value(b);break;
            case 2: cout << "MAXIMUM OF LIST : "<< p.extract_maximum() << endl;break;
            case 3: cout << "MAXIMUM OF LIST : "<< p.maximum() << endl;break;
            case 4: cout << "ENTER A VALUE AND INDEX: "; cin >> b >> c;p.increase_value(c,b);break;
            case 5: p.display();break;
            case 6: system("CLS");break;
            case 7: lalala = false;break;
        }
    }
return 0;
}