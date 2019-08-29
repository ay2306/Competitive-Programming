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
    void max_heapify(int);
    void display();
};

void heap::build_maxheap(){
    for(int i = n/2; i >= 1; i--){
        max_heapify(i);
    }
}

void heap::max_heapify(int i){
    int left = 2*i;
    int right = 2*i + 1;
    int largest;
    if(left<=n && arr[left]>arr[i]){
        largest = left;
    }else{
        largest = i;
    }
    if(right<=n && arr[right]>arr[largest]){
        largest = right;
    }
    if(largest != i){
        swap(arr[i],arr[largest]);
        max_heapify(largest);
    }
}

void heap::display(){
    for(int i = 1; i <= n; ++i)cout << arr[i] << " ";
    cout << endl;
}

int main(){
    int arr[] = {0,1,4,3,7,8,9,10};
    int n = 7;
    heap h(arr,n);
    h.build_maxheap();
    h.display();
    return 0;
}