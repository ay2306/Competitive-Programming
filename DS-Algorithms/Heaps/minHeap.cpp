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
    void build_minheap();
    void min_heapify(int);
    void display();
};

void heap::build_minheap(){
    for(int i = n/2; i >= 1; i--){
        min_heapify(i);
    }
}

void heap::min_heapify(int i){
    int left = 2*i;
    int right = left+1;
    int minimum;
    if(left <= n && arr[i] > arr[left]){
        minimum = left;
    }else{
        minimum = i;
    }
    if(right <= n && arr[minimum] > arr[right]){
        minimum = right;
    }
    if(minimum != i){
        swap(arr[i],arr[minimum]);
        min_heapify(minimum);
    }
}

void heap::display(){
    for(int i = 1; i <= n; ++i)cout << arr[i] << " ";
    cout << endl;
}

int main(){
    int arr[] = {0,4,4,5,7,1,8,5};
    int n = sizeof(arr)/sizeof(arr[1]);
    heap h(arr,n-1);
    h.build_minheap();
    h.display();
    return 0;
}