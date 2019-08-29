#include<stdio.h>
int length = 0;
int arr[1000];
void min_heapify(int arr[], int i, int N){
    int left = 2*i;
    int right = 2*i+1;
    int smallest;
    if(left <= N && arr[left] < arr[i]){
        smallest = left;
    }else{
        left = i;
    }
    if(right <= N && arr[right] < arr[smallest]){
        smallest = right;
    }
    if(smallest != i){
        int temp = arr[smallest];
        arr[smallest] = arr[i];
        arr[i] = temp;
        min_heapify(arr,smallest,N);
    }
}

int top(int arr[]){
    return arr[1];
}

void pop(int arr[]){
    arr[1] = arr[length];
    length--;
    if(length >= 2)min_heapify(arr,1,length);
}


void insert(int arr[], int val){
    length++;
    arr[length] = val;
    int i = length;
    while(i/2 > 0 && arr[i/2] > arr[i]){
        int temp = arr[i];
        arr[i] = arr[i/2];
        arr[i/2] = temp;
        i/=2;
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        length = 0;
        scanf("%d",&n);
        int ans = 0;
        while(n--){
            int a,b;
            // printf("ENTER TWO NUMBERS: ");
            scanf("%d%d",&a,&b);
            while(length > 0 && arr[1] <= a){
                pop(arr);
            }
            insert(arr,b);
            if(ans < length){
                ans = length;
            }
        }
        printf("%d\n",length);
    }
}