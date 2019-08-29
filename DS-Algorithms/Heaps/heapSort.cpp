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

class heap{
    int *arr;
    int n;
public:
    heap(int *arr, int n){
        this->arr = arr;
        this->n = n;
    }    
    void build_maxheap();
    void max_heapify(int i, int n);
    void heap_sort();
    void display();
};

void heap::build_maxheap(){
    for(int i = n/2; i >=1; i--){
        max_heapify(i,this->n);
    }
}

void heap::max_heapify(int i, int n){
    int left = 2*i;
    int right = 2*i + 1;
    int largest;
    if(left <= n && arr[i] < arr[left]){
        largest = left;
    }else{
        largest = i;
    }
    if(right <= n && arr[largest] < arr[right]){
        largest = right;
    }
    if(largest != i){
        swap(arr[i],arr[largest]);
        max_heapify(largest,n);
    }
}

void heap::heap_sort(){
    int heap_size = this->n;
    build_maxheap();
    for(int i = heap_size; i >= 2; i--){
        swap(arr[1],arr[i]);
        heap_size--;
        max_heapify(1,heap_size);
    }
}

void heap::display(){
    for(int i = 1; i <= n; ++i)cout << arr[i] << " ";
    cout << endl;
}


int main(){
    int arr[] = {0,10,9,8,7,11,6,5,4,3,2,1};
    int n = sizeof(arr)/sizeof(arr[1]);
    heap h(arr, n-1);
    h.heap_sort();
    h.display();
}